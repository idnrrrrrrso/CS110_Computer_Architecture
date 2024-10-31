#!/bin/bash

source_file="your_source_file.c"

gcc -Wpedantic -Wall -Wextra -Wvla -Werror -std=c11 -m32 $source_file -o output_m32
gcc -Wpedantic -Wall -Wextra -Wvla -Werror -std=c11 -m64 $source_file -o output_m64

echo "Done."