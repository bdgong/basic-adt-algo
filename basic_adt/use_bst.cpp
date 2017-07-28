#include "BinarySearchTree.hpp"

int main()
{
    using namespace bdgong;
    using namespace std;
    CBinarySearchTree<int> bst;

    bst.insert(19);
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(11);
    bst.insert(2);
    bst.insert(13);
    bst.insert(17);
    bst.insert(97);

    cout << "Pre order traversal:" << endl;
    bst.preOrderTraversal();
    cout << endl;

    cout << "In order traversal:" << endl;
    bst.inOrderTraversal();
    cout << endl;

    cout << "Post order traversal:" << endl;
    bst.postOrderTraversal();
    cout << endl;

    cout << "Find 17: ";
    cout << (bst.find(17) ? "YES." : "NO.") << endl; 
    cout << "Find 77: ";
    cout << (bst.find(77) ? "YES." : "NO.") << endl; 

    cout << "Delete 17:";
    cout << (bst.remove(17) ? "Removed." : "Not exists.") << endl; 

    cout << "Delete 11:";
    cout << (bst.remove(11) ? "Removed." : "Not exists.") << endl; 

    cout << "Delete 5:";
    cout << (bst.remove(5) ? "Removed." : "Not exists.") << endl; 

    cout << endl;

    return 0;
}

