#include <iostream>

using namespace std;


void warshal(int a[][4],int n){
  int sol[4][4];
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      sol[i][j]=a[i][j];
    }
  }

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        sol[i][j]=sol[i][j] || (sol[i][k] && sol[k][j]);
      }
    }
  }


  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cout<<sol[i][j]<<"\t";
    }
    cout<<endl;
  }
}


int main(){
  int graph[4][4] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
  warshal(graph,4);
}
