#include<stdio.h>
#include<stdbool.h>


typedef struct job{
    char jobID;
    int profit, deadline;
}Job;

int min(int x, int y){
    if(x>y){
        return y;
    }else{
        return y;
    }    
}


void jobSeq(Job jobs[], int size){
    int slot[size];
    int result[size];
    for (int i = 0; i < size; i++){
        slot[i] = false;        
    }
    for (int i = 0; i < size; i++){
        for (int j = min(size, jobs[i].deadline)-1; j >=0; j--){
            if(slot[j] == false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }        
    }
    int total = 0;
    for (int i = 0; i < size; i++){
        if(slot[i] == true){
            total += jobs[result[i]].profit;
        }
    }
    printf("%d\n",total);   
    
}



void main(){
    Job jobs[5] = {
        {'A',20,2},
        {'B',15,2},
        {'C',10,1},
        {'D',5,3},
        {'E',1,3}
    };
    jobSeq(jobs,5);
}