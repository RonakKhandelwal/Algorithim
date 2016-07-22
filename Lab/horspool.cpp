#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int t[300];


void makeTable(char pattern[]){
  int m=strlen(pattern);
  for(int i=0;i<300;i++){
    t[i]=m;
  }
  for(int i=0;i<m-1;i++){
    t[pattern[i]]=m-i-1;
  }
}

int position(char src[],char p[]){
  int n=strlen(src);
  int m=strlen(p);
  int i,j,k;

  i=m-1;
  while(i<n)
  {
      k=0;
      while((k<m)&&(p[m-1-k]==src[i-k]))
          k++;
      if(k==m)
          return(i-m+1);
      else
          i+=t[src[i]];
  }
  return -1;
}

int main(){

  char src[100],p[100];
  int pos;
  cout<<"Enter the text in which pattern is to be searched: \n";
  gets(src);
  cout<<"Enter the pattern to be searched: \n";
  gets(p);
  makeTable(p);
  pos=position(src,p);
  if(pos>=0)
      cout<<"\nThe desired pattern was found starting from position "<<pos+1<<endl;
  else
      cout<<"\nThe pattern was not found in the given text\n"<<endl;
  //cout<<"\nNumber of comparisons = "<<k<<endl;
  return 0;
}
