#!/bin/bash

gcc -Wpedantic -Wall -Wextra -Wvla -Werror -std=c11 -m32 ex5.c -o ex5_32bit.out
./ex5_32bit.out > output_32bit.txt

gcc -Wpedantic -Wall -Wextra -Wvla -Werror -std=c11 -m64 ex5.c -o ex5_64bit.out
./ex5_64bit.out > output_64bit.txt

echo "Compilation and execution completed."
