#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char product[51];
    double price;
    int numProducts, i;

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

    // Print header
    printf("Product\tPrice\n");
    printf("---------------\n");

    // Read and display each product and its price
    for (i = 0; i < numProducts; i++) {
        if (fscanf(file, "%s %lf", product, &price) == 2) {
            printf("%s\t%.2lf\n", product, price);
        } else {
            printf("Error reading product data on line %d.\n", i + 2);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
