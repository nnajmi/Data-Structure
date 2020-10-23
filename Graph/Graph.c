#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

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
    return 0;
}