#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"
#include <map>

using namespace std;

map <int,int> width;

void maxWidth(BTree<int>* root,int k,int& r)
{
  if(!root)
  {
    return;
  }
  width[k]++;
  r=max(r,width[k]);
  if(!(root->left||root->right))
  {
    return;
  }
  maxWidth(root->left,k+1,r);
  maxWidth(root->right,k+1,r);
  return;
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    int r=0;
    maxWidth(root,0,r);
    cout<<"Maximum width of tree:";
    cout<<r<<endl;
    return 0;
}
