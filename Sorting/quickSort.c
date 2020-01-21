#include <stdio.h>

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int startIndex, int endIndex){
    int pivotIndex, i, pivot;
    pivotIndex = startIndex-1;
    pivot = arr[endIndex];
    for(i=startIndex;i<=endIndex;i++){
        if(arr[i]<pivot){
            pivotIndex++;
            swap(&arr[i],&arr[pivotIndex]);
        }
    }
    swap(&arr[pivotIndex+1], &arr[endIndex]);
    return (pivotIndex+1);
}

void quickSort(int arr[], int startIndex, int endIndex){
    int pivotIndex;
    if(startIndex>=endIndex)
        return;
    pivotIndex = partition(arr, startIndex, endIndex);
    quickSort(arr, startIndex, pivotIndex-1);
    quickSort(arr, pivotIndex+1, endIndex);
}

void main(){
    int arr[50];
    int i, n;
    printf("Enter the number of terms to be entered: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter term %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("The array is: ");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i+1!=n)
            printf(", ");
    }
    printf("\n\n");
    quickSort(arr, 0, n-1);
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i+1!=n)
            printf(", ");
    }
    printf("\n\n");
}

