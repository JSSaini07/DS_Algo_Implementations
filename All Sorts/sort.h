#include <iostream>

using namespace std;

template <typename datatype>
class Sort {
private:
    void merge(datatype elements[],int x1,int y1,int x2,int y2);
    int partition(datatype elements[],int pivot,int first,int n);
    void minHeapify(datatype elements[],int index,int first,int n);
public:
    void insertionSort(datatype elements[],int first,int n);
    void selectionSort(datatype elements[],int first,int n);
    void bubbleSort(datatype elements[],int first,int n);
    void mergeSort(datatype elements[],int first,int n);
    void quickSort(datatype elements[],int first,int n);
    void heapSort(datatype elements[],int first,int n);
};

template<typename datatype>
void Sort<datatype>::insertionSort(datatype elements[],int first,int n)
{
    for(int i=first;i<first+n-1;i++)
    {
        for(int j=i+1;j>first;j--)
        {
            if(elements[j]<elements[j-1])
            {
                swap(elements[j],elements[j-1]);
            }
        }
    }
}

template<typename datatype>
void Sort<datatype>::selectionSort(datatype elements[],int first,int n)
{
    for(int i=first;i<first+n-1;i++)
    {
        datatype minElement=elements[i];
        int minIndex=i;
        for(int j=i+1;j<first+n;j++)
        {
            if(elements[j]<minElement)
            {
                minElement=elements[j];
                minIndex=j;
            }
        }
        swap(elements[i],elements[minIndex]);
    }
}

template <typename datatype>
void Sort<datatype>::bubbleSort(datatype elements[],int first,int n)
{
    for(int i=0;i<n;i++)
    {
       int flag=1;
        for(int j=first;j<first+n-i-1;j++)
        {
            if(elements[j]>elements[j+1])
            {
                flag=-1;
                swap(elements[j],elements[j+1]);
            }
        }
        if(flag==1)
        {
            break;
        }
    }
}

template <typename datatype>
void Sort<datatype>::merge(datatype elements[],int x1,int y1,int x2,int y2)
{
    datatype tempArray[x2+y2];
    int i=x1;
    int j=x2;
    int k=x1;
    while(i<x1+y1&&j<x2+y2)
    {
        if(elements[i]<elements[j])
        {
            tempArray[k]=elements[i];
            i++;
            k++;
        }
        else
        {
            tempArray[k]=elements[j];
            j++;
            k++;
        }
    }
    while(i<x1+y1)
    {
        tempArray[k]=elements[i];
        i++;
        k++;
    }
    while(j<x2+y2)
    {
        tempArray[k]=elements[j];
        j++;
        k++;
    }
    for(int i=x1;i<x1+y1;i++)
    {
        elements[i]=tempArray[i];
    }
    for(int i=x2;i<x2+y2;i++)
    {
        elements[i]=tempArray[i];
    }
}

template <typename datatype>
void Sort<datatype>::mergeSort(datatype elements[],int first,int n)
{
    if(n<=1)
    {
        return;
    }
    mergeSort(elements,first,n/2);
    mergeSort(elements,first+n/2,(n-n/2));
    merge(elements,first,n/2,first+n/2,(n-n/2));
}

template <typename datatype>
int Sort<datatype>::partition(datatype elements[],int pivot,int first,int n)
{
    datatype pivotElement=elements[pivot];
    int partitionIndex=0;
    for(int i=first;i<first+n;i++)
    {
        if(elements[i]<pivotElement)
        {
            partitionIndex++;
        }
    }
    swap(elements[pivot],elements[first+partitionIndex]);
    int i=first;
    int j=first+partitionIndex+1;
    while(i<first+partitionIndex&&j<first+n)
    {
        if(elements[i]>pivotElement&&elements[j]<pivotElement)
        {
            swap(elements[i],elements[j]);
        }
        else
        if(elements[i]>pivotElement)
        {
            j++;
        }
        else
        if(elements[j]<pivotElement)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    return first+partitionIndex;
}

template <typename datatype>
void Sort<datatype>::quickSort(datatype elements[],int first,int n)
{
    if(n<=1)
    {
        return;
    }
    int pivot=first;
    int partitionIndex=partition(elements,pivot,first,n);
    quickSort(elements,first,partitionIndex-first);
    quickSort(elements,partitionIndex+1,first+n-partitionIndex-1);
}

template <typename datatype>
void Sort<datatype>::minHeapify(datatype elements[],int index,int first,int n)
{
    int i=index;
    int left=2*i;
    int right=left+1;
    left-=first;
    right-=first;
    int smallIndex=i;
    if(left<=first+n&&elements[left]<elements[smallIndex])
    {
        smallIndex=left;
    }
    if(right<=first+n&&elements[right]<elements[smallIndex])
    {
        smallIndex=right;
    }
    if(smallIndex!=i)
    {
        swap(elements[i],elements[smallIndex]);
        minHeapify(elements,smallIndex,first,n);
    }
}

template <typename datatype>
void Sort<datatype>::heapSort(datatype elements[],int first,int n)
{
    datatype newArray[n+1];
    for(int i=0;i<n;i++)
    {
        newArray[i+1]=elements[first+i];
    }
    for(int i=n/2;i>=1;i--)
    {
        minHeapify(newArray,i,0,n+1);
    }
    for(int i=1;i<=n;i++)
    {
        minHeapify(newArray,i+1,i,n-i);
    }
    for(int i=0;i<n;i++)
    {
        elements[first+i]=newArray[i+1];
    }
}

