#include <iostream>
#define V 5
using namespace std;


int minIndex(int key[],bool mstSet[]){
  int min=9999,min_index;
  for(int i=0;i<V;i++){
    if (mstSet[i] == false && key[i] < min){
      min =key[i];min_index=i;
    }
  }
  return min_index;
}


void printTree(int parent[],int graph[V][V]){
  cout<<"Edge Vertex"<<endl;
  for(int i=1;i<V;i++){
    cout<<parent[i]<<" - "<<i<<" "<<graph[parent[i]][i]<<endl;
  }
}

void primTreee(int graph[V][V]){
  int key[V];
  int parent[V];
  bool mstSet[V];
  for(int i=0;i<V;i++){
    key[i]=9999;
    mstSet[i]=false;
  }
  key[0]=0;
  parent[0]=-1;

  for(int count =0;count <V-1;count++){
    int u=minIndex(key,mstSet);
    mstSet[u]=true;
    for(int i=0;i<V;i++){
      if(graph[u][i] && mstSet[i]==false && graph[u][i]<key[i]){
        key[i]=graph[u][i];
        parent[i]=u;
      }
    }
  }
  printTree(parent,graph);

}


int main(){

  int graph[V][V] = {{0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0},
                       };

      // Print the solution
      primTreee(graph);

      return 0;

  return 0;
}
