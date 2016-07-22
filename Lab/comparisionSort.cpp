#include <iostream>

using namespace std;


void counting(int a[],int n){
  int count[n];
  for(int i=0;i<n;i++){
    count[i]=0;
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(a[i]<a[j])
        count[j]++;
      else
        count[i]++;
    }
  }
  int s[n];
  for(int i=0;i<n;i++){
    s[count[i]]=a[i];
  }
  for(int i=0;i<n;i++){
      a[i]=s[i];
  }

}


void print(int a[],int n){
  for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
  }
}


int main(){
  int arr[] = {10,120,500,300,30,27};
  int n = sizeof(arr)/sizeof(arr[0]);
  counting(arr,n);
  cout<<"sorted array"<<endl;
  print(arr,n);

  return 0;
}
