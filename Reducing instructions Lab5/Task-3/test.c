#include <stdio.h>
#include <float.h> // For DBL_MAX and DBL_MIN
#include <math.h>

int main() {
    double num = 1.0;
    int iteration = 0;

    printf("Increasing the number by a factor of 100:\n");
    // Increasing the value
    while (num != INFINITY) {
        printf("Iteration %d: %e\n", iteration, num);
        num *= 100.0;
        iteration++;
        if (num == INFINITY) {
            printf("Reached positive infinity at iteration %d\n", iteration);
        }
    }

    // Reset for decreasing test
    num = 1.0;
    iteration = 0;

    printf("\nDecreasing the number by a factor of 100:\n");
    // Decreasing the value
    while (num != 0.0) {
        printf("Iteration %d: %e\n", iteration, num);
        num /= 100.0;
        iteration++;
        if (num == 0.0) {
            printf("Reached zero at iteration %d\n", iteration);
        }
    }

    return 0;
}
