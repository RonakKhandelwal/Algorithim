#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 500
int t[MAX],k=0;

void shifttable(char p[])
{
    int i,j,m;
    m=strlen(p);
    for(i=0;i<MAX;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]]=m-1-j;
}

int horspool(char src[],char p[])
{
    int i,j,m,n;
    n=strlen(src);
    m=strlen(p);
    cout<<"\nLength of text = "<<n;
    cout<<"\nLength of pattern = "<<m;
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

int main()
{
    char src[100],p[100];
    int pos;
    cout<<"Enter the text in which pattern is to be searched: \n";
    gets(src);
    cout<<"Enter the pattern to be searched: \n";
    gets(p);
    shifttable(p);
    pos=horspool(src,p);
    if(pos>=0)
        cout<<"\nThe desired pattern was found starting from position "<<pos+1;
    else
        cout<<"\nThe pattern was not found in the given text\n";
    cout<<"\nNumber of comparisons = "<<k<<endl;
    return 0;
}
