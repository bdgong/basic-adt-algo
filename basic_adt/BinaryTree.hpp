/*
 * Binary tree.
 * */

#include <iostream>
#include <stack>
#include <queue>
#include <memory>

namespace bdgong {
template <typename T>
class CBinaryTree 
{
    public: 
        typedef struct node {
            T data; 
            struct node *lChild, *rChild;
        }Node;

        typedef enum {L, R} CHILD;
        
        CBinaryTree() : root(nullptr) {
        }

        ~CBinaryTree() {
            clear();
        }

        /*
         * Create a binary tree, call recursive.
         *
         * */
        void create() {
            createNode(&root);
        }

        /*
         * Delete all nodes.
         * */
        void clear() {
            if(root != nullptr) {
                deleteChild(root, L);
                deleteChild(root, R);
                std::cout << "deleting " << root->data << std::endl;
                delete root;
                root = nullptr;
            }
            else {}
        }

        /*
         * Delete given node's given child.
         * */
        void deleteChild(Node *parent, CHILD child) {
            if(parent == nullptr) {
                return;
            }

            if(child == L && parent->lChild != nullptr) {
                deleteChild(parent->lChild, L);
                deleteChild(parent->lChild, R);
                std::cout << "deleting " << parent->lChild->data << std::endl;
                delete parent->lChild;
                parent->lChild = nullptr;
            }
            else if(child == R && parent->rChild != nullptr) {
                deleteChild(parent->rChild, L);
                deleteChild(parent->rChild, R);
                std::cout << "deleting " << parent->rChild->data << std::endl;
                delete parent->rChild;
                parent->rChild = nullptr;
            }
            else {}
        }

        const Node * getRoot() const {
            return root;
        }

        /*
         * The depth of this binary tree.
         * */
        int getDepth() {
            return getDepth(root);
        }

        static void print(const T& elem) {
            std::cout << elem << " ";
        }

        /*
         * Traversal the tree in pre order.
         * */
        void preOrderTraversal(void (*visit)(const T& elem) = CBinaryTree::print) {
            // impl 1: recursive call
            //preOrderTraversal(root, visit);
            //
            // impl 2: use stack
            std::stack<Node*> visitStack;
            if(root != nullptr) {
                visitStack.push(root);
            }
            else {}
            while(!visitStack.empty()) {
                Node *node = visitStack.top();
                visit(node->data);
                visitStack.pop();
                if(node->rChild != nullptr) {
                    visitStack.push(node->rChild);
                }
                else {}
                if(node->lChild != nullptr) {
                    visitStack.push(node->lChild);
                }
                else {}
            }
        }
        /*
         * Traversal the tree in in order.
         * */
        void inOrderTraversal(void (*visit)(const T& elem) = CBinaryTree::print) {
            // impl 1: recursive call
            //inOrderTraversal(root, visit);
            //
            // impl 2: use stack
            // <Node to visit, shouldVisit>
            std::stack<std::pair<Node*, bool>> visitStack;
            if(root != nullptr) {
                visitStack.push(std::make_pair(root, false));
            }
            else {}
            while(!visitStack.empty()) {
                auto pair = visitStack.top();
                Node *node          = pair.first;
                bool shouldVisit    = pair.second;

                visitStack.pop();

                if(shouldVisit) {
                    visit(node->data);
                }
                else {
                    if(node->rChild != nullptr) {
                        visitStack.push(std::make_pair(node->rChild, false));
                    }
                    else {}
                    visitStack.push(std::make_pair(node, true));
                    if(node->lChild != nullptr) {
                        visitStack.push(std::make_pair(node->lChild, false));
                    }
                    else {}
                }
            }
        }
        /*
         * Traversal the tree in post order.
         * */
        void postOrderTraversal(void (*visit)(const T& elem) = CBinaryTree::print) {
            // impl 1: recursive call
            //postOrderTraversal(root, visit);
            //
            // impl 2: use stack
            // <Node to visit, shouldVisit>
            std::stack<std::pair<Node*, bool>> visitStack;
            if(root != nullptr) {
                visitStack.push(std::make_pair(root, false));
            }
            else {}
            while(!visitStack.empty()) {
                auto pair = visitStack.top();
                Node *node          = pair.first;
                bool shouldVisit    = pair.second;

                visitStack.pop();

                if(shouldVisit) {
                    visit(node->data);
                }
                else {
                    visitStack.push(std::make_pair(node, true));
                    if(node->rChild != nullptr) {
                        visitStack.push(std::make_pair(node->rChild, false));
                    }
                    else {}
                    if(node->lChild != nullptr) {
                        visitStack.push(std::make_pair(node->lChild, false));
                    }
                    else {}
                }
            }
        }

        /*
         * Traversal in BFS.
         * */
        void levelOrderTraversal(void (*visit)(const T& elem) = CBinaryTree::print) {
            std::queue<Node*> visitQueue;
            if(root != nullptr) {
                visitQueue.push(root);
            }
            else {}
            while(!visitQueue.empty()) {
                Node *node = visitQueue.front();
                visitQueue.pop();
                visit(node->data);

                if(node->lChild != nullptr) {
                    visitQueue.push(node->lChild);
                }
                else {}
                if(node->rChild != nullptr) {
                    visitQueue.push(node->rChild);
                }
                else {}
            }
        }

        /*
         * Traversal in DFS
         * */
        void branchOrderTraversal(void (*visit)(const T& elem) = CBinaryTree::print) {
            std::stack<Node*> visitStack;
            if(root != nullptr) {
                visitStack.push(root);
            }
            else {}
            while(!visitStack.empty()) {
                Node *node = visitStack.top();
                visitStack.pop();
                visit(node->data);

                if(node->rChild != nullptr) {
                    visitStack.push(node->rChild);
                }
                else {}
                if(node->lChild != nullptr) {
                    visitStack.push(node->lChild);
                }
                else {}
            }
        }
    private:
        void preOrderTraversal(Node *parent, void (*visit)(const T& elem)) {
            if(parent != nullptr) {
                visit(parent->data);
                preOrderTraversal(parent->lChild, visit);
                preOrderTraversal(parent->rChild, visit);
            }
            else {}
        }
        void inOrderTraversal(Node *parent, void (*visit)(const T& elem)) {
            if(parent != nullptr) {
                inOrderTraversal(parent->lChild, visit);
                visit(parent->data);
                inOrderTraversal(parent->rChild, visit);
            }
            else {}
        }
        void postOrderTraversal(Node *parent, void (*visit)(const T& elem)) {
            if(parent != nullptr) {
                postOrderTraversal(parent->lChild, visit);
                postOrderTraversal(parent->rChild, visit);
                visit(parent->data);
            }
            else {}
        }
        /*
         * Create given node.  Use standard input stream.
         * */
        void createNode(Node **node) {
            int elem, exists;

            std::cin >> elem >> exists;     // if exists not 1, neglect the inputed elem
            if(exists == 1) {
                *node = new Node;
                (*node)->data = elem;
                createNode(&(*node)->lChild);
                createNode(&(*node)->rChild);
            }
            else {
                *node = nullptr;
            }
        }

        /*
         * Get depth from given parent.
         * */
        int getDepth(Node *parent) {
            if(parent == nullptr) {
                return 0;
            }
            else {
                int lDepth = getDepth(parent->lChild);
                int rDepth = getDepth(parent->rChild);
                int depth = lDepth > rDepth ? lDepth : rDepth;
                return depth + 1;
            }
        }

        Node *root;
};
}
