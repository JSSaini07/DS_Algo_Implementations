#include <iostream>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"

using namespace std;

/*
if root is included in the longest path, the diameter is longest path in left subtree+longest path in right subtree
+rootnode, now do the same of left subtree and right subtree and the answer is max of three.
-> root considered as a part of longest path
-> root->left considered as a part of longest path (root excluded) [max diameter in left subtree]
-> root->right considerd as a part of longest path (root excluded) [max diameter in right subtree]

The code can be optimised if each root returns two values, the max path in left subtree and max path in right subtree
of that node. Using this
                max left path of node = max(left child max left path,left child max right path)+1
                max right path of node = max(right child max left path,right child max right path)+1
returning this value we can find the diameter of any node by adding the two returned components plus 1.
Now return the maximum of all three.
*/

pair<int,int> findDiameter(BTree<int>* root)
{
    if(root==NULL)
    {
        return make_pair(-1,-1);
    }
    if(!(root->left||root->right))
    {
        return make_pair(0,0);
    }
    pair<int,int> leftD=findDiameter(root->left);
    pair<int,int> rightD=findDiameter(root->right);
    pair<int,int> treeD=make_pair(max(leftD.first,leftD.second)+1,max(rightD.first,rightD.second)+1);
    if(leftD.first+leftD.second>rightD.first+rightD.second)
    {
        if(leftD.first+leftD.second>treeD.first+treeD.second)
        {
            return leftD;
        }
        return treeD;
    }
    if(rightD.first+rightD.second>=leftD.first+leftD.second)
    {
        if(rightD.first+rightD.second>treeD.first+treeD.second)
        {
            return rightD;
        }
        return treeD;
    }
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    pair<int,int> r=findDiameter(root);
    cout<<"Diameter of tree:";
    cout<<r.first+r.second+1<<endl;
    return 0;
}
