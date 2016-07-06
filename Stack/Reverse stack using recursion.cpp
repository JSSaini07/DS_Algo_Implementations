#include <iostream>
#include "./Stack Implementation/stack.h"

using namespace std;

Stack<int> placeAtEnd(Stack<int> s,int topElement)
{
    if(s.isEmpty())
    {
        s.push(topElement);
        return s;
    }
    int currentTopElement=s.pop();
    s=placeAtEnd(s,topElement);
    s.push(currentTopElement);
    return s;
}

Stack<int> reverseStack(Stack<int> s)
{
    if(s.isEmpty())
    {
        return s;
    }
    int topElement=s.pop();
    s=reverseStack(s);
    s=placeAtEnd(s,topElement);
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
    s=reverseStack(s);
    while(!s.isEmpty())
    {
        cout<<s.pop()<<" ";
    }
    return 0;
}
