#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

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