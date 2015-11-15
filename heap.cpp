#include <iostream>
#include <math.h>

using namespace std;

void heapify(int a[],int n){
  for(int i=floor((n-1)/2);i>=0;i--){
    int k=i+1;
    int v=a[i];
    int heap=0;
    while(!heap && 2*k<n){
      int j=2*k;
      if (j<n-1) {
        if (a[j]<a[j+1]) {
          j++;
        }
      }
      if(v>=a[j]){
        heap=1;
      }
      else{
        a[k]=a[j];
        k=j;
      }
    }
    a[k]=v;
  }
}




int main(){
  int a[]={10,15,30,45,60,75};
  int n=6;
  heapify(a,6);

  for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
  }
}
