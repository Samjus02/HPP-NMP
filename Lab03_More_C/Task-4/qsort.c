#include <stdio.h>
#include <stdlib.h>


int CmpDouble(const void *p1, const void *p2) {
    const double *a = (const double *)p1; // Cast p1 to double pointer
    const double *b = (const double *)p2; // Cast p2 to double pointer

    if (*a < *b) {
        return 1; // Return positive for descending order
    } else if (*a > *b) {
        return -1; // Return negative for descending order
    } else {
        return 0; // Return zero if they are equal
    }
}

int main() {  
    double arrDouble[] = {9.3, -2.3, 1.2, -0.4, 2, 9.2, 1, 2.1, 0, -9.2};
    int arrlen=10;
    qsort (arrDouble, arrlen, sizeof(double), CmpDouble);
    printf("Sorted elements in array are: ");
    for (int i = 0; i<arrlen; i++) {
        printf(" %.2f", arrDouble[i]);
    }
    return 0;
}