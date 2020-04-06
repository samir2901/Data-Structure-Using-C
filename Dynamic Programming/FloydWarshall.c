#include<stdio.h>
#define V 4
#define INF 99999

int min(int x, int y){
    return x < y ? x : y;
}

void printSolution(int dist[V][V]){
    int i, j;
    printf("The final distance graph:\n");
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            if (dist[i][j] == INF){
                printf("INF");
            }else{
                printf("%d\t",dist[i][j]);
            }            
        }    
        printf("\n");    
    }
}

void floydWarshall(int graph[V][V]){
    int prev[V][V], i, j, k;    
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            prev[i][j] = graph[i][j];
        }        
    }
    for (int k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){               
                if (prev[i][k] + prev[k][j] < prev[i][j]){
                    prev[i][j] = prev[i][k] + prev[k][j];
                }
                
            }        
        }     
    }    
    printSolution(prev);   
}


int main(){
    int graph[V][V] = {{0,8,INF,1},
                       {INF,0,1,INF},
                       {4,INF,0,INF},
                       {INF,2,9,0}};
    floydWarshall(graph);    
    return 0;
}
