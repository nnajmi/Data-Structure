#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
#define I __INT32_MAX__
void BFS(int G[][7], int start, int n)
{
    int i = start;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    Enqueue(i);

    while(!IsEmptyQueue())
    {
        i = Dequeue();
        for(int j = 1; j < n; j++)
            if(visited[j] == 0 && G[i][j] == 1)
            {
                printf("%d ", j);
                visited[j] = 1;
                Enqueue(j);
            }
    }   
}
void DFSRecursive(int G[][7], int start, int n)
{
    static int visited[7] = {0}; //static, so we can have access within all recursive function calls
    if(visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for(int j = 1; j < n; j++)
            if(G[start][j] == 1 && visited[j] == 0)
                DFSRecursive(G, j, n);
    }
}
void DFSIterative(int G[][7], int start, int n)
{
    int i = start;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    Push(i);

    int j= 0;
    while(!IsEmptyStack())
    {
        while(j < n)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                Push(i);
                printf("%d ", j);
                visited[j] = 1;
                i = j;
                j = -1;
            }
            j++;
        }
        j = i;    
        i = Pop();
    }   
}
void DFSIterative2(int G[][7], int start, int n) //Not sure if it is working properly.
{
    int i = start;
    int visited[7] = {0};
    //printf("%d ", i);
    //visited[i] = 1;
    Push(i);

    while(!IsEmptyStack())
    {
        i = Pop();
        if(visited[i] == 0)
        {
            printf("%d ", i);
            visited[i] = 1;
        }
        for(int j = 1; j < n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0)
            {
                Push(j);
            }
        }
    }   
}
void Prim(int cost[][8], int n)
{
    int near[8] = {I, I, I, I, I, I, I, I};
    int t[2][7];
    int i, j, u, v, k, min = I;
    for(i = 1; i <= n; i++)
        for(j = i; j <= n; j++)
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = 0;
    near[v] = 0;
    for(i = 1; i <= n; i++)
        if(near[i] != 0)
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;

    for(i = 1; i < n-1; i++)
    {
        min = I;
        for(j = 1; j <= n; j++)
            if(near[j] != 0 && cost[j][near[j]] < min)
            {
                k = j;
                min = cost[j][near[j]];
            } 
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        //Update near array
        for(j = 1; j <= n; j++)
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
    } printf("\nPrim Result:\n"); 
    for(i = 0; i < n-1; i++)
        printf("(%d, %d) ", t[0][i], t[1][i]);
    printf("\n");
}
//Kruskal Algorithm
void Union(int set[], int u, int v)
{
    if(set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    } 
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}
int Find(int set[], int u)
{
    int x = u, v = 0;
    while(set[x] > 0)
        x = set[x];
    while(u != x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}
void Kruskal(int edges[3][9], int n, int e)
{
    int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int included[9] = {0};
    int t[2][6];
    int i, j, k, u, v, min;

    i = 0;
    while(i < n-1)
    {
        min = I;
        u = 0;
        v = 0;
        for(j = 0; j < e; j++)
            if(included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        if(Find(set, u) != Find(set, v))
        {
            t[0][i] = u;
            t[1][i] = v;
            Union(set, Find(set, u), Find(set, v));
            i++;
        }
        included[k] = 1;
    }
    printf("\nKruskal Result:\n");
    for(i = 0; i < n-1; i++)
        printf("(%d, %d) ", t[0][i], t[1][i]);
    printf("\n");

}
int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1, 0, 0},
                    {0, 1, 0, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 1, 1},
                    {0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0}};
    printf("\nBFS: ");
    BFS(G, 1, 7);
    printf("\nDFS Recursive: ");
    DFSRecursive(G, 1, 7);
    printf("\nDFS Iterative: ");
    DFSIterative(G, 1, 7);
    printf("\nDFS Iterative2: ");
    DFSIterative2(G, 2, 7);

    //Test Prim Algorithm
    int cost[][8] = {{I, I, I, I, I, I, I, I},
                    {I, I, 25, I, I, I, 5, I},
                    {I, 25, I, 12, I, I, I, 10},
                    {I, I, 12, I, 8, I, I, I},
                    {I, I, I, 8, I, 16, I, 14},
                    {I, I, I, I, 16, I, 20, 18},
                    {I, 5, I, I, I, 20, I, I},
                    {I, I, 10, I, 14, 18, I, I}};
    int n = 7;
    Prim(cost, n);
    //Test Kruskal Algorithm
    int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                        {2, 6, 3, 7, 4, 5, 7, 6, 7},
                        {25, 5, 12, 10, 8, 16, 14, 20, 18}};
    n = 7;
    int e = 9;
    Kruskal(edges, n, e);
    return 0;
}