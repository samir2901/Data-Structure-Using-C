//Find the length of the longest increasing subsequence
#include<stdio.h>

int LISLen(int arr[], int n){
    int L[n];
    L[0] = 1;
    for (int i = 1; i < n; i++){
        L[i] = 1;
        for (int j = 0; j < i; j++){
            if ((arr[j] < arr[i]) && (L[i] < L[j] + 1)){
                L[i] = 1 + L[j];
            }            
        }        
    }
    int max = 0;
    for (int k = 0; k < n; k++){
        if(L[k] > L[max]){
            max = k;
        }
    }
    return L[max];    
}

void main(){
    int arr[12] = {5,7,4,-3,9,1,10,4,5,8,9,3};
    printf("Length of LIS: %d\n",LISLen(arr,12));
}