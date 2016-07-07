#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

int preorder[100000];
int inorder[100000];

int findIndex(int value,int x,int y)
{
    for(int i=x;i<=y;i++)
    {
        if(inorder[i]==value)
        {
            return i;
        }
    }
    return -1;
}

BTree<int>* createTree(int x1,int y1,int x2,int y2)
{
    if(x1>y1||x2>y2)
    {
        return NULL;
    }
    int rootValue=preorder[x1];
    BTree<int>* root=new BTree<int>(rootValue);
    int rootIndexInInorder=findIndex(rootValue,x2,y2);
    root->left=createTree(x1+1,x1+rootIndexInInorder-x2,x2,rootIndexInInorder-1);
    root->right=createTree(x1+rootIndexInInorder-x2+1,y1,rootIndexInInorder+1,y2);
    return root;
}

int main()
{
    BTree<int>* root;
    int n;
    cout<<"Enter number of tree nodes:";
    cin>>n;
    cout<<"Enter preorder traversal:";
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    cout<<"Enter inorder traversal:";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    root=createTree(0,n-1,0,n-1);
    cout<<"Constructed tree:";
    printLevelWise(root);
    return 0;
}
