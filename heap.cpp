#include <iostream>
#include <math.h>

using namespace std;

void heapify(int a[],int n){
  for(int i=floor(n/2);i>0;i--){
    int k=i;
    int v=a[k];
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

void heapsort(int a[],int n){
  int k=n-1;
  while(n>0){
    int temp=a[n-1];
    a[n-1]=a[0];
    a[0]=temp;
    --n;
    heapify(a,n);
  }
}


int main(){
  int a[]={2,9,7,6,5,8};
  int n=6;
  heapify(a,6);
  heapsort(a,6);
  for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
  }
}
