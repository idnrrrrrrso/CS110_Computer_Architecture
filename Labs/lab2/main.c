#include "vector.h"
#include <stdio.h>

int main(void) {
  Vector *vector = vector_create();
  for (int i = 0; i < 100; ++i) {
    vector_push(vector, i * 10 / 7.0);
  }
  for (int i = 0; i < 100; ++i) {
    printf("%f\n", vector_get(vector, i));
  }
  vector_free(vector);
  return 0;
}
