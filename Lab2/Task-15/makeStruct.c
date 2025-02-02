#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    double price;
} product_t;

int main(int argc, char *argv[]) {
    FILE *file;
    int numProducts, i;
    product_t *products;

    // Check if the file name is provided
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Open the file provided as the command-line argument
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Read the total number of products
    if (fscanf(file, "%d", &numProducts) != 1) {
        printf("Error: Failed to read the number of products.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the array of products
    products = (product_t *)malloc(numProducts * sizeof(product_t));
    if (products == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read and store each product and its price
    for (i = 0; i < numProducts; i++) {
        if (fscanf(file, "%s %lf", products[i].name, &products[i].price) != 2) {
            printf("Error reading product data on line %d.\n", i + 2);
            free(products);
            fclose(file);
            return 1;
        }
    }

    // Print header
    printf("Product\tPrice\n");
    printf("---------------\n");

    // Display all the products
    for (i = 0; i < numProducts; i++) {
        printf("%s\t%.2lf\n", products[i].name, products[i].price);
    }

    // Free allocated memory and close the file
    free(products);
    fclose(file);

    return 0;
}
