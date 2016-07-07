

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


