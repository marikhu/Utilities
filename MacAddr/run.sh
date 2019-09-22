#!/bin/bash
set -e

gcc -g -O0 MacAddr.c -o MacAddr
./MacAddr enp2s0
