#ifndef LAB_2_VECTOR_H
#define LAB_2_VECTOR_H

#define VECTOR_INITIAL_CAPACITY 10

typedef struct {
  double *data;
  int size;
  int capacity;
} Vector;

Vector *vector_create(void);

void vector_push(Vector *vector, double element);

double vector_get(const Vector *vector, int index);

void vector_free(Vector *vector);

void another_vector_free(Vector **vector);
#endif // LAB_2_VECTOR_H
