#include<stdio.h>

int visited [5]= {0, 0, 0, 0, 0};
int a[5][5]={
    {0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0}
};

int q[20], f=-1, r=-1;

void bfs(int v)
{
    for(int i = 0; i < 5; i++){
        if(a[v][i] != 0 && visited[i] == 0){
            r = r + 1;
            q[r] = i;
            visited[i] = 1;
            printf("%d ",i);
        }
    }
    f = f + 1;
    if(f <= r)
        bfs(q[f]);
}
int main()
{
    int v;
    printf("Enter the starting vertex:");
    scanf("%d",&v);
    f = r = 0;
    q[r] = v;
    printf("\nBFS traversal is:\n");
    visited[v] = 1;
    printf("%d ", v);
    bfs(v);
    if(r != 4)
        printf("\nBFS is not possible");
}
