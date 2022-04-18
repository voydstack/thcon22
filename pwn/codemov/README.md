# Code: mov

## mov-only shellcode

Title:
- Code: mov

Category:
- pwn

Difficulty:
- Medium

Build docker image:
 - `cd docker && docker build -t codemov .`
 
Run container:
 - `./run.sh [HOSTNAME=localhost] [PORT=1337] `

Description:

> I heard `mov` is turing complete, can you give me a shell ?

Solver:
 - `nc -lvp REV_PORT` 
 - `nc HOSTNAME PORT < solution/codemov-final.asm` (in another terminal)

Attachments: [codemov-dist.zip](codemov-dist.zip)
