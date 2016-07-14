#include <iostream>
#include "./Implementation/BST.h"
#include "./Implementation/IO.h"

using namespace std;

int convertTree(BST<int>* root,int data)
{
    if(!root)
    {
      return 0;
    }
    if(!(root->left||root->right))
    {
      int val=root->data;
      root->data=root->data+data;
      return val;
    }
    int r=data+convertTree(root->right,data);
    root->data=root->data+r;
    r=root->data;
    convertTree(root->left,r);
    return root->left->data;
}


int main()
{
  BST<int>* root;
  root=inputBST();
  convertTree(root,0);
  printLevelWise(root);
  return 0;
}
