#include <iostream>
#include <stack>
using namespace std;
class Node
{
    public: 
        Node *lchild;
        int data;
        Node *rchild;
};
class BST
{
    private:
        Node *root;
    public:
        BST(){root = nullptr;}
        Node * Getroot() { return root;}
        void Inorder(Node *p);
        Node * ISearch(int key); 
        Node * RSearch(Node *p, int key); 
        void IInsert(int key);
        Node * RInsert(Node *p, int key);  
        int Height(Node *p);
        Node * InPre(Node *p);
        Node * InSucc(Node *p); 
        Node * Delete(Node *p, int key);
        void CreateFromPreorder(int pre[], int n);
};
void BST::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
Node * BST::ISearch(int key)
{
    Node *t = root;
    while(t != nullptr)
    {
        if(t->data == key)
            return t;
        else if(t->data < key)
            t = t->rchild;
        else
            t = t->lchild;
    }
    return nullptr;
}
Node * BST::RSearch(Node *p, int key)
{
    if(p == nullptr)
        return nullptr;

    if(p->data == key)
        return p;
    else if(p->data < key)
        return RSearch(p->rchild, key);
    else
        return RSearch(p->lchild, key);
}
void BST::IInsert(int key)
{
    Node *t = root;
    Node *p, *r;

    //root is empty
    if(root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }
    while(t != nullptr)
    {
        r = t;
        if(key == t->data)
            return;
        else if(key < t->data)
            t = t->lchild;
        else 
            t = t->rchild;     
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
Node * BST::RInsert(Node *p, int key)
{
    Node *t;
    if(p == nullptr)
    {
        t = new Node;
        t->data = key;
 
        t->lchild = t->rchild = nullptr;
        if(this->Getroot() == nullptr)
            root = t;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    return p;
}
int BST::Height(Node *p)
{
    int x = 0, y = 0;
    if(p == nullptr)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
Node * BST::InPre(Node *p)
{
    p = p->lchild;
    while(p && p->rchild)
        p = p->rchild;
    return p;
}
Node * BST::InSucc(Node *p)
{
    p = p->rchild;
    while(p && p->lchild)
        p = p->lchild;
    return p;
}
Node * BST::Delete(Node *p, int key)
{
    Node *q;
    if(p == nullptr)
        return nullptr;
    if(p->lchild == nullptr && p->rchild == nullptr)
    {
        if(p == root)
            root = nullptr;
        delete p;
        return nullptr;
    }
    if( key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
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
    return p;
}
void BST::CreateFromPreorder(int pre[], int n)
{
    int comp;
    //Create root node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = nullptr;

    //Iterative steps
    Node *t;
    Node *p = root;
    stack <Node *> stk;
    while(i < n)
    {
        //Left child case
        if(pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        //Right child case
        else
        {
            if(stk.empty())
                comp = 32767;
            else
                comp = stk.top()->data;
            if(pre[i] > p->data && pre[i] < comp)
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = nullptr;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }            
        }
    }
}
int main()
{
    BST bst;
    Node *temp;
    
    //Iterative Insert
    bst.IInsert(10);
    bst.IInsert(5);
    bst.IInsert(20);
    bst.IInsert(8);
    bst.IInsert(30);
    bst.Inorder(bst.Getroot());
    cout << endl;
    
    //Recursive Insert
    bst.RInsert(bst.Getroot(), 50);
    bst.RInsert(bst.Getroot(), 70);
    bst.RInsert(bst.Getroot(), 1);
    bst.Inorder(bst.Getroot());
    cout << endl;
    
    //Iterative Search
    temp = bst.ISearch(2);
    if(temp != nullptr)
        cout << temp->data << " was found" << endl;
    else
        cout << "Key was not found." <<endl;
    
    //Recursive Search
    temp = bst.RSearch(bst.Getroot(), 2);
    if(temp != nullptr)
        cout << temp->data << " was found" << endl;
    else
        cout << "Key was not found." <<endl;
    
    //Height
    cout << "Height " << bst.Height(bst.Getroot()) << endl;
    
    //Inorder predecessor and inorder successor
    cout << "Inorder predecessor " << bst.InPre(bst.Getroot())->data << endl;
    cout << "Inorder successor " << bst.InSucc(bst.Getroot())->data << endl;

    // Delete
    bst.Delete(bst.Getroot(), 5);
    bst.Inorder(bst.Getroot());
    cout << endl;

    //Create BST from Preorder
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    BST b;
    int n = sizeof(pre) / sizeof(pre[0]);
    b.CreateFromPreorder(pre, n);
    b.Inorder(b.Getroot());
    //cout << "root " << b.Getroot()->lchild->lchild->data;
    return 0;
}