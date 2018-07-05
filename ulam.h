#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// ppm max color
#define RGB_MAX 255

/*
 * write a boolean ulam spiral matrix to a ppm file
 * If a number is a prime, put black, otherwise white. 
 */
int write_ppm(const char * filename, bool ** matrix, int size);

/*
 * compute one square of the ulam spiral matrix
 * side - the size of the square
 * x,y - coords of where to start
 * n - the current number in the spiral to start counting from
 */
void fill_square(bool ** matrix, int side, int x, int y, int n);

bool ** alloc_matrix(int size);
void free_matrix(bool ** matrix, int size);

int is_prime(int n);