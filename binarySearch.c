#include <stdio.h>

int binSearch(int arr[], int low, int high, int key){
	int mid;
	mid = (low + high)/2;
	if(high>=low){
		if(arr[mid]==key){
			return 1;
		}else if(arr[mid] < key){
			binSearch(arr, mid+1, high, key);
		}else if (arr[mid > key]){
			binSearch(arr, low, mid-1, key);
		}		
	}else{
		return 0;
	}	
}


void main(){
	int arr[6]={12,14,15,16,18,20};
	int n;
	printf("Enter a number to search: ");
	scanf("%d",&n);
	if (binSearch(arr,0,5,n)){
		printf("Found\n");
	}else{
		printf("Not Found.");
	}	
}