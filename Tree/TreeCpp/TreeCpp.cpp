#include <iostream>
#include <stdio.h>
#include "QueueCpp.h"
using namespace std;
class Tree
{
    private:
        Node *root;
    public:
        Tree(){root = NULL;}
        void CreateTree();
        void Preorder() { Preorder(root);}
        void Preorder(Node *p);
        void Postorder() { Postorder(root);}
        void Postorder(Node *p);
        void Inorder() { Inorder(root);}
        void Inorder(Node *p);
        void Levelorder() { Levelorder(root);}
        void Levelorder(Node *p);
        int Height() { return Height(root);}
        int Height(Node *root);
};
void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.Enqueue(root);

    while(!q.IsEmpty())
    {
        p = q.Dequeue();
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.Enqueue(t);
        }
        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.Enqueue(t);
        }
    }
}
void Tree::Preorder(Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p)
{
    if(p)
    {
        Preorder(p->lchild);
        printf("%d ", p->data);
        Preorder(p->rchild);
    }
}
void Tree::Postorder(Node *p)
{
    if(p)
    {
        Preorder(p->lchild);
        Preorder(p->rchild);
        printf("%d ", p->data);
    }
}
void Tree::Levelorder(Node *root)
{
    Queue q(100);
    printf("%d ", root->data);
    q.Enqueue(root);

    while(!q.IsEmpty())
    {
        root = q.Dequeue();
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            q.Enqueue(root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            q.Enqueue(root->rchild);
        }
    }
}
int Tree::Height(Node *root)
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
    Tree t;
    t.CreateTree();
    cout << "\nPreorder: ";
    t.Preorder();
    cout << "\nInorder: ";
    t.Inorder();
    cout << "\nPostorder: ";
    t.Postorder();
    cout << "\nLevelorder: ";
    t.Levelorder();
    cout << "\nHeight: " << t.Height();
    return 0;
}