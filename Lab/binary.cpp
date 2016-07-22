#include <iostream>

using namespace std;

int binarySearch(int a[],int l,int r,int key){
  if(l<r){
  int mid=l+(r-l)/2;
  if(a[mid] == key)return mid;
  else if (a[mid] < key) {
    binarySearch(a,mid+1,r,key);
  }
  else{
    binarySearch(a,l,mid,key);
  }

}
else{
  return -1;
}

}


int main(){
  int arr[]={1,2,3,4,5,6};
  int n=6;
  int ans=binarySearch(arr,0,5,3);
  cout<<ans<<endl;
}
