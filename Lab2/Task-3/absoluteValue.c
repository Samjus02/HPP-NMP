#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {
    double a, b, c;
    printf("Type a number: \n");
    scanf("%lf", &a); // lf because we are reading a double

    printf("Type a number: \n");
    scanf("%lf", &b);

    printf("Type a number: \n");
    scanf("%lf", &c);

    double abs1 = fabs(a);
    double abs2 = fabs(b);
    double abs3 = fabs(c);

    double largest = a;
    if (abs2 > largest) {
        largest = b;
    }
    if (abs3 > largest) {
        largest = c;
    }

    printf("The number with the largest absolute value is: %.2lf\n", largest);
    
    return 0;
}