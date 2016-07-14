
template <typename datatype>
class BST {
public:
    datatype data;
    BST<datatype>* left;
    BST<datatype>* right;
    BST(datatype data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
