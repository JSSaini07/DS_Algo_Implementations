#include <iostream>
#include <vector>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

bool checkChildSum(BTree<int>* root)
{
    if(root==NULL||!(root->left||root->right))
    {
        return true;
    }
    if(root->left&&!root->right&&root->data==root->left->data)
    {
        return true;
    }
    if(!root->left&&root->right&&root->data==root->right->data)
    {
        return true;
    }
    if(root->data!=(root->left->data)+(root->right->data))
    {
        return false;
    }
    bool leftSubTreeStatus=checkChildSum(root->left);
    bool rightSubTreeStatus=checkChildSum(root->right);
    return (leftSubTreeStatus&&rightSubTreeStatus);
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    bool r=checkChildSum(root);
    if(r)
    {
        cout<<"Property is followed";
    }
    else
    {
        cout<<"Property not followed";
    }
    return 0;
}
