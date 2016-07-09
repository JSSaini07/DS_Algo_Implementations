#include <iostream>
#include <vector>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

int currentSum=0;
int currentNode=0;

int maxRootToLeafSum(BTree<int>* root)
{
    if(root==NULL)
    {
        return currentSum;
    }
    currentSum+=root->data;
    currentNode=root->data;
    int leftSum=maxRootToLeafSum(root->left);
    int rightSum=maxRootToLeafSum(root->right);
    currentSum-=currentNode;
    return max(leftSum,rightSum);
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    int r=maxRootToLeafSum(root);
    cout<<"Max root to leaf sum:"<<r;
    return 0;
}
