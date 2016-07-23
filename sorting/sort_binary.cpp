#include <iostream>
using namespace std;

int binary(int arr[], int l, int r, int x){
  if(l < r){
    int m = l + (r-l)/2;
    if(arr[m] == x){
      return m;
    }
    else if(arr[m] < x){
      return binary(arr, m+1, r, x);
    }
    else{
      return binary(arr, 0, m-1, x);
    }
  }
  return -1;
}

int main(){

  int arr[] = {0,1,2,3,4,5,6,7,8,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  int lol = binary(arr, 0, n, 3);
  if(lol == -1){
    cout<<"Not found"<<endl;
  }
  cout<<lol<<endl;


}
