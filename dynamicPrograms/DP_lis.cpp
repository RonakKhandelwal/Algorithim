#include <iostream>
#include <stdio.h>

using namespace std;



int lis(int arr[], int n){
  int *lis = (int*) malloc(n*sizeof(arr[0]));
  for(int i = 0; i < n; i++){
    lis[i] = 1;
  }
  int maxLis = 1;
  for(int i = 1; i < n; i++){
    int max_lis = 0;
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[i]){
        if(lis[j] > max_lis){
          max_lis = lis[j];
        }
      }
    }
    lis[i] = max_lis + 1;
  }
  int max = 0;
  for (int i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
  return max;
}

int main(){
  int arr[] = { 15, 27, 14, 38, 26, 55, 46, 65, 85 } ;
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<lis(arr, n)<<endl;

}
