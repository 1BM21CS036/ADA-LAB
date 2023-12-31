#include<stdio.h>

int graph[20][20], vis[10];

void DFS(int i,int n){
    int j;
    printf("Visited:%d\n",i);
    vis[i]=1;
    for(j=0;j<n;j++){
        if(graph[i][j]==1 && vis[j]==0){
            DFS(j,n);
        }
    }
}
void main(){

    int n,i,j,top=-1;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix representing the graph:\n");
   
    int vis[n],st[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    DFS(0,n);
}
