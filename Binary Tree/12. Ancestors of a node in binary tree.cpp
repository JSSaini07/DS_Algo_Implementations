#include <iostream>
#include <vector>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

vector<int> ancestors;

void printAncestors(BTree<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==k)
    {
        cout<<"Ancestors are:";
        for(int i=0;i<ancestors.size();i++)
        {
            cout<<ancestors[i]<<" ";
        }
        cout<<endl;
        return;
    }
    ancestors.push_back(root->data);
    printAncestors(root->left,k);
    printAncestors(root->right,k);
    ancestors.pop_back();
    return;
}

int main()
{
    BTree<int>* root;
    int k;
    root=inputLevelWise();
    cout<<"Enter node value:";
    cin>>k;
    printAncestors(root,k);
    return 0;
}
