#include <iostream>
#include <math.h>

using namespace std;




void minHeap(int a[],int n){
  int k,i,j,item;
  for (k=1;k<n;k++)
  {
      item = a[k];
      i = k;
      j = (i-1)/2;
      while((i>0)&&(item<a[j]))
      {
          a[i] = a[j];
          i = j;
          j = (i-1)/2;
      }
      a[i] = item;
  }
}



int main(){
  int a[]={4,5,9,7,8,3};
  minHeap(a,6);
  for(int i=0;i<6;i++){
    cout<<a[i]<<endl;
  }

  return 0;
}
