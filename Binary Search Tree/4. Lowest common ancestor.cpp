#include <iostream>
#include "./Implementation/BST.h"
#include "./Implementation/IO.h"

using namespace std;

int findLCA(BST<int>* root,int x,int y)
{
    if(!root)
    {
      return -1;
    }
    if(root->data>x&&root->data>y)
    {
      return findLCA(root->left,x,y);
    }
    else
    if(root->data<x&&root->data<y)
    {
      return findLCA(root->right,x,y);
    }
    return root->data;
}


int main()
{
  BST<int>* root;
  int x,y;
  root=inputBST();
  cout<<"Enter node values:";
  cin>>x>>y;
  int r=findLCA(root,x,y);
  cout<<r;
  return 0;
}
