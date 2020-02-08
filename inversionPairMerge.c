/*
Counting the number of inverted pairs in an array
For example in the array {12,13,14,15,11,9} the inverted pairs are (14,11),(14,9),(15,9),(15,11).
So for an inverted pair in an array, A the inverted pairs are (A[i],A[j]) where i < j and A[i] > A[j].
But here the counting will be done with the help of merge sort (divide and conquer).
*/
 
#include <stdio.h> 
#include <stdlib.h>
int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

int getInvPair(int arr[], int array_size) 
{ 
	int* temp = (int*)malloc(sizeof(int) * array_size); 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
	int mid, inv_count = 0; 
	if (right > left) { 
		mid = (right + left) / 2; 
		inv_count += _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 

int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	i = left; 
	j = mid; 
	k = left;
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++]; 
			inv_count = inv_count + (mid - i); 
		} 
	} 
	while (i <= mid - 1) {
		temp[k++] = arr[i++]; 
    }

	while (j <= right) {
		temp[k++] = arr[j++]; 
    }
	for (i = left; i <= right; i++) {
		arr[i] = temp[i]; 
    }
	return inv_count; 
} 

void main(){
    int arr[7] = {7,12,13,14,15,11,9};
    int invPairs = getInvPair(arr, 7);
    printf("The number of inversion pairs is %d",invPairs);
}
