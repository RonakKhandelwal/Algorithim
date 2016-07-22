#include <iostream>

using namespace std;

int sequential(int a[],int n,int key){
  for(int i=0;i<n;i++){
    if(a[i]==key){
      return i;
    }
  }

  return -1;

}

int main(){
  int a[]={0,4,5,7,8,10,34,58,90,4};
  int n=10;
  int ans=sequential(a,n,5);
  if(ans == -1){
    cout<<"Not found"<<endl;
  }
  else{
    cout<<"Found at position "<<ans+1<<endl;
  }


}
