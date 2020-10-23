#include <stdio.h>
#include <stdlib.h>
struct QNode
{
    int data;
    struct QNode *next;
} *front = NULL, *rear = NULL;
void Enqueue(int x)
{
    struct QNode *t;
    t = (struct QNode *)malloc(sizeof(struct QNode));
    if(t == NULL)
        printf("Queue is Full!\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;   
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int Dequeue()
{
    int x = -1;
    if(front == NULL)
        printf("Queue is Empty!\n");
    else
    {
        struct QNode *t;
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
int IsEmptyQueue()
{
    return front == NULL;
}
// void Display()
// {
//     struct Node *p;
//     p = front;
//     while(p)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }