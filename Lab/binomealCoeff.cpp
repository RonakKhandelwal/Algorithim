#include <iostream>

using namespace std;

int binomeal(int n,int k){
  if(k==0||k==n){
    return 1;
  }
  else{
    return binomeal(n-1,k-1)+binomeal(n-1,k);
  }
}


int main(){

  cout<<binomeal(5,2);

  return 0;
}
