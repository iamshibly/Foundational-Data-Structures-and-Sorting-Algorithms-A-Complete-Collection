#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    int found = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            found = 1;
            break;
        }
    }
    if (i==n) {
        printf("Element not found\n");
    }
    return i; // Return the index if the element is found, n if not found
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 18, 25};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int x = 22; // Element to search



    // Print at which index the element was found (if found)
    // Note: linear_result is not really needed here, you can use the return value directly

    int linear_result = linear_search(arr, n, x);

    // Print at which index the element was found (if found)
    if (linear_result < n) {
        printf("Linear Search: Element %d found at index %d.\n", x, linear_result);
    }


    return 0;
}

