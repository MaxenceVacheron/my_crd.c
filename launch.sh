#!/bin/bash

docker-compose -f /home/pi/my_crd.c/docker-compose.yml up -d
gotty --port 2783 -w docker exec -it my_crd ./Release/my_crd

