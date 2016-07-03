//Kadane's Algorithm
//T:0(N)
//S:O(1)

#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

void kadane(int n)
{
    int left=0,right=0,answerleft=0,answerright=0,large=0,r=0;
    for(int i=0;i<n;i++)
    {
        r+=a[i];
        if(r>large)
        {
            large=r;
            right=i;
            answerright=i;
        }
        else
        if(r<=0)
        {
            r=0;
            answerleft=left;
            answerright=right;
            left=i+1;
            right=i+1;
        }
    }
    answerleft=left;
    answerright=right;
    int arr_max_element_index=max_element(a,a+n)-a;
    if(large==0)
    {
        answerleft=arr_max_element_index;
        answerright=arr_max_element_index;
        large=a[arr_max_element_index];
    }
    cout<<answerleft<<" "<<answerright<<" "<<large<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    kadane(n);
    return 0;
}
