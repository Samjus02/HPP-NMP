#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the original array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Allocate memory for the new array
    int *new_arr = NULL;
    int new_size = 0;

    for (int i = 0; i < n; i++) {
        if (!is_prime(arr[i])) {
            // Reallocate memory for the new array
            new_arr = (int *)realloc(new_arr, (new_size + 1) * sizeof(int));
            if (new_arr == NULL) {
                printf("Memory reallocation failed!\n");
                free(arr);
                return 1;
            }
            new_arr[new_size] = arr[i];
            new_size++;
        }
    }

    // Output the new array and its size
    printf("New array without primes:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\nSize of the new array: %d\n", new_size);

    // Free allocated memory
    free(arr);
    free(new_arr);

    return 0;
}
