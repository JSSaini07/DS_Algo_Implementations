#include <iostream>
#include "./Implementation/BST.h"
#include "./Implementation/IO.h"

using namespace std;

void printRange(BST<int>* root,int x,int y)
{
      if(!root)
      {
        return;
      }
      if(root->data<x)
      {
        printRange(root->right,x,y);
        return;
      }
      if(root->data>y)
      {
        printRange(root->left,x,y);
        return;
      }
      cout<<root->data<<" ";
      printRange(root->left,x,y);
      printRange(root->right,x,y);
      return;
}


int main()
{
  BST<int>* root;
  int x,y;
  root=inputBST();
  cout<<"Enter range:";
  cin>>x>>y;
  printRange(root,x,y);
  return 0;
}
