#include <iostream>
#include "../../Queue/Queue Implementation/queue.h"

using namespace std;

BST<int>* insertData(BST<int>* root,int data)
{
    if(!root)
    {
        root=new BST<int>(data);
    }
    else
    if(root->data>data)
    {
        root->left=insertData(root->left,data);
    }
    else
    {
        root->right=insertData(root->right,data);
    }
    return root;
}

BST<int>* inputBST()
{
    BST<int>* root=NULL;
    int data;
    cout<<"Enter Data(-1 to terminate):";
    cin>>data;
    while(data!=-1)
    {
        root=insertData(root,data);
        cout<<"Enter Data(-1 to terminate):";
        cin>>data;
    }
    return root;
}

void printPreOrder(BST<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(BST<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPostOrder(BST<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

void printLevelWise(BST<int>* root)
{
    if(!root)
    {
	return;
    }
    Queue<BST<int>* > q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        BST<int>* currentNode=q.dequeue();
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
