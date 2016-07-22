#include <iostream>
#define V 5

using namespace std;

int maxIndex(int weight[],bool mstSet[]){
  int max=-1,max_index;
  for(int i=0;i<V;i++){
    if(!mstSet[i] && weight[i] > max){
      max=weight[i];
      max_index=i;
    }
  }
  return max_index;
}

void printTree(int parent[],int weight[]){
  cout<<"edge\tWeight"<<endl;
  for(int i=1;i<V;i++){
    cout<<i<<"-"<<parent[i]<<"\t"<<weight[i]<<endl;
  }
}

void prims(int graph[V][V]){
  int weight[V];
  bool mstSet[V];
  int parent[V];
  for(int i=0;i<V;i++){
    weight[i]=-1;
    mstSet[i]=false;
  }
  weight[0]=0;
  parent[0]=-1;
  for(int count=0;count <V-1;count++){
    int u=maxIndex(weight,mstSet);
    mstSet[u]=true;
    for(int i=0;i<V;i++){
      if(!mstSet[i] && graph[u][i] && graph[u][i] > weight[i]){
        weight[i]=graph[u][i];
        parent[i]=u;
      }
    }
  }

  printTree(parent,weight);
}





int main(){

  int graph[V][V] = {{0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0},
                       };

      // Print the solution
      prims(graph);

      return 0;

  return 0;
}
