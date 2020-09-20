#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
//#include "Stack.h"

struct Node *root = NULL;
void TreeCreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    Create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    Enqueue(&q, root);

    while(!IsEmptyQueue(q))
    {
        p = Dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Enqueue(&q, t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Enqueue(&q, t);
        }
    }
}
void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Preorder(p->lchild);
        printf("%d ", p->data);
        Preorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if(p)
    {
        Preorder(p->lchild);
        Preorder(p->rchild);
        printf("%d ", p->data);
    }
}
void IPreorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p || !IsEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            Push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = Pop(&stk);
            p = p->rchild;
        }
    }
}
void IInorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p || !IsEmptyStack(stk))
    {
        if(p)
        {
            Push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = Pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
// void IPostorder(struct Node *p)
// {
//     struct Stack stk;
//     StackCreate(&stk, 100);
//     struct Node *temp;

//     while(p || !IsEmptyStack(stk))
//     {
//         if(p)
//         {
//             Push(&stk, p);
//             p = p->lchild;
//         }
//         else
//         {
//             temp = Pop(&stk);
//             if(temp > 0)
//             {
//                 Push(&stk, -temp);
//                 p = ((struct Node *)temp)->lchild;
//             }
//             else
//             {            
//                 printf("%d ", ((struct Node *)temp)->data);
//                 p = NULL;
//             }
//         }
//     }
// }
 void Levelorder(struct Node *root)
{
    struct Queue q;
    Create(&q, 100);

    printf("%d ", root->data);
    Enqueue(&q, root);

    while(!IsEmptyQueue(q))
    {
        root = Dequeue(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            Enqueue(&q, root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            Enqueue(&q, root->rchild);
        }
    }
}
int Count(struct Node *root)
{
    if(root)
        return Count(root->lchild) + Count(root->rchild) + 1;
    else
        return 0;
}
int CountLeaves(struct Node *root)
{
    if(root)
    {
        if(!root->lchild && !root->rchild)
            return CountLeaves(root->lchild) + CountLeaves(root->rchild) + 1;
        else
            return CountLeaves(root->lchild) + CountLeaves(root->rchild); 
    }       
    else
        return 0;
}
int CountInternalNodes(struct Node *root)
{
    if(root)
    {
        if(root->lchild || root->rchild)
            return CountInternalNodes(root->lchild) + CountInternalNodes(root->rchild) + 1;
        else
            return CountInternalNodes(root->lchild) + CountInternalNodes(root->rchild); 
    }       
    else
        return 0;
}
int Height(struct Node *root)
{
    int x = 0, y = 0;
    if(root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    TreeCreate();
    printf("Count %d\n", Count(root));
    printf("Count Leaves %d\n", CountLeaves(root));
    printf("Count Internal %d\n", CountInternalNodes(root));
    printf("Height %d\n", Height(root));
    return 0;
}