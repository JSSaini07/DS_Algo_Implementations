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
    if(((!root1)&&root2)||(root1&&(!root2)))
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    bool leftSubtreeStatus=checkIdentical(root1->left,root2->left);
    bool rightSubtreeStatus=checkIdentical(root1->right,root2->right);
    return (leftSubtreeStatus&&rightSubtreeStatus);
}

bool checkSubtree(BTree<int>* root1,BTree<int>* root2)
{
    if(!(root1||root2))
    {
        return true;
    }
    if(((!root1)&&root2)||(root1&&(!root2)))
    {
        return false;
    }
    if(root1->data==root2->data)
    {
        return checkIdentical(root1,root2);
    }
    return(checkSubtree(root1->left,root2)||checkSubtree(root1->right,root2));
}

int main()
{
    BTree<int>* root1;
    BTree<int>* root2;
    cout<<"Enter main tree"<<endl;
    root1=inputLevelWise();
    cout<<"Enter sub tree"<<endl;
    root2=inputLevelWise();
    bool r=checkSubtree(root1,root2);
    if(r)
    {
        cout<<"Given tree is a subtree of main tree"<<endl;
    }
    else
    {
        cout<<"Given tree is not a subtree of main tree"<<endl;
    }
    return 0;
}
