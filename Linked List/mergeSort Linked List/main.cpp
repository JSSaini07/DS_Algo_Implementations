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

// merge sort logic

node<int>* mergeLL(node<int>* head1,node<int>* head2)
{
    node<int>* head=NULL;
    node<int>* temp=NULL;
    if(head1->data<head2->data)
    {
        head=new node<int>(head1->data);
        head1=head1->next;
    }
    else
    {
        head=new node<int>(head2->data);
        head2=head2->next;
    }
    temp=head;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            temp->next=new node<int>(head1->data);
            head1=head1->next;
        }
        else
        {
            temp->next=new node<int>(head2->data);
            head2=head2->next;
        }
        temp=temp->next;
    }
    while(head1!=NULL)
    {
        temp->next=new node<int>(head1->data);
        head1=head1->next;
        temp=temp->next;
    }
    while(head2!=NULL)
    {
        temp->next=new node<int>(head2->data);
        head2=head2->next;
        temp=temp->next;
    }
    return head;
}

node<int>* mergeSort(node<int>* head)
{
    if(head->next==NULL)
    {
        return head;
    }
    node<int>* head1=head;
    node<int>* head2=NULL;
    node<int>* mid=head;
    node<int>* fastPointer=head;
    while(fastPointer->next!=NULL&&fastPointer->next->next!=NULL)
    {
        mid=mid->next;
        fastPointer=fastPointer->next->next;
    }
    head2=mid->next;
    mid->next=NULL;
    head1=mergeSort(head1);
    head2=mergeSort(head2);
    return mergeLL(head1,head2);
}

int main()
{
    node<int>* head=NULL;
    head=createLinkedList();
    cout<<"Original Linked List:";
    printLL(head);
    head=mergeSort(head);
    cout<<"Linked List After Merge Sort:";
    printLL(head);
    return 0;
}
