#include <iostream>

#define V 10

using namespace std;



int minIndex(int dist[],bool sptSet[]){
  int min=9999,min_index;

  for(int i=0;i<V;i++){
    if(!sptSet[i] && dist[i]<min) {
      min=dist[i];min_index=i;
    }
  }
  return min_index;
}


void printSpt(int dist[]){
  for(int i=0;i<V;i++){
    cout<<"Shortest path form the spource for vertex "<<i<<" is "<<dist[i]<<endl;
  }
}


void djiktras(int graph[V][V]){
  int dist[V];
  bool sptSet[V];
  for(int i=0;i<V;i++){
    dist[i]=9999;
    sptSet[i]=false;
  }
  dist[0]=0;
  for(int count=0;count<V;count++){
    int u=minIndex(dist,sptSet);
    sptSet[u]=true;
    for(int i=0;i<V;i++){
      if (!sptSet[i] && graph[u][i] && dist[u] != 9999 && (dist[u]+graph[u][i]<dist[i])) {
        dist[i]=dist[u]+graph[u][i];
      }
    }
  }

  printSpt(dist);
}



int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    djiktras(graph);

    return 0;
}
