/*
 * A self defined double-linked list. 
 *
 *  - size()
 *  - empty()
 *  - front()
 *  - push_front()
 *  - pop_front()
 *  - back()
 *  - push_back()
 *  - pop_back()
 *  - clear()
 *  - remove()
 *  - reverse()
 * */
#include <stdexcept>
#include <iostream>

namespace bdgong
{
    const static char * const ErrorEmptyList = "empty list";
    template <typename T>
    class List
    {
        private:
            typedef struct node {
                struct node *prev;
                T data;
                struct node *next;
            }Node;

            Node *head;
            Node *tail;
            std::size_t _size;
        public:
            List() : head(nullptr), tail(nullptr), _size(0) {
            }
            ~List() {
                std::cout << "destructor called." << std::endl;
                clear();
            }

            const std::size_t size() const {
                return _size;
            }

            const bool empty() const {
                return _size <= 0;
            }

            void clear() {
                if(empty()) {
                    return;
                }

                Node *pn = head;
                tail->next = nullptr;       // notice: this is VIP
                while(head != nullptr) {
                    head = head->next;

                    std::cout << "deleting " << pn->data << std::endl;
                    pn->prev = nullptr;
                    pn->next = nullptr;
                    delete pn;
                    pn = nullptr;
                    --_size;

                    pn = head;
                }
            }

            T& front() {
                if(empty()) {
                    throw std::out_of_range(ErrorEmptyList);
                }
                else {
                    return head->data;
                }
            }

            T& back() {
                if(empty()) {
                    throw std::out_of_range(ErrorEmptyList);
                }
                else {
                    return tail->data;
                }
            }

            void push_front(const T& elem) {
                if(head == nullptr) {
                    // push the first element
                    head = new Node;
                    head->data = elem;
                    head->prev = tail;
                    head->next = tail;

                    tail = head;
                }
                else {
                    // insert into first location
                    Node *node = new Node;
                    node->data = elem;

                    node->next = head;
                    node->prev = tail;

                    if(tail != nullptr) {
                        tail->next = node;
                    }

                    head->prev = node;
                    head = node;
                }
                ++_size; 
            }

            void push_back(const T& elem) {
                if(tail == nullptr) {
                    // push the first element
                    tail = new Node;
                    tail->data = elem;
                    tail->prev = head;
                    tail->next = head;

                    head = tail;
                }
                else {
                    // append to last position
                    Node *node = new Node;
                    node->data = elem;

                    node->next = head;
                    node->prev = tail;
                    head->prev = node;
                    tail->next = node;

                    tail = node;
                }
                ++_size;
            }

            void pop_front() { 
                if(empty()) {
                    return;
                }

                Node *p = head;
                //T elem = p->data;

                if(head->next == nullptr) {
                    // there is only one node remain
                }
                else if(head->next == tail) {
                    // there are two nodes remain
                    tail->prev = nullptr;
                    tail->next = nullptr;
                    head = tail;
                }
                else {
                    // there are three or more nodes remain
                    head = head->next; 
                    head->prev = tail; 
                    tail->next = head; 
                }

                p->prev = nullptr;
                p->next = nullptr;
                delete p;
                p = nullptr;
                --_size;
            }

            void pop_back() {
                if(empty()) {
                    return;
                }

                Node *p = tail;
                tail->prev->next = tail->next;
                tail->next->prev = tail->prev;
                tail = tail->prev;

                p->prev = nullptr;
                p->next = nullptr;
                delete p;
                p = nullptr;
                --_size;
            }

            void reverse() {
                if(head == nullptr || head->next == nullptr) {
                    return;
                }

                Node *pre = head;
                Node *p = head->next;
                Node *next;
                while(p != head) {
                    next = p->next;

                    p->next = pre;
                    p->prev = next;

                    pre = p;
                    p = next;
                }
                // now pre=tail,p==head, but prev,next not setted
                head->prev = head->next;

                head = pre;
                head->prev = p;
                tail = p;
                tail->next = head;
            }
    };
}
