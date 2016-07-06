#include <iostream>
#include "node.h"

using namespace std;

// basic functions for creating and printing//
node<int>* createLinkedList()
{
    node<int>* head=NULL;
    node<int>* temp=NULL;
    int data;
    cout<<"Enter data(-1 to exit):";
    cin>>data;
    while(data!=-1)
    {
        if(head==NULL)
        {
            head=new node<int>(data);
            temp=head;
        }
        else
        {
            temp->next=new node<int>(data);
            temp=temp->next;
        }
        cout<<"Enter data(-1 to exit):";
        cin>>data;
    }
    return head;
}

void printLL(node<int>* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

bool detectLoop(node<int>* head)
{
    if(head->next==NULL)
    {
        return false;
    }
    node<int>* slow=head;
    node<int>* fast=head->next->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        if(slow==fast)
        {
            return true;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}

int main()
{
    node<int>* head=NULL;
    head=createLinkedList();
    cout<<"Original Linked List:";
    printLL(head);
    int r=detectLoop(head);
    if(r)
    {
        cout<<"Linked List contains a loop";
    }
    else
    {
        cout<<"Linked List does not contain loop";
    }
    /*
    //create loop
    head->next=head;
    r=detectLoop(head);
    if(r)
    {
        cout<<"Linked List contains a loop";
    }
    else
    {
        cout<<"Linked List does not contain loop";
    }*/
    return 0;
}
