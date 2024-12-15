#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void linearSearch(int arr[], int size, int element) {
    int found = 0; // Flag to track if the element is found
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element is present at index %d\n", i);
            found = 1;
            break; // Uncomment this if you want only the first match
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int ARRAY[] = {2, 4, 5, 7, 8, 9, 6, 3, 1, 55, 7, 98, 653, 4, 88, 7, 33, 5, 2};
    int size = sizeof(ARRAY) / sizeof(ARRAY[0]);
    int elementToFind;

    printf("Array is:\n");
    displayArray(ARRAY, size);
    printf("\n");

    printf("Enter the element to search: ");
    scanf("%d", &elementToFind);

    linearSearch(ARRAY, size, elementToFind);

    return 0;
}
