#include <stdio.h>

int binary_search(int arr[], int size, int x) {
    int beg = 0, end = size - 1;
    int mid_checked = 0;

    while (beg <= end) {
        int midIndex = (beg + end) / 2;
        mid_checked++;

        if (arr[midIndex] == x) {
            printf("Number of times MidIndex was checked: %d\n", mid_checked);
            return midIndex;
        } else if (arr[midIndex] < x) {
            beg = midIndex + 1;
        } else {
            end = midIndex - 1;
        }
    }
    printf("Number of times MidIndex was checked: %d\n", mid_checked);
    return -1;
}

int linear_search(int arr[], int size, int x) {
    int found = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == x) {
            found = 1;
            break;
        }
    }
    if (i==size) {
        printf("Linear Search: Element %d not found\n", x);
    }
    return i;
}

int main() {
    int arr[] = {-222, -24, -22, -8, -2, 0, 2, 3, 9, 10, 11, 27, 30, 38, 43, 77, 99, 120};
    int size = sizeof(arr) / sizeof(arr[0]);

    int x = 7;

    int binary_result = binary_search(arr, size, x);
    int linear_result = linear_search(arr, size, x);

    if (binary_result != -1) {
        printf("Binary Search: Element %d found at index %d.\n", x, binary_result);
    } else {
        printf("Binary Search: Element %d not found.\n", x);
    }

    if (linear_result < size) {
        printf("Linear Search: Element %d found at index %d.\n", x, linear_result);
    }

    return 0;
}

