/* doCirculant in C */
#include <stdio.h>
#define SIZE 4 /* size of array */

void doCirculant( int x[] ) {
  int y[ SIZE ][ SIZE ]; /* 2D array */

  /* create a circulant matrix */
  for( int k = 0; k < SIZE; k++ ) {
    y[0][k] = x[k]; /* copy array x to first row of array y */
  }

  for( int i = 0; i < SIZE - 1; i++ ) {
    int start = x[0]; /* take the first value of the 1D array aside */

    /* add and shift values in array */
    for( int j = 0; j < SIZE - 1; j++ ) {
      y[i + 1][j] = x[ j + 1 ]; /* copy the remaining part of the 1D array into a single row in the 2D array */
      x[j] = x[ j + 1 ]; /* shift values of the 1D array */
    }

    y[i + 1][SIZE - 1] = start; /* add the start to the end of array y[i][end] */
    x[SIZE - 1] = start; /* add start to the end of array x */
  }

  /* print circulant matrix generated */
  for( int l = 0; l < SIZE; l++ ) {
    for( int m = 0; m < SIZE; m++ ) {
      printf( "%d ", y[l][m] );
    }
    printf( "\n" );
  }
}

int main() {
  int z[ SIZE ]; /* input array */

  printf( "Enter 4 integers: " );
  scanf( "%d%d%d%d", &z[0], &z[1], &z[2], &z[3] );
  printf( "\n" );

  doCirculant( z );
  printf( "\n" );

  return 0;
}
