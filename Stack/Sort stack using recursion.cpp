#include <iostream>
#include "./Stack Implementation/stack.h"

using namespace std;

Stack<int> placeInStack(Stack<int> s,int topElement)
{
    if(s.stackSize()==0||topElement<s.top())
    {
        s.push(topElement);
        return s;
    }
    int currentTopElement=s.pop();
    s=placeInStack(s,topElement);
    s.push(currentTopElement);
    return s;
}

Stack<int> sortStack(Stack<int> s)
{
    if(s.stackSize()==0)
    {
        return s;
    }
    int topElement=s.pop();
    s=sortStack(s);
    s=placeInStack(s,topElement);
    return s;
}

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
    s=sortStack(s);
    cout<<"Sorted Stack:";
    while(!s.isEmpty())
    {
        cout<<s.pop()<<" ";
    }
    return 0;
}
