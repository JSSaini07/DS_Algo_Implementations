#include <iostream>
#include "./Implementation/BTree.h"  // include the binary tree node 
#include "./Implementation/IO.h"     // include input/output functions created

using namespace std;


int main()
{
    // IO.h contains the logic for inputLevelWise, printLevelWise, printPreOrder, printInOrder, printPostOrder
    BTree<int>* root;
    root=inputLevelWise();
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
