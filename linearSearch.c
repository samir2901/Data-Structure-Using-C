#include <stdio.h>

int lenght(int arr[]){
    int x;
    x = sizeof(&arr)/sizeof(arr[0]);
    return x;    
}


int linearSearch(int arr[], int key){
    int i;
    for(i=0;i<lenght(arr);i++){
        if(key==arr[i]){
            return 1;
            break;
        }       
    }
    return 0;
}

void main(){
    int arr[5]={23,45,12,67,34};
    int key = 5;
    if(linearSearch(arr, key)){
        printf("Found\n");
    }else{
        printf("Not Found\n");
    }
}