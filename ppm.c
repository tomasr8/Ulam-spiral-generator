#include "ulam.h"

int write_ppm(const char * filename, bool ** matrix, int size) {
  // helper piece of memory, represents one row of the image
  unsigned char * row = malloc(3 * size * sizeof(unsigned char));
  if(row == NULL) {
    return -1;
  }

  FILE *fp;
  fp = fopen(filename, "wb");
  if (!fp) {
    return -1;
  }

  fprintf(fp, "P6\n");

  // image size
  fprintf(fp, "%d %d\n", size, size);

  // rgb component depth
  fprintf(fp, "%d\n", RGB_MAX);

  // pixel data
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      unsigned char color = RGB_MAX;

      // number is prime, make it black
      if(matrix[i][j] == 1) {
        color = 0;
      }

      row[3*j] = row[3*j+1] = row[3*j+2] = color;
    }
    fwrite(row, 3 * size * sizeof(unsigned char), 1, fp);
  }

  free(row);
  fclose(fp);
  return 0;
}