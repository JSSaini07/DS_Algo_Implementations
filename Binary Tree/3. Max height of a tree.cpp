#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

int maxTreeHeight(BTree<int>* root)
{
    if(!root)
    {
        return 0;
    }
    int lefSubTreeHeight=maxTreeHeight(root->left);
    int rightSubTreeHeight=maxTreeHeight(root->right);
    return (1+max(lefSubTreeHeight,rightSubTreeHeight));
}

int main()
{
    BTree<int>* root=inputLevelWise();
    int r=maxTreeHeight(root);
    cout<<"Max tree height:"<<r;
    return 0;
}
