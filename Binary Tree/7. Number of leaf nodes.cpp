#include <iostream>
#include <vector>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

int numLeafNodes(BTree<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    int numLeafNodesLeftSubtree=numLeafNodes(root->left);
    int numLeafNodesRightSubtree=numLeafNodes(root->right);
    return (numLeafNodesLeftSubtree+numLeafNodesRightSubtree);
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    int r=numLeafNodes(root);
    cout<<"Number of leaf nodes:"<<r;
    return 0;
}
