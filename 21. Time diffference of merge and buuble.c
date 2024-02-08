#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void merge(int arr1[], int left, int mid, int right){
    int size1 = mid-left+1;
    int size2 = right-mid;

    int T1[size1], T2[size2];
    for (int i = 0; i < size1; i++)
        T1[i] = arr1[left + i];
    for (int j = 0; j < size2; j++)
        T2[j] = arr1[mid + 1 + j];

    int i, j, k;
    i=0;
    j=0;
    k=left;

    while(i<size1 && j<size2){
        if(T1[i]<=T2[j]){
            arr1[k]=T1[i];
            i++;
        }
        else{
            arr1[k]=T2[j];
            j++;
        }
        k++;
    }

    while(i<size1){
        arr1[k]=T1[i];
        i++; k++;
    }
    while(j<size2){
        arr1[k]=T2[j];
        j++; k++;
    }
}

void mergesort(int arr1[], int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergesort(arr1, left, mid);
        mergesort(arr1, mid+1, right);
        merge(arr1, left, mid, right);
    }
}

void swap(int arr2[], int i, int j) {
    int temp = arr2[i];
    arr2[i] = arr2[j];
    arr2[j] = temp;
}

void optimizedBubbleSort(int arr2[], int size) {
    int i, j;
    int swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0;

        for (j = 0; j < size - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]) {
                swap(arr2, j, j + 1);
                swapped = 1;
            }
        }
    }
}

int main(){
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr1[size], arr2[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % 500;
        arr2[i] = arr1[i];
    }

    clock_t time1, time2;
    time1 = clock();
    mergesort(arr1, 0, size - 1);
    time2 = clock();
    double mergesort_Time = ((double)(time2 - time1)/CLOCKS_PER_SEC) ;
    printf("Merge Sort Code Run Time = %.10lf\n", mergesort_Time);

    /*printf("Sorted Array Using Merge Sort : ");
    for(int i=0; i<size; i++){
        printf("%d ", arr1[i]);
    }*/


    time1 = clock();
    optimizedBubbleSort(arr2, size);
    time2 = clock();
    double bubblesort_Time = ((double)(time2 - time1)/CLOCKS_PER_SEC) ;
    printf("\nBubble Sort Code Run Time = %.10lf\n", bubblesort_Time);

    /*printf("Sorted Array Using Bubble Sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }*/


    if(bubblesort_Time>mergesort_Time){
        printf("\nMerge Sort Is Faster Than Bubble Sort");
    }
    else{
       printf("\nBubble Sort Is Faster Than Merge Sort");
    }
    return 0;
}
