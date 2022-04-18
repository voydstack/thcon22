# Coderunner 2049

## Seccomp rule hijacking

Title:
- Coderunner 2049

Category:
- pwn

Difficulty:
- Medium

Build docker image:
 - `cd docker && docker build -t coderunner2049 .`
 
Run container:
 - `./run.sh [HOSTNAME=localhost] [PORT=1337] `

Description:

> We've just released our futuristic, efficient and secure code runner, featuring next-gen sandboxing. Feel free to try it out!

Solver:
 - `cd solution && python3 exploit.py HOSTNAME PORT` (requires python3 / pwntools)

Attachments: [coderunner2049-dist.zip](coderunner2049-dist.zip)
