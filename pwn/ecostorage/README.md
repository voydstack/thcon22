# EcoStorage

## Environment hijacking

Title:
- EcoStorage

Category:
- pwn

Difficulty:
- Medium

Build docker image:
 - `cd docker && docker build -t ecostorage .`
 
Run container:
 - `./run.sh [HOSTNAME=localhost] [PORT=1337] `

Description:

> EcoStorage is a simple, fast and environment friendly storage software, it is also secure!

Solver:
 - `cd solution && python3 exploit.py HOSTNAME PORT` (requires python3 / pwntools)

Attachments: [ecostorage-dist.zip](ecostorage-dist.zip)
