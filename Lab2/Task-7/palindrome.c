#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int is_palindrome(int number) {
    int original_number = number; // Store the original number
    int reversed_number = 0;
    int remainder;

    // Reverse the number
    while (number != 0) {
        remainder = number % 10; // Extract the last digit
        reversed_number = reversed_number * 10 + remainder; // Build the reversed number
        number /= 10; // Remove the last digit
    }

    // Check if the original number is equal to the reversed number
    if (original_number == reversed_number) {
        return 1; // Palindrome
    } else {
        return 0; // Not a palindrome
    }
}

int main() {
    int num;

    // Input from the user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Check and display the result
    if (is_palindrome(num)) {
        printf("It is a palindrome\n");
    } else {
        printf("It is not a palindrome\n");
    }

    return 0;
}