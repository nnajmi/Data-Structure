#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
void Create(int A[], int n) // Convert array to linked list
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Create2(int A[], int n) // Convert array to linked list
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for(i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void RDisplay(struct Node *p) // Recursive Display
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}
void RDisplayBackward(struct Node *p) // backward recursive Display of the linked list 
{
    if(p != NULL)
    {
        RDisplayBackward(p->next);
        printf("%d ", p->data);
    }
}
int Count(struct Node *p)
{
    int count = 0;
    while( p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int RCount(struct Node *p) // Time : O(n), Space : O(n)
{
    if( p == NULL)
        return 0;
    else
        return RCount(p->next) + 1;
}
int RCount2(struct Node *p) 
{
    int x = 0;
    if( p )
    {
        x = RCount2(p->next);
        return x + 1;
    }
    else
        return x;
}
int Sum(struct Node *p) // O(n)
{
    int sum = 0;
    while(p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int RSum(struct Node *p) // Time : O(n), Space : O(n) 
{
    if(p == NULL)
        return 0;
    else
        return RSum(p->next) + p->data;
}
int Max(struct Node *p)
{
    int max = INT_MIN;
    //int max = p->data;
    //p = p->next;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int RMax(struct Node *p)
{
    int x;
    if(p == 0)
        return INT_MIN;
    x = RMax(p->next);
    if(x > p->data)
        return x;
    else
        return p->data;
}
struct Node* LSearch(struct Node *p, int key) //Linear Search, Iterative Version
{
    while(p)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}
struct Node* LSearch2(struct Node *p, int key) //Move to front
{
    struct Node *q = NULL;
    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
struct Node* RSearch(struct Node *p, int key) //Linear Search, Recursive Version
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next, key);
}
void Insert(struct Node *p, int index, int x)
{
    if(index < 0 || index > Count(p))
        return;
    struct Node *t;
    int i;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int i, x = -1;

    if(index < 1 || index > Count(p))
        return x;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int IsSorted(struct Node *p)
{
    int x = INT_MIN;
    while(p)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}
void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
void Reverse1(struct Node *p) //Using an array
{
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int) * Count(p));
    while(q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
void Reverse2(struct Node *p) //Using sliding pointers
{
    struct Node *q = NULL, *r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void Reverse3(struct Node *q, struct Node *p) //Using Recursion
{
    if(p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}
void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
}
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)
        last->next = p;
    if(q)
        last->next = q;
}
int IsLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    }
    while(p && q && p != q);
    if(p == q)
        return 1;
    else
        return 0;  
}
int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);

    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;

    printf("%d", IsLoop(first));

    return 0;
}