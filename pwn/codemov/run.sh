#!/bin/sh
HOST=${1:-localhost}
PORT=${2:-1337}
docker run -d --name codemov -p $PORT:1337 codemov