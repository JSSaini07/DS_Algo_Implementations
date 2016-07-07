
#ifndef node_header // include guard to save from multiple includes of node.h
#define node_header

template <typename datatype>
class node {
public:
    datatype data;
    node* next;
    node(datatype data)
    {
        this->data=data;
        this->next=NULL;
    }
};

#endif
