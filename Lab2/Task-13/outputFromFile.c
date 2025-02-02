#include <stdio.h>

int main() {
    FILE *file;
    char product[51]; // To store product name (max 50 characters + 1 for null terminator)
    double price;
    int numProducts, i;

    // Open the file
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the total number of products
    fscanf(file, "%d", &numProducts);

    // Print header
    printf("Product\tPrice\n");
    printf("---------------\n");

    // Read and display each product and its price
    for (i = 0; i < numProducts; i++) {
        fscanf(file, "%s %lf", product, &price);
        printf("%s\t%.2lf\n", product, price);
    }

    // Close the file
    fclose(file);

    return 0;
}
