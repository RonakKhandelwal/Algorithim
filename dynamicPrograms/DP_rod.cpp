#include <iostream>


using namespace std;



int rod(int price[], int n){
  if(n == 0) return 0;
  int max_val = -1;
  for(int i = 0; i < n; i++){
    max_val = max(max_val, price[i] + rod(price, n-i-1));
  }
  return max_val;
}

int rodDP(int price[], int n){
  int dp[n+1];
  dp[0] = 0;
  for(int i =1; i <= n; i++){
    int max_val = -1;
    for(int j = 0; j < i; j++){
      max_val = max(max_val, price[j] + dp[i-j-1]);
    }
    dp[i] = max_val;
  }
  return dp[n];
}


int main(){
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout<<rodDP(arr, size)<<endl;
  return 0;
}
