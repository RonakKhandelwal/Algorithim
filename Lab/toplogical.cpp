#include <iostream>

using namespace std;

struct Node{
  int value;
  struct Node* next;
};

Node* root;
struct Node* add(Node* root,int val){
  Node* temp=new Node;
  temp->value=val;
  temp->next=root;
  return temp;
}

void dfs(int a[][5],int visited[],int v,int n){
if(visited[v] == 0){
  visited[v]=1;
  for(int i=0;i<n;i++){
    if(a[v][i] && !visited[i]){
      dfs(a,visited,i,n);
    }
  }
  root=add(root,v+1);

}
}

void print(){
  Node* cur=root;

  while(cur !=NULL){
    cout<<cur->value<<endl;
    cur=cur->next;
  }

}

int main(){
  int a[5][5]={{0,0,1,0,0},
               {0,0,1,0,0},
               {0,0,0,1,1},
               {0,0,0,0,1},
               {0,0,0,0,0}};
  int visited[5]={0};
for(int i=0;i<5;i++)
  dfs(a,visited,i,5);
  print();

  return 0;

}
