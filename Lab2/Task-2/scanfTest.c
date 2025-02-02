#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main() {
    int a, b;
    
    // Ask the user to type a number
    printf("Type a number: \n");

    // Get and save the number the user types
    scanf("%d", &a);

    printf("Type another number: \n");
    scanf("%d", &b);
    
    // Loop to print the rectangle
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            // Print '*' for the border, '.' for the inner part
            if (i == 0 || i == a - 1 || j == 0 || j == b - 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n"); // Move to the next line
    }
    
    return 0;
}
