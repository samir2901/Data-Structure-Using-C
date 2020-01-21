#include <stdio.h>
void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void InsertionSort(int arr[], int n){
    int i, j;
    for(i=1;i<n;i++){
        for(j=i;j>0&&arr[j-1]>arr[j];j--){
            swap(&arr[j-1], &arr[j]);
        }
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
    InsertionSort(arr,n);
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i+1!=n)
            printf(", ");
    }
    printf("\n\n");
}

