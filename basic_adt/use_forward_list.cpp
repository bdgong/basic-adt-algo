#include <iostream>
#include "ForwardList.hpp"

int main()
{
    using namespace std;
    using namespace bdgong;

    ForwardList<int> forwardList;

    forwardList.push_front(222);
    forwardList.push_front(233);
    forwardList.push_front(17);
    forwardList.push_front(77);     // 77, 17, 233, 222

    cout << "size: " << forwardList.size() << endl;
    forwardList.pop_front();        // 17, 233, 222
    cout << forwardList.front() << endl;

    if(forwardList.remove(233)) {   // 17, 222
        cout << "removed 233." << endl;
    }
    else {
        cout << "233 not found" << endl;
    }

    forwardList.reverse();

    cout << "size: " << forwardList.size() << endl;

    forwardList.insert_after(0, 5);
    forwardList.insert_after(0, 1);

    forwardList.erase_after(1);

    return 0;
}

