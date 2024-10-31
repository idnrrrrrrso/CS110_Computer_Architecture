#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>

#define PRINT_SIZE(type) printf("Size of " #type ": %lu\n", (unsigned long)sizeof(type))

int main() {
    PRINT_SIZE(char);
    PRINT_SIZE(short);
    PRINT_SIZE(short int);
    PRINT_SIZE(int);
    PRINT_SIZE(long int);
    PRINT_SIZE(unsigned int);
    PRINT_SIZE(void *);
    PRINT_SIZE(size_t);
    PRINT_SIZE(float);
    PRINT_SIZE(double);
    PRINT_SIZE(int8_t);
    PRINT_SIZE(int16_t);
    PRINT_SIZE(int32_t);
    PRINT_SIZE(int64_t);
    PRINT_SIZE(time_t);
    PRINT_SIZE(clock_t);
    PRINT_SIZE(struct tm);
    PRINT_SIZE(NULL);

    return 0;
}

/*
gcc -Wpedantic -Wall -Wextra -Werror -std=c89 -m64 -o task5_m64 task5.c
.\task5_m64 > output_m64
怎么好像需要额外下载mingw32? 要不先算了吧
gcc -Wpedantic -Wall -Wextra -Werror -std=c89 -m32 -o task5_m32 task5.c
.\task5_m32 > output_m32
*/
