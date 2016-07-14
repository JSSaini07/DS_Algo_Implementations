#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

int findLCA(BTree<int>* root,int x,int y,int k,int& maxk,int& r)
{
    if(root==NULL)
    {
        return 0;
    }
    int a=findLCA(root->left,x,y,k+1,maxk,r);
    int b=findLCA(root->right,x,y,k+1,maxk,r);
    int c=((root->data==x)||(root->data==y));
    if(a+b+c==2&&k>=maxk)
    {
        maxk=k;
        r=root->data;
    }
    return (a+b+c);
}

int main()
{
    BTree<int>* root;
    int x,y;
    int r=0;
    int maxk=0;
    root=inputLevelWise();
    cout<<"Enter the nodes:";
    cin>>x>>y;
    findLCA(root,x,y,0,maxk,r);
    cout<<"Lowest common ancestor ofthe two nodes is:";
    cout<<r<<endl; 
    return 0;
}
