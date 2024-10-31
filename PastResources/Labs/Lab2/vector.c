/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
/* Reasons that the function is bad:
   Although data is created on the heap using malloc, 
   the vector itself 'v' is created on the stack.
   Once the function exits, the memory allocated for v will be deallocated, 
   and the returned pointer will become invalid, 
   leading to undefined behavior when accessing its memory.
   Besides, the allocated memory 'retval->data' has no way to be freed, leading to memory leak problems.
*/
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Another suboptimal way of creating a vector */
/* Reasons that the function is bad:
   The return value is a whole `struct vector_t` rather than a pointer pointing to the struct, this means when returning the vector, a copy of the vector is required. That's unnecessary. (But the consumption is not that large? Since it's just a size_t and a pointer. But conventionally we still don't prefer to return a copy of a data structure. Is that right?)
*/
vector_t also_bad_vector_new() {
    /* Create the vector */
    vector_t v;

    /* Initialize attributes */
    v.size = 1;
    v.data = malloc(sizeof(int));
    if (v.data == NULL) {
        allocation_failed();
    }
    v.data[0] = 0;
    return v;
}

/* Create a new vector with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;

    /* First, we need to allocate memory on the heap for the struct */
    retval = malloc(sizeof(vector_t));

    /* Check our return value to make sure we got memory */
    if (retval == NULL) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    retval->size = 1;
    retval->data = malloc(sizeof(int));

    /* Check the data attribute of our vector to make sure we got memory */
    if (retval->data == NULL) {
        free(retval);				//Why is this line necessary?
        allocation_failed();
    }

    /* Complete the initialization by setting the single component to zero */
    *(retval->data) = 0;

    /* and return... */
    return retval;
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if (v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    if (loc < v->size) {
        return *(v->data + loc);
    } else {
        return 0;
    }
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    /* free(NULL) does nothing. */
    free(v->data);  
    free(v);
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */

    /* YOUR SOLUTION HERE */

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if (v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, allocate extra memory. */
    if (loc >= v->size) {
        int *new_data = realloc(v->data, sizeof(int) * (loc + 1));
        if (new_data == NULL) {
            allocation_failed();
        }

        /* Initialize the newly allocated memory to 0 */
        for (size_t i = v->size; i != loc; ++i){
            *(new_data + i) = 0;
        }

        /* Update the vector's data pointer and size */
        v->data = new_data;
        v->size = loc + 1;
    } 
    
    /* Then set the location with value. */
    *(v->data + loc) = value;
}