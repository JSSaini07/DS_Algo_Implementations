#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> s;
    int n,data;
    cout<<"Enter the number of elements:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        s.push(data);
    }
    cout<<"Stack Size:"<<s.stackSize()<<endl;
    cout<<"Top Element:"<<s.top()<<endl;
    while(!s.isEmpty())
    {
        cout<<s.pop()<<" ";
    }
    return 0;
}
