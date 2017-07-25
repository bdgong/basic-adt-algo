/**
 * A self defined forward list.
 *
 *   - size()
 *   - empty()
 *   - front()
 *   - push_front()
 *   - pop_front()
 *   - insert_after()
 *   - erase_after()
 *   - clear()
 *   - remove()
 *   - reverse()
 *   - find()
 *
 * */
#include <stdexcept>
#include <iostream>

namespace bdgong
{
    const static char* const ErrorEmptyList = "empty list";
    const static char* const ErrorOutOfRange = "out of range";

    template <typename T>
    class ForwardList
    {
        private:
            typedef struct node {
                T data;
                struct node *next;
            }Node;

            Node *head;
            std::size_t __size;

        public:
            ForwardList() : head(nullptr), __size(0) {
            }

            ~ForwardList() {
                clear();
            }

            std::size_t size() const {
                return __size;
            }

            bool empty() const {
                return __size <= 0;
            }

            T& front() {
                if(empty()) {
                    throw std::out_of_range(ErrorEmptyList);
                }
                else {
                    return head->data;
                }
            }

            void push_front(const T& elem) {
                // push the first element
                if(head == nullptr) {
                    head = new Node;
                    head->data = elem;
                    head->next = nullptr;
                }
                else {
                    Node *node = new Node;
                    node->data = elem;
                    node->next = head;
                    head = node;
                }

                ++__size;
            }

            T pop_front() {
                if(empty()) {
                    throw std::out_of_range(ErrorEmptyList);
                }
                else {
                    Node *pn = head;
                    T elem = pn->data;
                    head = head->next;

                    delete pn;
                    --__size;

                    return elem;
                }
            }

            void clear() {
                Node *t = head;
                while(head != nullptr) {
                    head = head->next;
                    std::cout << "deleting element " << --__size << " : " << t->data << std::endl;
                    delete t;
                    t = head;
                }
            }

            const bool remove(const T& elem) {
                if(empty()) {
                    throw std::out_of_range(ErrorEmptyList);
                }
                else {
                    if(head->data == elem) {
                        // if remove head elem
                        delete head;
                        head = nullptr;
                        --__size;
                        
                        return true;
                    }
                    else {
                        // not remove the head elem
                        Node *pn = head->next, *pbefore = head;
                        while(pn->data != elem && pn != nullptr) {
                            pn = pn->next;
                            pbefore = pbefore->next;
                        }

                        if(pn != nullptr) {
                            // found the element to remove
                            pbefore->next = pn->next;
                            delete pn;
                            --__size;

                            return true;
                        }
                        else {
                        }
                    }
                }

                return false;
            }

            void reverse() {
                if(head == nullptr || head->next == nullptr) {
                    return;
                }

                Node *pre = head; 
                Node *p = head->next;
                Node *next;
                pre->next = nullptr;
                while(p != nullptr) {
                    next = p->next;

                    p->next = pre;
                    pre     = p;
                    p = next;
                }

                head = pre;
            }

            /*
             * @param pos The insert position, can be 0 ~ size(), exclusive.
             * @param elem The element to insert.
             * */
            void insert_after(std::size_t pos, const T& elem)
            {
                if(pos >= __size) {
                    throw std::out_of_range(ErrorOutOfRange);
                }

                // find the position to insert 
                Node *p = head, *pre;
                for (int i=0 ; i <= pos ; ++i){
                    pre = p;
                    p   = p->next;
                }

                if(p == head) {
                    // insert at front
                    push_front(elem);
                }
                else {
                    Node *node = new Node;
                    node->data = elem;
                    node->next = p;

                    pre->next = node;
                    ++__size;
                }
            }

            void erase_after(std::size_t pos)
            {
                if(pos >= __size - 1) {
                    throw std::out_of_range(ErrorOutOfRange);
                }

                Node *p = head, *pre;
                for (int i=0; i<= pos; ++i) {
                    pre = p;
                    p   = p->next;
                }

                if(p == head) {
                    pop_front();
                }
                else {
                    pre->next = p->next;
                    delete p;

                    --__size;
                }
            }

            int find(const T& elem)
            {
                return -1;
            }
    };
}

