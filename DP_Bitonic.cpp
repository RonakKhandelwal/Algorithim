#include <iostream>

using namespace std;


int lbs(int arr[], int n){
  int dp[n+1];
  for(int i = 0; i < n; i++ ){
    dp[i] = 1;
  }
  for(int  i = 1; i <= n; i++){
    int max_val = 0;
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[i]){
        max_val = max(max_val, dp[j]);
      }
    }
    dp[i] = max_val + 1;
  }
  int dp1[n+1];
  for(int i = 0; i < n; i++ ){
    dp1[i] = 1;
  }
  for(int  i = 1; i <= n; i++){
    int max_val = 0;
    for(int j = 0; j < i; j++){
      if(arr[j] > arr[i]){
        max_val = max(max_val, dp1[j]);
      }
    }
    dp1[i] = max_val + 1;
  }
  int max_val = -1;
  for(int  i = 0; i< n; i++){
    max_val = max(max_val, dp[i] + dp1[i] - 1);
  }
  return max_val;

}

int main(){
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<lbs(arr, n)<<endl;
  return 0;
}
