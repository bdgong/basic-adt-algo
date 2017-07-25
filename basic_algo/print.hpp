#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>

/*
 * Print all element of arr, from ~ to(exclusive).
 * */
template <typename T>
void PrintAll(T arr[], int from, int to)
{
    for (int i=from; i<to ; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

/*
 * Print all element of arr, 0 ~ end(exclusive).
 * */
template <typename T>
void PrintAll(T arr[], int end)
{
    PrintAll(arr, 0, end);
}

#endif /*print.hpp*/

