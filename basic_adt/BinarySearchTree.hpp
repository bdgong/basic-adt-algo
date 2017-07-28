/*
 * Notice:
 *
 * Since the inner node is pointer type, the pointer-to-pointer type must be used
 * for delete and insert operation.
 * */
#include <iostream>
#include "util.hpp"

namespace bdgong
{
    template <typename T>
    class CBinarySearchTree
    {
        public:
            typedef struct node {
                T val;
                struct node *lChild, *rChild;
            }Node, *PNode;

            CBinarySearchTree() 
                : root(nullptr)
            {
            }

            ~CBinarySearchTree() {
                clear(root);
            }

            void clear() {
                clear(root);
            }

            void clear(Node *node) {
                if(node != nullptr) {
                    if(node->lChild != nullptr) {
                        clear(node->lChild);
                    }
                    else {}
                    if(node->rChild != nullptr) {
                        clear(node->rChild);
                    }
                    else {}
                    node->lChild = nullptr;
                    node->rChild = nullptr;
                    std::cout << "Deleting " << node->val << std::endl;
                    delete node;
                    node = nullptr;
                }
                else {}
            }

            /*
             * The insert element must be the leaf node, why?
             * */
            const bool insert(const T &elem) {
                return insert(&root, elem);
            }

            /*
             * Find given element, if found, return the node, otherwise, nullptr is
             * returned.
             * */
            const PNode * find(const T &elem) const {
                return search(&root, elem);
            }

            /*
             * Remove given element.  If remove success, return true, otherwise return
             * false.
             * */
            bool remove(const T &elem) {
                PNode *node = const_cast<PNode*>(find(elem));
                if(node == nullptr) {
                    return false;
                }
                else {
                    return removeNode(node);
                }
            }

            void preOrderTraversal() {
                preOrderTraversal(root, print);
            }

            void inOrderTraversal() {
                inOrderTraversal(root, print);
            }

            void postOrderTraversal() {
                postOrderTraversal(root, print);
            }

        private:
            CBinarySearchTree(const CBinarySearchTree&);
            CBinarySearchTree & operator=(const CBinarySearchTree&);

            const bool insert(PNode *parent, const T &elem) {
                Node *node = new Node;
                node->val = elem;
                node->lChild = nullptr;
                node->rChild = nullptr;
                if(*parent == nullptr) {
                    *parent = node;
                    return true;
                }
                else {
                    // can not have repeat element
                    if((*parent)->val == elem) {
                        return false;
                    }
                    else if((*parent)->val < elem) {
                        insert(&(*parent)->rChild, elem);
                    }
                    else {
                        insert(&(*parent)->lChild, elem);
                    }
                }
            }

            const PNode * search(const PNode *parent, const T &elem) const {
                if(*parent == nullptr) {
                    return nullptr;
                }
                else if((*parent)->val == elem) {
                    return parent;
                }
                else if((*parent)->val > elem) {
                    return search(&(*parent)->lChild, elem);
                }
                else {
                    return search(&(*parent)->rChild, elem);
                }
            }

            bool removeNode(PNode *pNode) {
                if((*pNode)->lChild == nullptr && (*pNode)->rChild == nullptr) {  // 左右孩子均空
                    delete *pNode;
                    *pNode = nullptr;
                }
                else if((*pNode)->rChild == nullptr) {   // 左孩子不空
                    PNode p = *pNode;
                    *pNode = (*pNode)->lChild;
                    delete p;
                }
                else if((*pNode)->lChild == nullptr) {   // 右孩子不空
                    PNode p = *pNode;
                    *pNode = (*pNode)->rChild;
                    delete p;
                }
                else {  // 左右孩子均不空，将前面一个元素移动到当前位置，重接被移动元素左（右）孩子
                    PNode p = *pNode;
                    PNode t = p->lChild;
                    while(t->rChild != nullptr) {
                        p = t;
                        t = t->rChild;
                    }   // 找到刚好比待删除元素小的结点
                    (*pNode)->val = t->val;
                    if(p == *pNode) {    // 重接左子树
                        p->lChild = t->lChild;
                    }
                    else {              // 重接右子树
                        p->rChild = t->lChild;
                    }
                    delete t;
                    t = nullptr;
                }
                return true; 
            }

            void preOrderTraversal(Node *node, void (*visit)(const T&)) {
                if(node != nullptr)  {
                    visit(node->val);
                    preOrderTraversal(node->lChild, visit);
                    preOrderTraversal(node->rChild, visit);
                }
            }

            void inOrderTraversal(Node *node, void (*visit)(const T&)) {
                if(node != nullptr)  {
                    inOrderTraversal(node->lChild, visit);
                    visit(node->val);
                    inOrderTraversal(node->rChild, visit);
                }
            }

            void postOrderTraversal(Node *node, void (*visit)(const T&)) {
                if(node != nullptr)  {
                    postOrderTraversal(node->lChild, visit);
                    postOrderTraversal(node->rChild, visit);
                    visit(node->val);
                }
            }

            Node *root;
    };
}

