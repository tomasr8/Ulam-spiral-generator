#include "ulam.h"

int main(int argc, char ** argv) {
  if(argc != 3) {
    printf("Need a size argument and an output argument\n");
    return 1;
  }

  int size = strtol(argv[1], NULL, 10);
  char * output_img = argv[2];

  if(size % 2 == 0) {
    printf("SIZE has to be even\n");
    return 1;
  }

  bool ** matrix = alloc_matrix(size);
  if(matrix == NULL) {
    printf("Failed to alloc matrix\n");
    return 1;
  }

  int n = 2; // starting number, 1 is not a prime
  int side = 3; // starting side size of the smallest square
  int x = (size - 1)/2 + 1; // starting coords
  int y = (size - 1)/2;

  for(int i = 0; i < (size - 1)/2; i++) {
    fill_square(matrix, side, x, y, n);
    n += 4*side - 4;
    side += 2;
    x += 1;
    y += 1;
  }

  int status = write_ppm(output_img, matrix, size);

  if(status < 0) {
    printf("Failed to write to file\n");
    free_matrix(matrix, size);
    return 1;
  }

  free_matrix(matrix, size);
  return 0;
}

void fill_square(bool ** matrix, int side, int x, int y, int n) {
  // fill right side
  for(int i = 0; i < side - 1; i++) {
    matrix[y - i][x] = is_prime(n++);
  }

  // fill top side
  for(int i = 1; i < side; i++) {
    matrix[y - side + 2][x - i] = is_prime(n++);
  }

  // fill left side
  for(int i = 1; i < side; i++) {
    matrix[y - side + 2 + i][x - side + 1] = is_prime(n++);
  }

  // fill bottom side
  for(int i = 1; i < side; i++) {
    matrix[y + 1][x - side + 1 + i] = is_prime(n++);
  }
}

bool ** alloc_matrix(int size) {
  bool ** matrix = malloc(size * sizeof(bool *));
  if(matrix == NULL) {
    return NULL;
  }

  for(int i = 0; i < size; i++) {
    matrix[i] = malloc(size * sizeof(bool));
    if(matrix[i] == NULL) {
      for(int j = 0; j < i; j++) {
        free(matrix[i]);
      }
      return NULL;
    }
  }

  return matrix;
}

void free_matrix(bool ** matrix, int size) {
  for(int i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);
}
