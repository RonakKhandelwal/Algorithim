#include<iostream>

using namespace std;

void heapify(int a[],int n)
{
    int k,i,j,item;
    for (k=1;k<n;k++)
    {
        item = a[k];
        i = k;
        j = (i-1)/2;
        while((i>0)&&(item>a[j]))
        {
            a[i] = a[j];
            i = j;
            j = (i-1)/2;
        }
        a[i] = item;
    }
}

void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[]={2, 9, 7, 6, 5, 8};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Before Heap\n";
    display(a,n);
    heapify(a,n);
    cout<<"After Heap\n";
    display(a,n);
    return 0;
}
