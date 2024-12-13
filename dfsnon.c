#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
void dfs(int vertex,int n){
    int stack[MAX],top=-1;
    stack[++top]=vertex;
    visited[vertex]=1;
    while(top!=-1){
        int node = stack[top--];
        printf("%d",node);
        for(int i=0;i<n;i++){
            if(adj[node][i]==1 && !visited[i]){
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}

int main(){
    int n,e;
    printf("\nNo.of vertices:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("\nNo.of edges:");
    scanf("%d",&e);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=0;
        }
    }
    printf("\nENTER (u,v):\n");
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int start;
    printf("\nEnter start:");
    scanf("%d",&start);
    dfs(start,n);
    return 0;
    
}