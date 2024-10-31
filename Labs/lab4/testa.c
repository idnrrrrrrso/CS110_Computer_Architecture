#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef union {
  uint32_t number;
  uint8_t bytes[4];
  data aaa;
} DataType;

typedef struct {
  unsigned int x : 7;
  unsigned int y : 5;
  unsigned int z : 20;
} data;

int main() {
  unsigned long x = sizeof(DataType);
  unsigned long y = sizeof(data);
  printf("%lu", x);
}