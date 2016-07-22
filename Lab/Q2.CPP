#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node *left,*right;
};

int height(Node *root)
{
    if(root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    if(l>r)
        return l+1;
    return r+1;
}

int bfactor(Node *root)
{
    int l = height(root->left);
    int r = height(root->right);
    return l-r;
}

Node * rightRotate(Node* p)
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

Node * leftRotate(Node* q)
{
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    return p;
}

Node * balance(Node *p)
{
    if(bfactor(p)==2)
    {
        if( bfactor(p->right) < 0 )
            p->right = rightRotate(p->right);
        return leftRotate(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = leftRotate(p->left);
        return rightRotate(p);
    }
    return p;
}

Node * insert(Node * root, int item)
{
    if(root==NULL)
    {
        root= new Node;
        root->left=NULL;
        root->right=NULL;
        root->x=item;
        return root;
    }
    if( item<root->x)
        root->left = insert(root->left,item);
    else
        root->right = insert(root->right,item);
    return balance(root);
}

void inorder(Node * root)
{
    if (root==NULL)
        return;
    inorder(root->left);
    cout<<root->x<<" ";
    inorder(root->right);
}

int main()
{
    Node *root=NULL;
    int a[]= {10,20,5,8,2,4,7,12};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
        root=insert(root,a[i]);
    inorder(root);
}
