#include <iostream>

using namespace std;

void merger(int a[],int low,int mid,int high){
  int n1=mid-low+1;
  int n2=high-mid;
  int l[n1],m[n2];

  for(int i=0;i<n1;i++){
    l[i]=a[i+low];
  }
  for(int i=0;i<n2;i++){
    m[i]=a[mid+i+1];
  }
  int k=low,i=0,j=0;
  while(i<n1 && j<n2){
    if (l[i]<m[j]) {
      a[k]=l[i];
      i++;
    }
    else{
      a[k]=m[j];
      j++;
    }
    k++;
  }
  while (i<n1) {
    a[k++]=l[i++];
  }
  while (j<n2) {
    a[k++]=m[j++];
  }
}


void mergeSort(int a[],int l,int r){
  if(l<r){
    int m=l+(r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merger(a,l,m,r);
  }
}

int main(){
  int a[]={0,2,3,5,9,7,1,8,6,4};
  int n=10;
  mergeSort(a,0,9);
  for (int i = 0; i < 10; i++) {
    cout<<a[i]<<endl;
  }

  return 0;
}
