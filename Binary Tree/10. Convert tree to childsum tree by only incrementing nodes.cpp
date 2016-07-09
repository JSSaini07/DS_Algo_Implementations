#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

void convertChildSum(BTree<int>* root)
{
    if(root==NULL||(root->left==NULL&&root->right==NULL))
    {
        return;
    }
    convertChildSum(root->left);
    convertChildSum(root->right);
    if(root->data>(root->left->data)+(root->right->data))
    {
        root->left->data=(root->data)-(root->right->data);
    }
    else
    if(root->data<(root->left->data)+(root->right->data))
    {
        root->data=(root->left->data)+(root->right->data);
    }
    root->data=(root->left->data)+(root->right->data);
    return;
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    convertChildSum(root);
    cout<<"Converted tree to follow child sum property:";
    printLevelWise(root);
    return 0;
}
