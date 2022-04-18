FROM ubuntu:20.04

RUN apt-get update && apt-get install -y python3 python3-pip socat

RUN python3 -m pip install pwntools

RUN useradd -m -s /bin/bash user

USER user

COPY codemov.py /home/user/
COPY executor /home/user/
COPY flag.txt /home/user/

CMD cd /home/user && socat TCP-LISTEN:1337,reuseaddr,fork EXEC:/home/user/codemov.py
