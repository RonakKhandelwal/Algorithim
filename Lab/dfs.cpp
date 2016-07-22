#include <iostream>

using namespace std;




void dfs(int a[6][6],int visited[6],int v,int n){

  visited[v]=1;
  for (int i=0; i < n; i++) {
    if (a[v][i] && !visited[i]) {
      dfs(a,visited,i,n);
      cout<<v<<"\t to\t"<<i<<endl;
    }
  }

}


int main(){
  int a[6][6]={
    {0,0,1,1,0,0},
    {0,0,0,0,1,1},
    {1,0,0,1,0,1},
    {1,0,1,0,0,0},
    {0,1,0,0,0,1},
    {0,1,1,0,1,0}
  };
  int visited[6]={0};
  dfs(a,visited,2,6);

}
