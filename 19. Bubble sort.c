#include <stdio.h>

// Function to swap two numbers
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to perform optimized bubble sort and return the number of swaps
int optimizedBubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    int swapCount = 0;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                swapped = 1;
                swapCount++;
            }
        }

        // If no two elements were swapped by the inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }

    return swapCount;
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform optimized bubble sort and get the number of swaps
    int swapCount = optimizedBubbleSort(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of swaps: %d\n", swapCount);

    return 0;
}

