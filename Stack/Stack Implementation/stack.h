#include "../../Linked List/Implementation/node.h"

template <typename datatype>
class Stack {
node<datatype>* first;
int size;
public:
    Stack()
    {
        first=NULL;
        size=0;
    }
    void push(datatype data)
    {
        node<datatype>* newNode=new node<datatype>(data);
        newNode->next=first;
        first=newNode;
        size++;
    }
    datatype pop()
    {
        if(first!=NULL)
        {
            datatype r=first->data;
            first=first->next;
            size--;
            return r;
        }
    }
    datatype top()
    {
        if(first!=NULL)
        {
            return first->data;
        }
    }
    int stackSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return !size;
    }
};

