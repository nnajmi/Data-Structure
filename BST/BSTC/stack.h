#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Stack
{
    int size;
    int top;
    struct Node **S;
};
void Create(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node*));
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
struct Node * Pop(struct Stack *st)
{
    struct Node *x = NULL;
    if(st->top == -1)
        printf("Stack Underflow!\n");
    else
        x = st->S[st->top--];
    return x;
}
int IsEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}
int IsFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    return 0;
}
struct Node* StackTop(struct Stack st)
{
    if(!IsEmpty(st))
        return st.S[st.top];
    return NULL;
}
