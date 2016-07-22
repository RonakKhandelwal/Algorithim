#include <iostream>

using namespace std;


struct Node{
    int x;
     Node* left;
     Node* right;
};

int height(Node* root){
  if(root == NULL)
    return 0;
  else return height(root->right)>height(root->left)?height(root->right)+1:height(root->left)+1;
}


Node* rightRotate(Node* p){
  Node* q= p->left;
  p->left=q->right;
  q->right=p;
  return q;
}

Node* leftRotate(Node* p){
  Node* q=p->right;
  p->right=q->left;
  q->left=p;
  return q;
}

int bfactor(Node* p){
  int l=height(p->left);
  int r=height(p->right);
}


Node* balance(Node* p){
  int b=bfactor(p);
  if(b == 2){
    if (bfactor(p->left) < 0) {
      p->left=leftRotate(p->left);

    }
    return rightRotate(p);
  }
    else if(b == -2){
      if(bfactor(p->right) > 0){
        p->right=rightRotate(p->right);
      }
      return leftRotate(p);
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
