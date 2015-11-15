#include <iostream>

using namespace std;

void topologicalSort(int a[][5], int visited[], int v, int n,int sort[],int &x)
{
    if(visited[v]==0)
    {
        int i;
        visited[v]=1;
        for (i=0;i<n;i++)
            if(a[v][i] && !visited[i])
                topologicalSort(a,visited,i,n,sort,x);
        sort[x++] = v+1;
    }
    else return;
}

int main()
{
     int a[5][5]={{0,0,1,0,0},
                  {0,0,1,0,0},
                  {0,0,0,1,1},
                  {0,0,0,0,1},
                  {0,0,0,0,0}};
    int visited[5]={0},n=5,i,j,sort[5]={0},x=0;
    for(int i =0 ;i<5;i++)
        topologicalSort(a,visited,i,n,sort,x);

    cout<<"Topological Sort: ";
    for(int i=x-1;i>=0;i--)
        cout<<sort[i]<<" ";
    cout<<endl;
    return 0;
}
