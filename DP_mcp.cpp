#include <iostream>
#define R 3
#define C 3

using namespace std;

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int mcp(int cost[R][C], int m, int n){
  if(m == 0 && n == 0)
  return 0;

  else{
    int i, j;
    int tc[R][C];
    tc[0][0] = cost[0][0];
    for (i = 1; i <= m; i++)
    tc[i][0] = tc[i-1][0] + cost[i][0];
    for (j = 1; j <= n; j++)
    tc[0][j] = tc[0][j-1] + cost[0][j];
    for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
    tc[i][j] = min(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + cost[i][j];

    return tc[m][n];

  }
}

int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", mcp(cost, 2, 2));
   return 0;
}
