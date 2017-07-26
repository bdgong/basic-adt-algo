#include "sort.hpp"

const int cNotFound = -1;

/*
 * Binary search element elem in array arr[0, len).
 *
 * - arr be sorted in ascending order
 *
 * @return The position of target elem in arr, if not found, -1 is returned.
 * */
const int BinarySearch(const int arr[], const int len, const int elem) 
{
    int low = 0, high = len-1, mid = (low + high) / 2;
    while(low < high && elem != arr[mid]) {
        if(arr[mid] > elem) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
        mid = (low + high) / 2;
    }

    if(elem == arr[mid]) {
        return mid;
    }
    else {
        return cNotFound;
    }
}

