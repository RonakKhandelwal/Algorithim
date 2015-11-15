#include <iostream>

using namespace std;

char c[]={'a','b','c','d','e','f'};

void bfs(int a[][6], int visited[], int q[], int v, int n, int f, int r)
{
    int i;
    visited[v]=1;
    for(i=0;i<n;i++)
        if(a[v][i] && !visited[i])
        {
            visited[i]=1;
            cout<<c[v]<<"->"<<c[i]<<endl;
            q[++r]=i;
        }
    if(f<=r)
    {
        bfs(a,visited,q,q[f++],n,f,r);
    }
}

int main()
{
    int a[6][6]={{0,0,1,1,0,0},
                {0,0,0,0,1,1},
                {1,0,0,1,0,1},
                {1,0,1,0,0,0},
                {0,1,0,0,0,1},
                {0,1,1,0,1,0}};
    int visited[6]={0},q[6]={0},n=6,i,j;
    char start;
    cout<<"Enter starting point: "; cin>>start;
    bfs(a,visited,q,int (start-97),n,0,-1);
    return 0;
}
