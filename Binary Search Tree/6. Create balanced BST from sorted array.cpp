#include <iostream>
#include "./Implementation/BST.h"
#include "./Implementation/IO.h"

using namespace std;

int n;
int a[100000];

BST<int>* converToBST(int x,int y)
{
    if(x>y)
    {
      return NULL;
    }
    int mid=(x+y)/2;
    BST<int>* root=new BST<int>(a[mid]);
    root->left=converToBST(x,mid-1);
    root->right=converToBST(mid+1,y);
    return root;
}


int main()
{
  BST<int>* root;
  int x,y;
  cout<<"Enter the size of array:";
  cin>>n;
  cout<<"Enter the array:";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  root=converToBST(0,n-1);
  printLevelWise(root);
  return 0;
}
