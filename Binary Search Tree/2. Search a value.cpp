#include <iostream>
#include "./Implementation/BST.h"
#include "./Implementation/IO.h"

using namespace std;

bool searchBST(BST<int>* root,int data)
{
    if(!root)
    {
      return false;
    }
    if(root->data==data)
    {
      return true;
    }
    bool dataInLeftSubtree=searchBST(root->left,data);
    bool dataInRightSubtree=searchBST(root->right,data);
    return (dataInLeftSubtree||dataInRightSubtree);
}

int main()
{
  BST<int>* root;
  int data;
  root=inputBST();
  cout<<"Enter the data to be searched:";
  cin>>data;
  bool r=searchBST(root,data);
  if(r)
  {
    cout<<"Data is present";
  }
  else
  {
    cout<<"Data not present";
  }
  return 0;
}
