#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

int convertToLeftSum(BTree<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(!(root->left||root->right))
    {
        return root->data;
    }
    int leftSum=convertToLeftSum(root->left);
    int rightSum=convertToLeftSum(root->right);
    root->data+=leftSum;
    return root->data+rightSum;
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    convertToLeftSum(root);
    cout<<"Modified Tree:";
    printLevelWise(root);
    return 0;
}
