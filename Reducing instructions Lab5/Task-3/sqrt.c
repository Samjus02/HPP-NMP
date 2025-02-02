#include <stdio.h>

int main() {
    double epsilon = 1.0; // Start with epsilon = 1.0
    double result;
    int iteration = 0;

    printf("Iteration\tEpsilon\t\tResult (1 + Epsilon)\n");
    printf("---------------------------------------------------\n");

    while (1) {
        result = 1.0 + epsilon; // Add epsilon to 1.0
        printf("%d\t\t%.5e\t%.5e\n", iteration, epsilon, result);

        // Break the loop if the result is no longer distinguishable from 1
        if (result == 1.0) {
            break;
        }

        epsilon *= 0.5; // Halve epsilon
        iteration++;
    }

    printf("\nSmallest epsilon that makes 1 + epsilon > 1: %.5e\n", epsilon * 2);
    printf("Smallest epsilon that makes 1 + epsilon == 1: %.5e\n", epsilon);

    return 0;
}
