#include<stdio.h>

int adjacencyMat[6][6] = {{0,1,1,0,0,0},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,1,1},{0,1,1,1,0,1},{0,0,0,1,1,0}};
int visited[12];
int nVertices = 6;

void dfs(int v){   
    printf("%d\t",v);
    visited[v] = 1;
    for (int i = 0; i < nVertices; i++){
        if(!visited[i] && adjacencyMat[v][i]==1){
            dfs(i);
        }
    }    
}


void main(){
    for (int i = 0; i < nVertices; i++){
        visited[i] = 0;
    }
    dfs(0);
    printf("\n");
}