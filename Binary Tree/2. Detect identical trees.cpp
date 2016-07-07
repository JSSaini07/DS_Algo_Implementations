#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

bool checkIdentical(BTree<int>* root1,BTree<int>* root2)
{
    if(!(root1||root2))
    {
        return true;
    }
    if((!(root1&&root2))||root1->data!=root2->data)
    {
        return false;
    }
    bool leftSubTreeStatus=checkIdentical(root1->left,root2->left);
    bool rightSubTreeStatus=checkIdentical(root1->right,root2->right);
    return (leftSubTreeStatus&&rightSubTreeStatus);
}

int main()
{
    BTree<int>* root1=inputLevelWise();
    BTree<int>* root2=inputLevelWise();
    bool r=checkIdentical(root1,root2);
    if(r)
    {
        cout<<"Trees identical";
    }
    else
    {
        cout<<"Trees not identical";
    }
    return 0;
}
