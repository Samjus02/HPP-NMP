#include <stdio.h>

int main() {
    // Declare and initialize variables
    double myDouble = 3.14159;
    int myInt = 42;
    char myChar = 'A';

    // Output the value, address, and memory size of each variable
    printf("Double:\n");
    printf("Value: %f\n", myDouble);
    printf("Address: %p\n", (void*)&myDouble);
    printf("Size: %zu bytes\n\n", sizeof(myDouble));

    printf("Integer:\n");
    printf("Value: %d\n", myInt);
    printf("Address: %p\n", (void*)&myInt);
    printf("Size: %zu bytes\n\n", sizeof(myInt));

    printf("Character:\n");
    printf("Value: %c\n", myChar);
    printf("Address: %p\n", (void*)&myChar);
    printf("Size: %zu bytes\n", sizeof(myChar));

    return 0;
}
