/*
1   2   3   4   5
_______________________________________
 1 |   1   2   3   4   5
 2 |   2   4   6   8  10
 3 |   3   6   9  12  15
 4 |   4   8  12  16  20
 5 |   5  10  15  20  25
 */

#include <stdio.h>
#define ROWS 5
#define COLS 5

int main()
{
    int row, column, product[ROWS][COLS];
    int i, j;

    // Step 1: Print column headers
    printf("    ");
    for (j = 0; j < COLS; j++) {
        printf("%4d", j + 1); // Print numbers from 1 to COLS with 4 spaces of padding
    }
    printf("\n");
    printf("_______________________________________\n");

    // Step 2: Fill and print the multiplication table
    for (i = 0; i < ROWS; i++) {
        row = i + 1; // Convert 0-index to 1-index for row display
        printf("%2d |", row); // Print row header with 2 spaces of padding

        for (j = 0; j < COLS; j++) {
            column = j + 1; // Convert 0-index to 1-index for column calculation
            product[i][j] = row * column; // Store the product in the array
            printf("%4d", product[i][j]); // Print the product with 4 spaces of padding
        }
        printf("\n"); // Move to the next line after printing each row
    }

    return 0;
}

