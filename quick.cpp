#include <iostream>
#include <stdio.h>
using namespace std;


int piviot(int a[],int l,int r){
  int piv=a[r];
  int j=r-1;
  int i=l;
  while(i<j){
    if(a[i] < piv){
      i++;
      continue;
    }
    else{
      while(a[j]>piv && j>i){
        j--;
      }
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
  a[r]=a[i];
  a[i]=piv;

  return i;
}

void quickSort(int a[],int l,int r){
  if(l<r){
    int p=piviot(a,l,r);
    quickSort(a,l,p-1);
    quickSort(a,p+1,r);


  }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {10,120,500,300,30,27};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
