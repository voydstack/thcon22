#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buf[0x40];
    char choice;

    // Disables stdout buffering
    setvbuf(stdout, NULL, _IONBF, 0);
    
    do {
        printf("Please tell me more about stack buffer overflows: ");
        read(0, buf, 0x80);
        printf("Ok, I get it, \"%s\".\n", buf);
        printf("Are you done yet? (y/n) ");
        choice = getchar();
    } while (choice == 'n');

    printf("Thank you!\n");

    return 0;
}