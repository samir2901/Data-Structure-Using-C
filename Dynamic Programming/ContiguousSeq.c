/*
A contiguous subsequence of a list S is a subsequence made up of consecutive elements of S. For
instance, if S is
5; 15; −30; 10; −5; 40;10;
then 15; −30; 10 is a contiguous subsequence but 5; 15; 40 is not. Give a linear-time algorithm for
the following task:
Input: A list of numbers, a1; a2; : : :; an.
Output: The contiguous subsequence of maximum sum (a subsequence of length zero
has sum zero).
For the preceding example, the answer would be 10; −5; 40; 10, with a sum of 55.
*/

#include<stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int CSSum(int arr[], int n){
    int S[n];
    S[0] = 0;
    for (int i = 1; i < n; i++)
    {
        S[i] = arr[i] + max(0, S[i-1]);
    }

    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (S[i] > S[maxIndex])
        {
            maxIndex = i;
        }
        
    }
    return S[maxIndex];    
}

void main(){
    int arr[7] = {5, 15, -30, 10, -5, 40, 10};
    printf("Largest Sum: %d",CSSum(arr,7));
}