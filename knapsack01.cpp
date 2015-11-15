#include <iostream>

using namespace std;

int max(int a,int b){
  return a>b?a:b;
}

int knapsack(int weight[], int value[], int W, int n, int inc[]){

  int K[n+1][W+1];
  for (int i=0;i<=n;i++)
  {
      for (int j=0;j<=W;j++)
      {
          if (i==0 || j==0)
              K[i][j] = 0;
          else if (weight[i-1]<=j)
                K[i][j]=max(value[i-1]+K[i-1][j-weight[i-1]],K[i-1][j]);
          else
                K[i][j]=K[i-1][j];
      }
  }
  return K[n][W];
}


int main(){
  int value[]={12,10,20,15};
  int weight[]={2,1,3,2};
  int W=5,n=4;
  int inc[n];
  cout<<"Knapsack: "<<knapsack(weight,value,W,n,inc)<<endl;
  return 0;


  return 0;
}
