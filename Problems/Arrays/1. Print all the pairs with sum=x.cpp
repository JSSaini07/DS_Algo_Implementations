//T:O(N)
//S::O(N) [One Pass]

#include <iostream>
#include <map>

using namespace std;

int a[100000];
map <int,int> m;

void printPairs(int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        if(m[sum-a[i]]>0)
        {
            for(int j=0;j<m[sum-a[i]];j++)   // print all the pairs formed
            {
                cout<<"("<<sum-a[i]<<","<<a[i]<<")"<<endl;
            }
        }
        m[a[i]]++;
    }
}

int main()
{
    int n,sum;
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    printPairs(n,sum);
    return 0;
}
