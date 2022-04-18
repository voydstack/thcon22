#!/bin/sh
HOST=${1:-localhost}
PORT=${2:-1337}
docker run -d --name stack101 -p $PORT:1337 stack101