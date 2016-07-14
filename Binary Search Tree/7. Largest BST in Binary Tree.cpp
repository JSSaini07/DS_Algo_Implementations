#include <iostream>
#include "../Binary Tree/Implementation/BTree.h"
#include "../Binary Tree/Implementation/IO.h"

using namespace std;

pair<BTree<int>*,int> searchBST(BTree<int>* root)
{
    if(!root||(!(root->left||root->right)))
    {
      return make_pair(root,1);
    }
    pair<BTree<int>*,int> maxLeft=searchBST(root->left);
    pair<BTree<int>*,int> maxRight=searchBST(root->right);
    if(root->left==maxLeft.first&&root->right==maxRight.first&&root->data>maxLeft.first->data&&root->data<maxRight.first->data)
    {
      return make_pair(root,1+maxLeft.second+maxRight.second);
    }
    else
    {
        if(maxLeft.second>maxRight.second)
        {
          return maxLeft;
        }
        return maxRight;
    }
}


int main()
{
  BTree<int>* root;
  pair<BTree<int>*,int> r;
  root=inputLevelWise();
  r=searchBST(root);
  printLevelWise(r.first);
  return 0;
}
