/*
 * Binary tree and basic operations.
 *
 * !g++ % -o %< -std=c++11 -g 
 * !./%< < tree.dat
 * */
#include "BinaryTree.hpp"

int main()
{
    using namespace std;
    using namespace bdgong;

    CBinaryTree<int> bt;
    bt.create();
    
    cout << "Current depth = " << bt.getDepth() << endl;

    cout << "Traversal by pre order: \n";
    bt.preOrderTraversal();
    cout << endl;

    cout << "Traversal by in order: \n";
    bt.inOrderTraversal();
    cout << endl;

    cout << "Traversal by post order: \n";
    bt.postOrderTraversal();
    cout << endl;

    cout << "Traversal by level order: \n";
    bt.levelOrderTraversal();
    cout << endl;

    cout << "Traversal by branch order: \n";
    bt.branchOrderTraversal();
    cout << endl;

    const CBinaryTree<int>::Node * rootNode = bt.getRoot();
    cout << "Root element = " << rootNode->data << endl;
    cout << "Root left child element = " << rootNode->lChild->data << endl;
    cout << "Root right child element = " << rootNode->rChild->data << endl;

    cout << "Current depth = " << bt.getDepth() << endl;

    return 0;
}
