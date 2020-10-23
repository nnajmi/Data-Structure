#include <stdio.h>
#include <stdlib.h>
struct SNode
{
    int data;
    struct SNode *next;
} *top = NULL;
void Push(int x)
{
    struct SNode *t;
    t = (struct SNode*)malloc(sizeof(struct SNode));
    if(t == NULL)
        printf("Stack Overflow!\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    } 
}
int Pop()
{
    int x = -1;
    struct SNode *t;
    if(top == NULL)
        printf("Stack is empty!\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
int Top()
{
    return top->data;
}
int IsEmptyStack()
{
    return top == NULL;
}
// void Display()
// {
//     struct Node *p;
//     p = top;
//     while(p != NULL)
//     {
//         printf("%d ", p->data);
//         p = p->next;
//     }
//     printf("\n");
// }