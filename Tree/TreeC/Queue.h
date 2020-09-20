#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void Create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}
void Enqueue(struct Queue *q, struct Node *x)
{
    if(q->rear == q->size - 1)
        printf("Queue is Full!");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }   
}
struct Node* Dequeue(struct Queue *q)
{
    struct Node  *x = NULL;
    if(q->rear == q->front)
        printf("Queue is Empty!");
    else
    {
        q->front++;
        x = q->Q[q->front];
    } 
    return x;  
}
int IsEmptyQueue(struct Queue q)
{
    return q.front == q.rear;
}

////////////////////////////////////////////////////////////////////

struct Stack
{
    int size;
    int top;
    struct Node **S;
};
void StackCreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1; 
    st->S = (struct Node**)malloc(st->size * sizeof(struct Node*));
}
void Display(struct Stack st)
{

    int i;
    for(i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}
void Push(struct Stack *st, struct Node *x)
{
    if(st->top == st->size - 1)
        printf("Stack Overflow!\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
struct Node* Pop(struct Stack *st)
{
    struct Node *x = NULL;
    if(st->top == -1)
        printf("Stack Underflow!\n");
    else
        x = st->S[st->top--];
    return x;
}
struct Node* Peek(struct Stack st, int index)
{
    struct Node *x = NULL;
    if(st.top - index + 1 < 0)
        printf("Invalid Index");
    x = st.S[st.top - index + 1];
    return x;
}
int IsEmptyStack(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}
int IsFullStack(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    return 0;
}
struct Node* StackTop(struct Stack st)
{
    if(!IsEmptyStack(st))
        return st.S[st.top];
    return NULL;
}