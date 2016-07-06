#include "node.h"

template <typename datatype>
class Queue {
node<datatype>* first;
node<datatype>* last;
int size;
public:
    Queue()
    {
        first=NULL;
        last=NULL;
        size=0;
    }
    void enqueue(datatype data)
    {
        if(first==NULL)
        {
            first=new node<datatype>(data);
            last=first;
        }
        else
        {
            last->next=new node<datatype>(data);
            last=last->next;
        }
        size++;
    }
    datatype dequeue()
    {
        if(first!=NULL)
        {
            datatype r=first->data;
            first=first->next;
            size--;
            return r;
        }
    }
    datatype front()
    {
        if(first!=NULL)
        {
            return first->data;
        }
    }
    int queueSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return !size;
    }
};

