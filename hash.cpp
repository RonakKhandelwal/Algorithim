#include <iostream>

using namespace std;


struct Node{
  int value;
  struct Node* next;
};


Node* insert(Node* l,int v){
  Node* temp = new Node;
  temp->value=v;
  temp->next=l;
  return temp;

}

void add(Node hash[],int ele){
  int n=ele%6;
  hash[n].next=insert(hash[n].next,ele);
}

void print(Node hash[]){
  for(int i=0;i<6;i++){
    Node* cur=hash[i].next;
    while(cur != NULL){
      cout<<cur->value<<endl;
      cur=cur->next;
    }
    cout<<endl;
  }
}


int main(){
  Node hash[6];
  for(int i=0;i<6;i++){
    hash[i].value=0;
    hash[i].next=NULL;
  }
  add(hash,1);
  add(hash,2);
  add(hash,3);
  add(hash,4);
  add(hash,5);
  add(hash,6);
  add(hash,7);
  add(hash,8);
  add(hash,9);
  add(hash,10);
  add(hash,11);
  add(hash,12);

  print(hash);
  return 0;
}
