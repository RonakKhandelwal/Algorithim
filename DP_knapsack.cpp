#include <iostream>

using namespace std;

int knapsack(int val[], int weight[], int n, int W){
  if(n == 0 || W == 0){
    return 0;
  }
  else if(weight[n-1] <= W){
    return max(knapsack(val,weight,n-1,W), knapsack(val,weight,n-1,W - weight[n-1]) + val[n-1]);
  }
  else{
    return knapsack(val, weight, n-1, W);
  }
}


int knapsackDP(int val[], int weight[], int n, int W){
  int dp[n+1][W+1];
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <=W; j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
      else if(weight[i-1] > W){
        dp[i][j] = dp[i-1][j];
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + val[i-1]);
      }
    }
  }
  return dp[n][W];
}

int max(int a, int b){
  return a > b? a : b;
}

int main(){
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int  W = 50;
  int n = sizeof(val)/sizeof(val[0]);
  cout<< knapsackDP(val, wt, n, W)<<endl;
}
