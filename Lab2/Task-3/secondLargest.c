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

    double secondLargest;
    if ((abs1 > abs2 && abs1 < abs3) || (abs1 < abs2 && abs1 > abs3)) {
        secondLargest = a;
    } else if ((abs2 > abs1 && abs2 < abs3) || (abs2 < abs1 && abs2 > abs3)) {
        secondLargest = b;
    } else {
        secondLargest = c;
    }

    printf("The number with the largest absolute value is: %.2lf\n", secondLargest);
    
    return 0;
}