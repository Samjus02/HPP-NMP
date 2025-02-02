#include <stdio.h>

int main() {
    // Using for loop
    printf("Using for loop:\n");
    for (int i = 100; i >= 0; i -= 4) {
        printf("%d ", i);
    }
    printf("\n");

    // Using while loop
    printf("Using while loop:\n");
    int i = 100;
    while (i >= 0) {
        printf("%d ", i);
        i -= 4;
    }
    printf("\n");

    // Using do...while loop
    printf("Using do...while loop:\n");
    i = 100;
    do {
        printf("%d ", i);
        i -= 4;
    } while (i >= 0);
    printf("\n");

    return 0;
}
