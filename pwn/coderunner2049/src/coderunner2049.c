#include <linux/seccomp.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/prctl.h>

#define CODE_SIZE 0x80
#define SHELLCODE_SIZE 0x1000

unsigned char filter[] = {32,0,0,0,4,0,0,0,21,0,0,7,62,0,0,192,32,0,0,0,0,0,0,0,53,0,5,0,0,0,0,64,21,0,5,0,1,0,0,0,21,0,4,0,0,0,0,0,21,0,3,0,60,0,0,0,21,0,2,0,231,0,0,0,21,0,1,0,11,0,0,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0,255,127};

unsigned char code[CODE_SIZE];

char *shellcode;

static void install_seccomp() {
    struct prog {
        unsigned short len;
        unsigned char *filter;
    } rule = {
        .len = sizeof(filter) >> 3,
        .filter = filter
    };

    printf("Applying our next-gen sandbox\n");

    if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0) < 0) {
        perror("prctl(PR_SET_NO_NEW_PRIVS)");
        exit(2);
    }

    if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &rule) < 0) {
        perror("prctl(PR_SET_SECCOMP)");
        exit(2);
    }
}

size_t read_code(char *code) {
    char i = 0;
    for (char i = 0; i < CODE_SIZE; i++) {
        code[i] = fgetc(stdin);
        if (code[i] == '\xc3') break;
    }
}

void handle_fault(int signum) {
    register unsigned long rax asm("rax");
    register unsigned long rbx asm("rbx");
    register unsigned long rcx asm("rcx");
    register unsigned long rdx asm("rdx");
    register unsigned long rsp asm("rsp");
    register unsigned long rsi asm("rsi");
    register unsigned long rdi asm("rdi");
    register unsigned long r8 asm("r8");
    register unsigned long r9 asm("r9");
    register unsigned long r10 asm("r10");
    register unsigned long r11 asm("r11");
    register unsigned long r12 asm("r12");
    register unsigned long r13 asm("r13");
    register unsigned long r14 asm("r14");
    register unsigned long r15 asm("r15");

    printf("Caught signal \"%s\" (%d)\n", strsignal(signum), signum);
    printf("Registers state: \n");
    printf("--------------------------------\n");
    printf("rax\t: 0x%lx\n", rax);
    printf("rbx\t: 0x%lx\n", rbx);
    printf("rcx\t: 0x%lx\n", rcx);
    printf("rdx\t: 0x%lx\n", rdx);
    printf("rsp\t: 0x%lx\n", rsp);
    printf("rsi\t: 0x%lx\n", rsi);
    printf("rdi\t: 0x%lx\n", rdi);
    printf("r8\t: 0x%lx\n", r8);
    printf("r9\t: 0x%lx\n", r9);
    printf("r10\t: 0x%lx\n", r10);
    printf("r11\t: 0x%lx\n", r11);
    printf("r12\t: 0x%lx\n", r12);
    printf("r13\t: 0x%lx\n", r13);
    printf("r14\t: 0x%lx\n", r14);
    printf("r15\t: 0x%lx\n", r15);
    printf("--------------------------------\n");
    munmap(shellcode, SHELLCODE_SIZE);
    _Exit(signum);
}

void prepare_shellcode() {
    size_t code_size;

    shellcode = mmap(NULL, SHELLCODE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);

    if (!shellcode) {
        perror("mmap");
        exit(1);
    }

    printf("Please enter your code (%d bytes maximum): ", CODE_SIZE);
    code_size = read_code(code);

    memcpy(shellcode, code, code_size);
}

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);

    signal(SIGSEGV, handle_fault);
    signal(SIGILL, handle_fault);
    signal(SIGABRT, handle_fault);
    signal(SIGTRAP, handle_fault);
}

int main(int argc, char *argv[]) {

    init();

    prepare_shellcode();

    install_seccomp();

    printf("Executing your code...\n");

    ((void (*)()) shellcode)();

    printf("Your code has been successfully executed!\n");

    munmap(shellcode, SHELLCODE_SIZE);

    _Exit(0);
}