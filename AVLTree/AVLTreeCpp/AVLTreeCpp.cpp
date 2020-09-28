#include <iostream>
using namespace std;
class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
        int height;
};
class AVL
{
    private:
        Node *root;
         
        //Helper methods
        int NodeHeight(Node *p);
        int BalanceFactor(Node *p);
        Node * LLRotation(Node *p);
        Node * LRRotation(Node *p);
        Node * RLRotation(Node *p);
        Node * RRRotation(Node *p);
        Node * InPre(Node *p);
        Node * InSucc(Node *p);
        void Inorder(Node *p);
        Node * RInsert(Node *p, int key);
        Node * Delete(Node *p, int key);
    public:
        AVL() { root = NULL;}

        void RInsert(int key) {root = RInsert(GetRoot(), key);};
        void Delete(int key) {Delete(GetRoot(), key);};
        void Inorder() {Inorder(GetRoot());}
        Node * GetRoot() { return root;}
};
int AVL::NodeHeight(Node *p)
{
    int hl, hr;
    if(p && p->lchild)
        hl = p->lchild->height;
    else
        hl = 0;

    if(p && p->rchild)
        hr = p->rchild->height;
    else
        hr = 0;
    if(hl > hr)
        return hl + 1;
    else
        return hr + 1;
}
int AVL::BalanceFactor(Node *p)
{
    int hl, hr;
    if(p && p->lchild)
        hl = p->lchild->height;
    else
        hl = 0;

    if(p && p->rchild)
        hr = p->rchild->height;
    else
        hr = 0;
    return hl - hr;
}
Node * AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    return pl;    
}
Node * AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root == p)
        root = pr;
    return pr;    
}
Node * AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;
    return plr;    
}
Node * AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;
    return prl;    
}
Node * AVL::InPre(Node *p)
{
    if(p)
        p = p->lchild;
    while(p && p->rchild)
        p = p->rchild;
    return p;
}
Node * AVL::InSucc(Node *p)
{
    if(p)
        p = p->rchild;
    while(p && p->lchild)
        p = p->lchild;
    return p;
}
void AVL::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
Node * AVL::RInsert(Node *p, int key)
{
    Node *t;
    if(p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        t->height = 1;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    
    p->height = NodeHeight(p);

    //Balance Factor and Rotation
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RLRotation(p);
    
    return p;
}
Node * AVL::Delete(Node *p, int key)
{
    if(p == nullptr)
        return nullptr;

    if(p->lchild == nullptr && p->rchild == nullptr)
    {
        if(p == root)
            root = nullptr;
        delete p;
        return nullptr;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        Node *q;
        if(NodeHeight(p->lchild) > NodeHeight(p->rchild))
        {
            q = InPre(p);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        } 
    }
    p->height = NodeHeight(p);
    //Balance Factor and Rotation
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RLRotation(p);
    
    return p;
}

int main()
{
    AVL tree;
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        tree.RInsert(A[i]);
    
    tree.Inorder();
    cout << endl;

    tree.Delete(28);
     
    tree.Inorder();
    cout << endl;
    return 0;
}