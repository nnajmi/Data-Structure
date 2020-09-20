#include <stdio.h>
class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};
class Queue
{
    private:
        int size;
        int front;
        int rear;
        Node **Q;
    public:
        Queue() {front = rear = -1; size = 10; Q = new Node*[size];};
        Queue(int size);
        void Enqueue(Node *x);
        Node * Dequeue();
        int IsEmpty() {return front==rear;};
        void Display();
};
Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new Node*[size];
}
void Queue::Enqueue(Node *x)
{
    if(rear == size - 1)
        printf("Queue is Full!");
    else
    {
        rear++;
        Q[rear] = x;
    }   
}
Node * Queue::Dequeue()
{
    Node *x = NULL;
    if(rear == front)
        printf("Queue is Empty!");
    else
    {
        front++;
        x = Q[front];
    } 
    return x;  
}
void Queue::Display()
{
    int i;
    for(i = front + 1; i <= rear; i++)
        printf("%d ", Q[i]);
    printf("\n");
}