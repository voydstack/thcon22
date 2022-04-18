FROM ubuntu:20.04

RUN apt-get update && apt-get install -y socat

RUN useradd -m -s /bin/bash user

USER user

COPY ecostorage /home/user/
COPY run.sh /home/user
COPY flag.txt /home/user/

CMD cd /home/user && socat TCP-LISTEN:1337,reuseaddr,fork EXEC:/home/user/run.sh
