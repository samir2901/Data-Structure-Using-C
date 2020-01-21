#include<stdio.h>

void merge(int arr[], int l, int mid, int u){
    int i,j,k;
    int b[50];
    for(i=l,j=mid+1,k=l;i<=mid && j<=u; k++){
        if(arr[i]<=arr[j]){
            b[k]=arr[i++];
        }else{
            b[k]=arr[j++];
        }
    }
    while(i<=mid){
        b[k++]=arr[i++];
    }
    while(j<=u){
        b[k++]=arr[j++];
    }
    for(k=0;k<=u;k++){
        arr[k]=b[k];
    }
}

void mergeSort(int arr[], int l, int u){
    int mid;
    if(l<u){
        mid = (l+u)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, u);
        merge(arr, l, mid, u);
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
    mergeSort(arr, 0, n-1);
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i+1!=n)
            printf(", ");
    }
    printf("\n\n");
}



