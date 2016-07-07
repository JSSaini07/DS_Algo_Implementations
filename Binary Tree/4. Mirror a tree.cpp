#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

BTree<int>* mirrorTree(BTree<int>* root)
{
    if(!root)
    {
        return NULL;
    }
    BTree<int>* mirroredLeftSubtree=mirrorTree(root->left);
    BTree<int>* mirroredRightSubtree=mirrorTree(root->right);
    root->left=mirroredRightSubtree;
    root->right=mirroredLeftSubtree;
    return root;
}

int main()
{
    BTree<int>* root=inputLevelWise();
    cout<<"Original tree:";
    printLevelWise(root);
    root=mirrorTree(root);
    cout<<endl<<"Mirror tree:";
    printLevelWise(root);
    return 0;
}
