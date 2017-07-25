/*
 * A self defined queue, use deque as inner container.
 *
 *
 *
 * */
#include <stdexcept>
#include <deque>

namespace bdgong
{
    template<typename T>
    class Queue 
    {
        private:
            std::deque<T> v;
        public:
            std::size_t size() const 
            {
                return v.size();
            }

            bool empty() const
            {
                return v.empty();
            }

            void push(const T& elem)
            {
                v.push_back(elem);
            }

            void pop()
            {
                if(v.empty()) {
                    throw std::out_of_range("empty queue");
                }
                else {
                    v.pop_front(); 
                }
            }

            T& front()
            {
                if(v.empty()) {
                    throw std::out_of_range("empty queue");
                }
                else {
                    return v.front();
                }
            }

            T& back() 
            {
                if(v.empty()) {
                    throw std::out_of_range("empty queue");
                }
                else {
                    return v.back();
                }
            }
    };
}
