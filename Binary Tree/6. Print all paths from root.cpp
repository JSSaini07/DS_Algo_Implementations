#include <iostream>
#include <vector>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

vector<int> v;

void printPaths(BTree<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        v.push_back(root->data);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        v.pop_back();
        return;
    }
    v.push_back(root->data);
    printPaths(root->left);
    printPaths(root->right);
    v.pop_back();
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    printPaths(root);
    return 0;
}
