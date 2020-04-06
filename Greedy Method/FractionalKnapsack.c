#include<stdio.h>

float maxProfit(float weights[], float profits[], float capacity, int n){
    float x[n];
    for(int i=0;i<n;i++){
        x[i] = 0.0;
        printf("i= %d, x[%d]= %.2f\n", i, i, x[i]);
    }
    printf("\n");
    float weight = 0;
    for(int i=0;i<n;i++){
        if(weight + weights[i] <= capacity){
            x[i] = 1;
            weight = weight + weights[i];
        }else{
            x[i] = (capacity - weight) / weights[i];
            weight = capacity;            
        }        
        printf("i= %d, x[%d]= %.2f\n", i, i, x[i]);
    }
    float max = 0;
    for (int i = 0; i < n; i++){        
        max = max + profits[i] * x[i];
    }    
    return max;
}

void main(){
    float profits[7] = {10,5,15,7,6,18,3};
    float weights[7] = {2,3,5,7,1,4,1};
    float profit = maxProfit(weights,profits,15,7);
    printf("\nMaximum Profit: %.2f\n",profit);
}