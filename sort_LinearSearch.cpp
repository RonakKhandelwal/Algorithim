#include <iostream>
using namespace std;

int search(int arr[], int n, int x){
  for(int i = 0; i < n; i++){
    if(arr[i] == x){
      return i;
    }
  }
  return -1;
}



int main(){

  int arr[] = {1,5,4,2,3,9,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<search(arr, n, 3);

}
