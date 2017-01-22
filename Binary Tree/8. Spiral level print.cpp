#include <iostream>
#include <vector>
#include "./Implementation/BTree.h"
#include "./Implementation/IO.h"
#include "../Stack/Stack Implementation/stack.h"

using namespace std;

void spiralLevelPrint(BTree<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    Stack<BTree<int>* > s1;
    Stack<BTree<int>* > s2;
    int leftToRight=1;
    s1.push(root);
    while(!s1.isEmpty()||!s2.isEmpty())
    {
        if(leftToRight)
        {
            while(!s1.isEmpty())
            {
                BTree<int>* currentNode=s1.pop();
                cout<<currentNode->data<<" ";
                if(currentNode->left)
                {
                    s2.push(currentNode->left);
                }
                if(currentNode->right)
                {
                    s2.push(currentNode->right);
                }
            }
        }
        else
        {
            while(!s2.isEmpty())
            {
                BTree<int>* currentNode=s2.pop();
                cout<<currentNode->data<<" ";
                if(currentNode->right)
                {
                    s1.push(currentNode->right);
                }
                if(currentNode->left)
                {
                    s1.push(currentNode->left);
                }
            }
        }
        leftToRight=!leftToRight;
    }
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    spiralLevelPrint(root);
    return 0;
}
