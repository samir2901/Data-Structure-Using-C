#include <stdio.h>
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void SelectionSort(int arr[], int n){
    int i, j;
    int minIndex;
    for(i=0;i<n;i++){
        minIndex = i;
        for(j=i+1;j<n;j++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
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
    SelectionSort(arr,n);
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i+1!=n)
            printf(", ");
    }
    printf("\n\n");
}
