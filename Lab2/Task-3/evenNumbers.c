#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main() {
    int a, b;
    printf("Type a number: \n");
    scanf("%d", &a);

    printf("Type a number: \n");
    scanf("%d", &b);

    if (a % 2 == 0 && b % 2 == 0) {
        printf("Both numbers are even with sum: %d", a + b);
    }
    else {
        printf("At least one of the numbers is odd, giving the product: %d", a * b);
    }

    return 0;
}