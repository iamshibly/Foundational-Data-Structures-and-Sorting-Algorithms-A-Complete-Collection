#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
    int size1 = mid-left+1;
    int size2 = right-mid;

    int T1[size1], T2[size2];
    for (int i = 0; i < size1; i++)
        T1[i] = arr[left + i];
    for (int j = 0; j < size2; j++)
        T2[j] = arr[mid + 1 + j];

    int i, j, k;
    i=0;
    j=0;
    k=left;

    while(i<size1 && j<size2){
        if(T1[i]<=T2[j]){
            arr[k]=T1[i];
            i++;
        }
        else{
            arr[k]=T2[j];
            j++;
        }
        k++;
    }

    while(i<size1){
        arr[k]=T1[i];
        i++; k++;
    }
    while(j<size2){
        arr[k]=T2[j];
        j++; k++;
    }
}

void mergesort(int arr[], int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");

    for(int i=0; i<size; i++){
            scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, size-1);

    printf("Sorted Array: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
