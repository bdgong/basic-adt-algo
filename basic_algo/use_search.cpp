#include "search.hpp"

int main()
{
    int arr[] = {15,21,26,26,27,35,36,40,49,59,62,63,72,77,83,86,86,90,92,93};
    int len = sizeof(arr) / sizeof(int);
    PrintAll(arr, len);
    auto testSearch = [&](const int (*algo)(const int[],const int, const int), 
            const int elem, const char *msg) {
        std::cout << msg << std::endl;

        int pos = algo(arr, len, elem);
        if(pos == cNotFound) {
            std::cout << "not found: " << elem << std::endl;
        }
        else {
            std::cout << "element " << elem << " at: " << pos << std::endl;
        }
    };

    testSearch(BinarySearch, 77, "BinarySearch: ");
    testSearch(BinarySearch, 17, "BinarySearch: ");
    testSearch(BinarySearch, 21, "BinarySearch: ");
    return 0;
}
