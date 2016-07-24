#include <iostream>

using namespace std;


int subSeq(int arr[], int n){
  int dp[n+1];
  dp[0] = arr[0];
  for(int i = 1; i <=n; i++){
    int max_val = -1;
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[i])
        max_val = max(max_val, dp[j]);
    }
    if(max_val > 0)
      dp[i] = arr[i] + max_val;
    else
      dp[i] = arr[i-1];
  }
  int max = dp[0];
  for(int i = 0 ; i < n; i++){
    if(max < dp[i])
      max = dp[i];
  }
  return max;
}

int main(){
  int arr[] = {10, 5, 4, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<subSeq(arr, n)<<endl;
}
