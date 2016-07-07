#include <vector>

using namespace std;

template <typename datatype>
class treeNode {
public:
    datatype data;
    vector<treeNode<datatype>* > children;
    treeNode(datatype data)
    {
        this->data=data;
    }
};
