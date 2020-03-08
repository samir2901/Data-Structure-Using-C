#include<stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int values[], int weights[], int capacity, int n){
    int K[n+1][capacity+1];
    int i, c;
    for(i=0;i<=n;i++)
        K[i][0] = 0;
    for(c=0;c<=capacity;c++)
        K[0][c] = 0;
    for(i=1;i<=n;i++){
        for(c=1;c<=capacity;c++){
            if(weights[i-1] <= c){
                K[i][c] = max(values[i-1] + K[i-1][c-weights[i-1]], K[i-1][c]);
            }else{
                K[i][c] = K[i-1][c];
            }
        }
    }    
    return K[n][capacity];
}

void main(){
    int values[4] = {15,10,8,1};
    int weights[4] = {15,12,10,5};
    int capacity = 22;
    printf("Maximum value: %d",knapsack(values,weights,capacity,4));
}