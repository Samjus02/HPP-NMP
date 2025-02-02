#include <stdio.h>

#define MAX_SIZE 10 // Define the maximum size of the matrix

int main() {
    int n, i, j;
    int matrix[MAX_SIZE][MAX_SIZE];

    // Input the size of the matrix (n x n)
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: Maximum allowed size is %d.\n", MAX_SIZE);
        return 1;
    }

    // Fill the matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0; // Diagonal elements
            } else if (i < j) {
                matrix[i][j] = 1; // Upper triangular elements
            } else {
                matrix[i][j] = -1; // Lower triangular elements
            }
        }
    }

    // Print the matrix
    printf("Generated matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
