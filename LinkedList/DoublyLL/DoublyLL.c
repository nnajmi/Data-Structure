#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <stack>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int Length(struct Node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > Length(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{
    int x = -1, i;

    if(index < 1 || index > Length(p))
        return x;
    if(index == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
             p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}
void Reverse(struct Node *p)
{
    struct Node *t;
    while(p)
    {
        t = p->prev;
        p->prev = p->next;
        p->next = t;
        p = p->prev;
        if(p != NULL && p->next == NULL)
            first = p;
    }
}
void middleNode1(struct Node *p)
{
    int len = Length(p);
    int index = (int)ceil(len/2.0);
    for(int i = 0; i < index - 1; i++)
        p = p->next;
    printf("Middle Element is %d using Method I\n", p->data);
}
void middleNode2(struct Node *p)
{
    struct Node *q = p;
    while(q)
    {
        q = q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    printf("Middle Element is %d using Method II\n", p->data);
}
// void middleNode3(struct Node *p)
// {
//     stack <Node *> s;
//     while(p)
//     {
//         s.push(p);
//         p = p->next;
//     }
//     int len = s.size();
//     int popLen = (int)floor(len/2.0);
//     while(popLen)
//     {
//         s.pop();
//         popLen--;
//     }
//     printf("Middle Element is %d using Method III\n", p->data);
// }
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);

    middleNode1(first);
    middleNode2(first);
    //middleNode3(first);
    return 0;
}