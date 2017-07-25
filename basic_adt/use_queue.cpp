#include "Queue.hpp"
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    using namespace bdgong;

    Queue<string> words;

    words.push("To");
    words.push("see");
    words.push("a");
    words.push("world");
    words.push("in");
    words.push("a");
    words.push("grain");
    words.push("of");
    words.push("sand");
    words.push(".");
    words.push("oops");

    words.push(",");
    words.push(" and");

    while(!words.empty()) {
        cout << words.front() << " ";
        words.pop();
    }
    cout << endl;

    try {
        words.pop(); 
    }
    catch (...) {
        cout << "no elements exists any more." << endl;
    }

    return 0;
}
