/*
Counting the number of inverted pairs in an array
For example in the array {7,12,13,14,15,11,9} the inverted pairs are (14,11),(14,9),(15,9),(15,11), ... and so on.
So for an inverted pair in an array, A the inverted pairs are (A[i],A[j]) where i < j and A[i] > A[j]
*/

#include<stdio.h>

int getInvPair(int arr[], int n){
    int inv=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                inv++;
            }
        }
    }
    return inv;
}

void main(){
    int arr[7] = {7,12,13,14,15,11,9};
    int invPairs = getInvPair(arr, 7);
    printf("The number of inversion pairs is %d",invPairs);
}