#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = NULL;
    int size = 0, capacity = 10;
    int num, sum = 0;

    // Allocate initial memory for 10 numbers
    numbers = (int *)malloc(capacity * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter numbers (non-integer to stop): ");

    // Read integers until a non-integer is encountered
    while (scanf("%d", &num) == 1) {
        // Check if more memory is needed
        if (size == capacity) {
            capacity += 10;
            numbers = (int *)realloc(numbers, capacity * sizeof(int));
            if (numbers == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                return 1;
            }
        }
        // Store the number and update sum
        numbers[size++] = num;
        sum += num;
    }

    // Print the entered numbers
    printf("Numbers entered: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Print the sum of numbers
    printf("Sum: %d\n", sum);

    // Free the allocated memory
    free(numbers);

    return 0;
}
