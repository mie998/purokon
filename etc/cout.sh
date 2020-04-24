#!bin/bash
filename=$1
g++ -Wall -ggdb3 -fsanitize=undefined -D_GLIBCXX_DEBUG -std=c++17 $1
./a.out < ~/Work/purokon/etc/input.txt
rm -f a.out
