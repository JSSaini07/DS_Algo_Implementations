//T:O(N)
//S::O(1)
/*
Moore's Voting Algorithm: If a number repeats more than n/2 times, we can store the first number as answer and start incrementing
counter each time the next number is same as current and decrementing if opposite, if count reaches zero we update our answer.
Now, if there exists a number that comes more than n/2 times, it is guranteed that we will get it as answer, in other case we have to
check if the answer we are getting is coming more than n/2 times.
*/

#include <iostream>
#include <map>

using namespace std;

int a[100000];

int findNumber(int n)
{
    int index=0,ctr=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[index])
        {
            ctr++;
        }
        else
        {
            ctr--;
            if(ctr==0)
            {
                index=i;
                ctr=1;
            }
        }
    }
    return a[index];
}

bool verify(int r,int n)
{
    int ctr=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==r)
        {
            ctr++;
            if(ctr>(n/2))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int r=findNumber(n);
    bool z=verify(r,n); // to check if the number found comes more than n/2 times or not
    if(z==true)
    {
        cout<<r;
    }
    else
    {
        cout<<"No such number found";
    }
    return 0;
}
