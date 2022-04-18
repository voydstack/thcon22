#!/bin/sh
HOST=${1:-localhost}
PORT=${2:-1337}
docker run -d --name coderunner2049 -p $PORT:1337 coderunner2049
