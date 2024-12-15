#include<stdio.h>
#include<stdlib.h>
# define MAX 1000

// Function to perform Binary Search
int BinarySearch(int Array[], int size, int element) {
    int low = 0;              // Starting index of the array
    int high = size - 1;      // Last index of the array
    int mid = 0;              // Middle index

    // Binary search loop: keep searching while there are elements to examine
    while (low <= high) {
        mid = (high + low) / 2; // Calculate the middle index
        if (Array[mid] == element) {
            return mid;         // Element found, return its index
        } else if (Array[mid] < element) {
            low = mid + 1;      // Move the search to the right half
        } else {
            high = mid - 1;     // Move the search to the left half
        }
    }
    return -1;                 // Element not found, return -1
}

// Function to display the array elements
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Print each element of the array
    }
    printf("\n");
}

int main() {
    // Initialize a sorted array
    int Array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43};
    int size = sizeof(Array) / sizeof(Array[0]); // Calculate the size of the array
    int Element_To_Search = 39;                 // Element to search for

    printf("Array size is: %d\n", size);         // Display the size of the array
    printf("Array is: ");
    display(Array, size);                        // Display the elements of the array

    // Perform Binary Search
    int result = BinarySearch(Array, size, Element_To_Search);
    if (result != -1) {                          // Check if the element was found
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;                                    // Exit the program
}
/*OUTPUT EXAMPLE

Array size is:22
Array is:1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43
Element found at index:19

*/