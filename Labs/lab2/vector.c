#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *vector_create(void) {
  Vector *vector = malloc(sizeof(Vector));
  if (vector == NULL) {
    fprintf(stderr, "Error: Unable to allocate memory for vector.\n");
    return NULL;
  }
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;
  vector->data = malloc(sizeof(double) * vector->capacity);
  if (vector->data == NULL) {
    fprintf(stderr, "Error: Unable to allocate memory for data.\n");
    free(vector);
    return NULL;
  }
  return vector;
}

void vector_push(Vector *vector, double element) {
  if (vector == NULL) {
    fprintf(stderr, "Error: Invalid passed in vector (nullptr).\n");
    return;
  }
  if (vector->size == vector->capacity) {
    int new_capacity = vector->capacity * 2;
    double *new_data = realloc(vector->data, sizeof(double) * new_capacity);
    if (new_data == NULL) {
      fprintf(stderr, "Error: Unable to allocate memory for data.\n");
      return;
    }
    vector->data = new_data;
    vector->capacity = new_capacity;
  }
  vector->data[vector->size++] = element;
}

double vector_get(const Vector *vector, int index) {
  if (vector == NULL) {
    fprintf(stderr, "Error: Invalid passed in vector (nullptr).\n");
    return 0;
  }
  if (index < 0 || index >= vector->size) {
    fprintf(stderr, "Error: Invalid index.\n");
    return 0;
  }
  return vector->data[index];
}

void vector_free(Vector *vector) {
  if (vector == NULL) {
    fprintf(stderr, "Error: Invalid passed in vector (nullptr).\n");
    return;
  }
  free(vector->data);
  free(vector);
}

void another_vector_free(Vector **vector) {
  if (vector == NULL) {
    fprintf(stderr, "Error: Invalid passed in vector (nullptr).\n");
    return;
  }
  vector_free(*vector);
  *vector = NULL;
}
