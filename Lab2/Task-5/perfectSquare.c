#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a;
    printf("Enter the number: ");
    scanf("%lf", &a);

    double root = sqrt(a);
    if (root == (int)root) {
        printf("The number is a perfect square %lf", root);
    } else {
        printf("The number is not a perfect square %lf",root);
    }
}