
template <typename datatype>
class BTree {
public:
    datatype data;
    BTree<datatype>* left;
    BTree<datatype>* right;
    BTree(datatype data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
