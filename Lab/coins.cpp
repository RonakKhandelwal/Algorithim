#include <iostream>

using namespace std;

int cns(int sum,int coins[],int n){
  int c[sum];
  for(int i=0;i<sum;i++){
    c[i]=999999;
  }
  c[0]=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
      if(coins[j] <= i && c[i-coins[j]]+1<c[i]){
        c[i]=c[i-coins[i]]+1;
      }
    }
  }
}


int cns2(int sum,int coins[],int n){
  int c[sum];
  for(int i=0;i<sum;i++){
    c[i]=-1;
  }
  c[0]=0;
  for(int i=0;i<sum;i++){
    
  }

}

int main(){
  int coins[]={1,3,5};
  int n=3;
  cout<<cns(11,coins,3)<<endl;;
}
