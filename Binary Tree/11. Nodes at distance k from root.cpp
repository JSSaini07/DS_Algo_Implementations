#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

void printAtDistance(BTree<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(!k)
    {
        cout<<root->data<<" ";
        return;
    }
    printAtDistance(root->left,k-1);
    printAtDistance(root->right,k-1);
    return;
}

int main()
{
    BTree<int>* root;
    int k;
    root=inputLevelWise();
    cout<<"Enter the distance:";
    cin>>k;
    printAtDistance(root,k);
    return 0;
}
