#include <iostream>

using namespace std;

int searchSubs(char a[],int n1,char b[],int n2){
  for(int i=0;i<n1-n2;i++){
    int k=i,j=0;
    while(a[k] == b[j] && j<n2){
      k++;j++;
    }
    if(j == n2){
      return i;
    }
  }
  return -1;

}

int main(){
  int n1,n2;
  cin>>n1;
  cin>>n2;
  char a[n1];
  char b[n2];
  cin>>a;
  cin>>b;
  int ans=searchSubs(a,n1,b,n2);
  cout<<ans<<endl;


}
