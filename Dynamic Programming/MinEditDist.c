#include<stdio.h>

int min(int x, int y, int z){
    if(x < y && x < z){
        return x;
    }else if(y < z){
        return y;
    }else{
        return z;
    }
}

int minEditDist(char str1[], char str2[], int m, int n){
    int table[m+1][n+1];
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if(i==0){
                table[i][j] = j;
            }else if(j==0){
                table[i][j] = i;
            }else if(str1[i-1] == str2[j-1]){
                table[i][j] = table[i-1][j-1];
            }else{
                table[i][j] = 1 + min(table[i][j-1], table[i-1][j], table[i-1][j-1]);
            }
        }        
    }
    return table[m][n];    
}

void main(){
    char str1[6] = "abcdef";
    char str2[5] = "ajced";
    printf("Minimum edit distance: %d\n", minEditDist(str1,str2,6,5));
}