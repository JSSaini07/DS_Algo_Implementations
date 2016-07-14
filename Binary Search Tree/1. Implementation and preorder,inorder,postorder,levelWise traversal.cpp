#include <iostream>
#include "./Implementation/BST.h"  // include the binary search tree node
#include "./Implementation/IO.h"     // include input/output functions created

using namespace std;


int main()
{
    // IO.h contains the logic for inputBST, printLevelWise, printPreOrder, printInOrder, printPostOrder
    BST<int>* root;
    root=inputBST();
    cout<<endl<<"LevelWise traversal:";
    printLevelWise(root);
    cout<<endl<<"PreOrder traversal:";
    printPreOrder(root);
    cout<<endl<<"InOrder traversal:";
    printInOrder(root);
    cout<<endl<<"PostOrder traversal:";
    printPostOrder(root);
    return 0;
}
