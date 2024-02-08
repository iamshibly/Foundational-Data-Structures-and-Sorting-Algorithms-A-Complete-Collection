#include <stdio.h>

// Binary search function
int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int mid_checks = 0;

    while (low <= high) {
        int mid = (high + low) / 2;
        mid_checks++;

        if (arr[mid] == x) {
            // Element found
            printf("Mid checks: %d\n", mid_checks);
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Element not found
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 7; // Element to search

    int binary_result = binary_search(arr, n, x);

    if (binary_result != -1) {
        printf("Binary Search: Element %d found at index %d.\n", x, binary_result);
    } else {
        printf("Binary Search: Element %d not found.\n", x);
    }

    return 0;
}

