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
    Queue<BTree<int>* > q;
    Stack<BTree<int>* > s;
    cout<<root->data<<" ";
    if(root->left)
    {
        q.enqueue(root->left);
    }
    if(root->right)
    {
        q.enqueue(root->right);
    }
    BTree<int>* currentNode;
    while(!q.isEmpty()||!s.isEmpty())
    {
        while(!q.isEmpty())
        {
            currentNode=q.dequeue();
            cout<<currentNode->data<<" ";
            if(currentNode->left)
            {
                s.push(currentNode->left);
            }
            if(currentNode->right)
            {
                s.push(currentNode->right);
            }
        }
        while(!s.isEmpty())
        {
            currentNode=s.pop();
            cout<<currentNode->data<<" ";
            if(currentNode->left)
            {
                q.enqueue(currentNode->left);
            }
            if(currentNode->right)
            {
                q.enqueue(currentNode->right);
            }
        }
    }
}

int main()
{
    BTree<int>* root;
    root=inputLevelWise();
    spiralLevelPrint(root);
    return 0;
}
