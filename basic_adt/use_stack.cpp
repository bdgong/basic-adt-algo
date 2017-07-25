#include "Stack.hpp"
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    using namespace bdgong;

    Stack<string> names;


    /// Exception test
    
    try {
        string topElem = names.top();
        cout << topElem << endl;
    }
    //catch (std::out_of_range oor) {
        //cout << "Error: " << oor.what() << endl;
    //}
    catch (...) {
        cout << "something error happened." << endl;
    }

    /// push and size, top test

    names.push("bdg");
    cout << "size: " << names.size() << endl;
    cout << "top:  " << names.top()  << endl;

    /// more push test

    names.push("buxi");
    names.push("buxixi");
    names.push("xiaohai");
    cout << "size: " << names.size() << endl;
    cout << "top:  " << names.top()  << endl;

    /// Pop test

    names.pop();
    cout << "names.pop() top: " << names.top() << endl;
    names.pop();
    cout << "names.pop() top: " << names.top() << endl;

    names.push(string("mingchen"));

    /// Empty test

    cout << "Now all of them: " << endl;
    while(!names.empty()) {
        cout << names.top() << " ";
        names.pop();
    }
    cout << endl;

    cout << "size: " << names.size() << endl;
    return 0;
}
