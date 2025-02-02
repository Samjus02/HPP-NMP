#include <stdio.h>
#include <stdlib.h>

void print_int_1(int x) {
    printf("Here is the number: %d\n", x);
}
void print_int_2(int x) {
    printf("Wow, %d is really an impressive number!\n", x);
}   

int main() {
    // Define a function pointer
    void (*foo)(int);

    // Point to print_int_1 and call it
    foo = print_int_1;
    foo(5);

    // Point to print_int_2 and call it
    foo = print_int_2;
    foo(10);
}