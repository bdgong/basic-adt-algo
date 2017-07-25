#include "List.hpp"

int main()
{
    using namespace std;
    using namespace bdgong;

    List<int> numbers;

    numbers.push_front(1);
    numbers.push_front(3);
    numbers.push_front(5);
    numbers.push_back(9);
    numbers.push_front(7);
    numbers.push_front(11);

    cout << "front()    = " << numbers.front()  << endl;
    cout << "back()     = " << numbers.back()   << endl;

    cout << "size()     = " << numbers.size() << endl;

    while(!numbers.empty()) {
        cout << numbers.front() << " ";
        numbers.pop_front();
    }
    cout << endl;

    numbers.push_back(1994);
    numbers.push_back(1618);
    numbers.push_back(717);

    cout << "size()     = " << numbers.size() << endl;

    numbers.reverse();

    while(!numbers.empty()) {
        cout << numbers.back() << " ";
        numbers.pop_back();
    }
    cout << endl;

}
