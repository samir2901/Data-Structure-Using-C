#include <stdio.h>

int fibDP(int n){
    int F[n+1];
    F[0] = 0;
    F[1] = 1;
    for(int i=2;i<n+1;i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}

void main(){
    for (int i = 0; i < 6; i++){
        printf("%d ",fibDP(i));
    }    
}