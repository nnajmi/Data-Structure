#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void Enqueue(struct Queue *q, int x)
{
    if((q->rear + 1) % q->size == q->front)
        printf("Queue is Full!");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }   
}
int Dequeue(struct Queue *q)
{
    int x = -1;
    if(q->rear == q->front)
        printf("Queue is Empty!");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    } 
    return x;  
}
void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }while(i != (q.rear + 1)%q.size);
    printf("\n");
}
int main()
{
    struct Queue q;
    Create(&q, 5);
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Display(q);
    printf("%d", Dequeue(&q));
    return 0;
}