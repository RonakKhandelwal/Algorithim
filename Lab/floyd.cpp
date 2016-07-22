#include <iostream>

using namespace std;

void floyd(int a[4][4]){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
         a[i][j]=a[i][j]<(a[i][k]+a[k][j])?a[i][j]:(a[i][k]+a[k][j]);
        }
    }
  }
}

int main(){
  int a[4][4]={
    {0,9999,3,9999},
    {2,0,9999,9999},
    {9999,7,0,1},
    {6,9999,9999,0}
  };
  floyd(a);
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      cout<<a[i][j]<<"\t";
    }
    cout<<endl;
  }
}
