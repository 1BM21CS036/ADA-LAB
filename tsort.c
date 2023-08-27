#include<stdio.h>
#include<stdlib.h>

int visited[50],graph[10][10],n,stack[10],top=-1;

void topological_sort(int node){
    visited[node]=1;

    for(int j=0;j<n;j++){
        if(graph[node][j]==1 && visited[j]!=1){
            topological_sort(j);
        }
    }

    stack[++top]=node;
}

int main(){
printf("Enter Number of nodes\n");
scanf("%d",&n);
printf("Enter the matrix\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        int key;
        scanf("%d",&key);
        graph[i][j]=key;
    }
}for(int i=0;i<n;i++){
        topological_sort(i);
    }
   

    printf("\nTOPOLOGICAL SORT\n");
    while(top!=-1){
        printf("%d ",stack[top--]);
    }

return 0;
}

