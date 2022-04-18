# Stack 101

## Basic stack buffer overflow (bypass PIE + Canary + ret2libc)

Title:
- Stack 101

Category:
- pwn

Difficulty:
- Easy

Build docker image:
 - `cd docker && docker build -t stack101 .`
 
Run container:
 - `./run.sh [HOSTNAME=localhost] [PORT=1337] `

Description:

> What can you tell me about stack buffer overflows ?

Solver:
 - `cd solution && python3 exploit.py HOSTNAME PORT` (requires python3 / pwntools)

Attachments: [stack101-dist.zip](stack101-dist.zip)
