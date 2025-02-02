#include <stdio.h>
#include <time.h>

static inline int inlineFunction(int x) {
    return x * x;
}

int regularFunction(int x) {
    return x * x;
}

int main(int argc, const char** argv) {
    const int iterations = 100000000; // A large number of iterations
    int result = 0;
    clock_t start, end;

    // Measure time for the inline function
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result += inlineFunction(i);
    }
    end = clock();
    double inlineTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Inline function time: %f seconds\n", inlineTime);

    // Measure time for the regular function
    result = 0; // Reset result
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result += regularFunction(i);
    }
    end = clock();
    double regularTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Regular function time: %f seconds\n", regularTime);

    return 0;
}
