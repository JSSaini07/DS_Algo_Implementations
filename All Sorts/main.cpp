#include <iostream>
#include "sort.h"

using namespace std;

int a[100000];

int main()
{
    int n;
    cin>>n;
    Sort<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    s.insertionSort(a,0,n);
    //s.selectionSort(a,0,n);
    //s.bubbleSort(a,0,n);
    //s.mergeSort(a,0,n);
    //s.quickSort(a,0,n);
    //s.heapSort(a,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
