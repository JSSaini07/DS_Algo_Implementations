#include <iostream>
#include "../../Queue/Queue Implementation/queue.h"

using namespace std;

BTree<int>* inputLevelWise()
{
    Queue<BTree<int>* > q;
    BTree<int>* root=NULL;
    int data;
    cout<<"Enter node value(-1 for NULL):";
    cin>>data;
    if(data==-1)
    {
	return root;
    }
    root=new BTree<int>(data);
    q.enqueue(root);
    while(!q.isEmpty())
    {
        BTree<int>* currentNode=q.dequeue();
        BTree<int>* leftChild=NULL;
        BTree<int>* rightChild=NULL;
        cout<<"Enter node "<<currentNode->data<<" left child(-1 for NULL):";
        cin>>data;
        if(data!=-1)
        {
            leftChild=new BTree<int>(data);
            q.enqueue(leftChild);
        }
        cout<<"Enter node "<<currentNode->data<<" right child(-1 for NULL):";
        cin>>data;
        if(data!=-1)
        {
            rightChild=new BTree<int>(data);
            q.enqueue(rightChild);
        }
        currentNode->left=leftChild;
        currentNode->right=rightChild;
    }
    return root;
}

void printPreOrder(BTree<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(BTree<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPostOrder(BTree<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

void printLevelWise(BTree<int>* root)
{
    if(!root)
    {
	return;
    }
    Queue<BTree<int>* > q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        BTree<int>* currentNode=q.dequeue();
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
