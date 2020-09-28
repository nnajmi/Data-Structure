#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;
int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild? p->lchild->height:0;
    hr = p && p->rchild? p->rchild->height:0;
    return hl > hr ? hl + 1 : hr + 1;
}
int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild? p->lchild->height:0;
    hr = p && p->rchild? p->rchild->height:0;
    return hl - hr;   
}
struct Node * LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p == root)
        root = pl;
    return pl;
}
struct Node * LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(p == root)
        root = plr;
    return plr;
}
struct Node * RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl;
    pr->lchild = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(p == root)
        root = pr;
    return pr;    
}
struct Node * RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->rchild = pr;
    prl->lchild = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(p == root)
        root = prl;
    return prl;   
}
struct Node * RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if(p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; //we start height from 1
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    p->height = NodeHeight(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) 
        return LLRotation(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) 
        return LRRotation(p);
    if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) 
        return RRRotation(p);
    if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) 
        return RLRotation(p);
    return p;
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
int main()
{
    // //LL Rotation
    // root = RInsert(root, 10);
    // RInsert(root, 5);
    // RInsert(root, 2);
    // Inorder(root);

    // //LR Rotation
    // root = RInsert(root, 50);
    // RInsert(root, 10);
    // RInsert(root, 20);
    // Inorder(root);

    // //RR Rotation
    // root = RInsert(root, 10);
    // RInsert(root, 20);
    // RInsert(root, 30);
    // Inorder(root);

    //RL Rotation
    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 15);
    Inorder(root);
    return 0;
}
