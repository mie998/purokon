#!bin/bash
filename=$1
g++ -Wall -std=c++14 $1
./a.out < ~/purokon/etc/input.txt
rm -f a.out
