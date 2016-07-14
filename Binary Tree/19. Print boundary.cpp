#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

void printLeft(BTree<int>* root)
{
    if(root==NULL||(!(root->left||root->right)))
    {
        return;
    }
    cout<<root->data<<" ";
    printLeft(root->left);
}

void printLeaf(BTree<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    if(!(root->left||root->right))
    {
        cout<<root->data<<" ";
    }
    printLeaf(root->left);
    printLeaf(root->right);
}

void printRight(BTree<int>* root)
{
    if(root==NULL||(!(root->left||root->right)))
    {
        return;
    }
    printLeft(root->right);
    cout<<root->data<<" ";
}

int printBoundary(BTree<int>* root)
{
    printLeft(root);
    printLeaf(root);
    printRight(root->right);
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    printBoundary(root);
    return 0;
}
