/*
 * A self defined stack, use vector as inner container.
 *
 * Notice the const usage:
 *
 * - const member function can not modify the member variable.
 * - const object can not call a non-const member function.
 * */
#include <vector>
#include <stdexcept>    // for std::out_of_range
namespace bdgong 
{
template <typename T>
class Stack
{
    private:
        std::vector<T> v;
    public:
        /*
         * Push element to stack.
         * */
        void push(const T& elem)
        {
            v.push_back(elem);
        }

        /*
         * Return the top element on stack.
         * */
        T& top()
        {
            if(v.empty()) {
                throw std::out_of_range("empty stack");
            }
            else {
                return v.back();
            }
        }

        /*
         * Pop the top element of stack.
         * */
        void pop()
        {
            if(v.empty()) {
                throw std::out_of_range("empty stack");
            }
            else {
                v.pop_back();
            }
        }

        /*
         * Return the size of stack.
         * */
        std::size_t size() const 
        {
            return v.size();
        }

        /*
         * Return true if stack is empty.  Otherwise return false.
         * */ 
        bool empty() const  // the const ?
        {
            return v.empty();
        }
};

}

