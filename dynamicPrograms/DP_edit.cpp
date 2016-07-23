#include <iostream>
#include <stdlib.h>

using namespace std;

// Utility function to find minimum of three numbers
int min(int x, int y, int z)
{
  int m = x;
  if(m > y){
    m = y;
  }
  if(m > z){
    m = z;
  }
  return m;
}

int editDist(char a[], char b[], int n, int m){
  int arr[n+1][m+1];
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      if(i == 0){
        arr[i][j] = j;
      }
      else if(j == 0){
        arr[i][j] = i;
      }
      else if(a[i - 1] == b[j - 1]){
        arr[i][j] = arr[i-1][j-1];
      }
      else{
        arr[i][j] = 1 + min(arr[i-1][j], arr[i][j - 1], arr[i-1][j-1]);
      }
    }
  }
  return arr[n][m];
}

int main()
{
    // your code goes here
    char str1[] = "sunday";
    char str2[] = "saturday";

    int n = strlen(str1);
    int m = strlen(str2);

    cout << editDist(str1, str2, n, m);

    return 0;
}
