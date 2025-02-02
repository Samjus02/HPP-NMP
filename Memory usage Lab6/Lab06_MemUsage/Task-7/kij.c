#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define BLOCK_SIZE 32 // Fixed block size

static double get_wall_seconds() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  double seconds = tv.tv_sec + (double)tv.tv_usec / 1000000;
  return seconds;
}

int rand_int(int N) {
  int val = -1;
  while (val < 0 || val >= N) {
    val = (int)(N * (double)rand() / RAND_MAX);
  }
  return val;
}

void allocate_mem(int*** arr, int n) {
  int i;
  *arr = (int**)malloc(n * sizeof(int*));
  for (i = 0; i < n; i++)
    (*arr)[i] = (int*)malloc(n * sizeof(int));
}

void free_mem(int** arr, int n) {
  int i;
  for (i = 0; i < n; i++)
    free(arr[i]);
  free(arr);
}

/* kij with cache blocking */
void mul_kij(int n, int **a, int **b, int **c) {
  int i, j, k, ii, jj, kk;
  for (kk = 0; kk < n; kk += BLOCK_SIZE) {
    for (ii = 0; ii < n; ii += BLOCK_SIZE) {
      for (jj = 0; jj < n; jj += BLOCK_SIZE) {
        for (k = kk; k < kk + BLOCK_SIZE && k < n; k++) {
          for (i = ii; i < ii + BLOCK_SIZE && i < n; i++) {
            int x = a[i][k];
            for (j = jj; j < jj + BLOCK_SIZE && j < n; j++) {
              c[i][j] += x * b[k][j];
            }
          }
        }
      }
    }
  }
}

int main() {
  int n;
  
  // Get matrix size from user
  printf("Enter matrix size (n): ");
  scanf("%d", &n);

  int **A, **B, **C;
  allocate_mem(&A, n);
  allocate_mem(&B, n);
  allocate_mem(&C, n);

  // Initialize matrices A and B with random values
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = rand_int(100);
      B[i][j] = rand_int(100);
      C[i][j] = 0;
    }
  }

  double start = get_wall_seconds();
  mul_kij(n, A, B, C);
  double end = get_wall_seconds();

  printf("Time: %f seconds\n", end - start);

  free_mem(A, n);
  free_mem(B, n);
  free_mem(C, n);

  return 0;
}