#!/bin/sh
HOST=${1:-localhost}
PORT=${2:-1337}
docker run -d --name ecostorage -p $PORT:1337 ecostorage
