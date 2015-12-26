#include <iostream>


using namespace std;


int max(int a,int b){
  return a>b?a:b;
}

int knpasack(int weight[],int v[],int n,int w){
  int a[n+1][w+1];

  for(int i=0;i<=n;i++){
    for(int j=0;j<=w;j++){
      if(i==0||j==0){
        a[i][j]=0;
      }
      else if(weight[i-1] <= j){
        a[i][j]=max(v[i-1]+a[i-1][j-weight[i-1]],a[i-1][j]);
      }
      else{
        a[i][j]=a[i-1][j];
      }
    }
  }

  return a[n][w];
}




int main(){
  int value[]={12,10,20,15};
  int weight[]={2,1,3,2};
  int w=5,n=4;
  int inc[n];
  cout<<"Knapsack: "<<knpasack(weight,value,n,w)<<endl;
  return 0;
  return 0;
}
