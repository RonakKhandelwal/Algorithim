#include <iostream>

using namespace std;

void selection(int a[],int n){

  int i=0,j=0;

  for(i=0;i<n;i++){
    int min=i;
    for(j=i;j<n;j++){
      if (a[min]>a[j]) {
        min=j;
      }
    }
    int temp=a[i];
    a[i]=a[min];
    a[min]=temp;

  }
}

void bubble(int a[],int n){
  int swapped=0;
  int i=0,j=0;
  for(i=0;i<n;i++){
    for(j=0;j<n-i-1;j++){
      if (a[j]>a[j+1]) {
        swapped=1;
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }

  }

}

int main(){
  int a[]={5,7,9,90,23,45,1,0,8,4};
  int n=10;
  bubble(a,n);
  for(int i=0;i<n;i++){
      cout<<a[i]<<endl;

  }



}
