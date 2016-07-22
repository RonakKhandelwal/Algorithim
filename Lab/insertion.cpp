#include <iostream>

using namespace std;

void insertion(int a[],int n){
  for(int i=0;i<n;i++){
    int key=a[i];
    int j=i-1;
    while(key<a[j] && j>=0){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
  }
}

int main(){
  int a[]={1,5,8,9,2,4};
  int n=6;
  insertion(a,n);
  for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
  }

  return 0;
}
