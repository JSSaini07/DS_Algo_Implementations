#include <iostream>
#include "./Implementation/BST.h"
#include "./Implementation/IO.h"

using namespace std;

BST<int>* deleteNode(BST<int>* root,int data)
{
    if(!root)
    {
      return NULL;
    }
    if(root->data==data)
    {
        if(!(root->left||root->right))
        {
          delete(root);
          return NULL;
        }
        else
        {
          if(root->right)
          {
            BST<int>* s=root->right;
            while(s->right)
            {
              s=s->left;
            }
            int val=s->data;
            deleteNode(root,s->data);
            root->data=val;
            return root;
          }
          else
          {
            BST<int>* s=root->left;
            while(s->left)
            {
              s=s->right;
            }
            int val=s->data;
            deleteNode(root,s->data);
            root->data=val;
            return root;
          }
        }
    }
    if(root->data>data)
    {
      root->left=deleteNode(root->left,data);
    }
    else
    {
      root->right=deleteNode(root->right,data);
    }
    return root;
}

int main()
{
  BST<int>* root;
  int data;
  root=inputBST();
  cout<<"Enter node to be deleted:";
  cin>>data;
  root=deleteNode(root,data);
  cout<<"Node deleted:";
  printLevelWise(root);
  return 0;
}
