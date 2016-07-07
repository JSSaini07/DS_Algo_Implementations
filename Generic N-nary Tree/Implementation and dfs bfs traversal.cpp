#include <iostream>
#include "treeNode.h"
#include "../Queue/Queue Implementation/queue.h"

using namespace std;

treeNode<int>* input()
{
    int data,numChild;
    cout<<"Enter node value:";
    cin>>data;
    treeNode<int>* root=new treeNode<int>(data);
    cout<<"Enter the number of children for node "<<root->data<<":";
    cin>>numChild;
    for(int i=0;i<numChild;i++)
    {
        cout<<"for child "<<i+1<<" of "<<root->data<<endl;
        treeNode<int>* childNode=input();
        (root->children).push_back(childNode);
    }
    return root;
}

void print(treeNode<int>* root)
{
    cout<<root->data<<" ";
    for(int i=0;i<(root->children).size();i++)
    {
        print((root->children)[i]);
    }
}

treeNode<int>* inputLevelWise()
{
    Queue<treeNode<int>* > q;
    int data,numChild;
    cout<<"Enter node value:";
    cin>>data;
    treeNode<int>* root=new treeNode<int>(data);
    q.enqueue(root);
    while(!q.isEmpty())
    {
        treeNode<int>* currentNode=q.dequeue();
        cout<<"Enter number of children for node "<<currentNode->data<<":";
        cin>>numChild;
        for(int i=0;i<numChild;i++)
        {
            cout<<"Enter node value for node"<<currentNode->data<<" child "<<i+1<<":";
            cin>>data;
            treeNode<int>* childNode=new treeNode<int>(data);
            (currentNode->children).push_back(childNode);
            q.enqueue(childNode);
        }
    }
    return root;
}

void printLevelWise(treeNode<int>* root)
{
    Queue<treeNode<int>* > q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        treeNode<int>* currentNode=q.dequeue();
        cout<<currentNode->data<<" ";
        for(int i=0;i<(currentNode->children).size();i++)
        {
            q.enqueue((currentNode->children)[i]);
        }
    }
}

int main()
{
    treeNode<int>* root;
    root=input();
    print(root);
    //root=inputLevelWise();
    //printLevelWise(root);
    return 0;
}
