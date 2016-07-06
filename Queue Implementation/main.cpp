#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue<int> q;
    int n,data;
    cout<<"Enter the number of elements:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        q.enqueue(data);
    }
    cout<<"Queue Size:"<<q.queueSize()<<endl;
    cout<<"Front Element:"<<q.front()<<endl;
    while(!q.isEmpty())
    {
        cout<<q.dequeue()<<" ";
    }
    return 0;
}
