CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11 -fopenmp
EXECUTABLES = hello matmul dotp

all: $(EXECUTABLES)

% : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(EXECUTABLES)

.PHONY: all clean
