#include <iostream>
#include "./Implementation/BST.h"
#include "./Implementation/IO.h"
#include "../Stack/Stack Implementation/stack.h"

using namespace std;

void printInorderIterative(BST<int>* root)
{
    Stack<BST<int>* > s;
    BST<int>* currentNode=root;
    int r=1;
    while(r)
    {
        if(currentNode)
        {
            s.push(currentNode);
            currentNode=currentNode->left;
        }
        else
        {
          if(!s.isEmpty())
          {
            currentNode=s.pop();
            cout<<currentNode->data<<" ";
            currentNode=currentNode->right;
          }
          else
          {
            r=0;
          }
        }
    }
}


int main()
{
  BST<int>* root;
  root=inputBST();
  printInorderIterative(root);
  return 0;
}
