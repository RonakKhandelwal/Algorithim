#include <iostream>
#include <stdio.h>

using namespace std;


int max(int a, int b){
  return a > b? a: b;
}

int lps(char *seq, int i, int j)
{
   if (i == j)
     return 1;
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;
   if (seq[i] == seq[j])
      return lps (seq, i+1, j-1) + 2;
   return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

int main(){
  char x[] = "GEEKSFORGEEKS";
  int l = strlen(x);
  cout<<lps(x, 0, l)<<endl;
}
