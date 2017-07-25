#include "sort.hpp"
#include "print.hpp"

int main()
{
    int arr[] = {1,7,5,-1994, 7,9,2,3};
    int arr2[] = {1,5,7,9};
    int arr3[] = {20,1};
    int arr4[] = {36, 72, 26, 40, 26, 63, 59, 90, 27, 62, 21, 49, 92, 86, 35, 93, 15, 77, 86, 83};
    int len = sizeof(arr) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    int len3 = sizeof(arr3) / sizeof(int);
    int len4 = sizeof(arr4) / sizeof(int);

    PrintAll(arr, len); 
    PrintAll(arr2, len2); 
    PrintAll(arr3, len3); 
    PrintAll(arr4, len4); 

    /// test sort algorithm
    auto testSortAlgorithm = [&](void (*algo)(int[],int,int), const char *msg) {
        std::cout << msg << std::endl;

        algo(arr, 2, len);
        PrintAll(arr, 0, len); 
        algo(arr2, 0, len2);
        PrintAll(arr2, len2); 
        algo(arr3, 0, len3);
        PrintAll(arr3, len3); 
        algo(arr4, 0, len4);
        PrintAll(arr4, len4); 
    };
    auto testSpecialSortAlgo = [&](void (*algo)(int[],int,int), const char *msg) {
        std::cout << msg << std::endl;

        algo(arr4, 0, len4);
        PrintAll(arr4, len4); 
    };

    /// test insert sort
    //testSortAlgorithm(InsertSort, "InsertSort: ");

    /// test bubble sort
    //testSortAlgorithm(BubbleSort, "BubbleSort: ");

    /// test select sort
    //testSortAlgorithm(SelectSort, "SelectSort: ");

    /// test quick sort
    //testSortAlgorithm(QuickSort, "QuickSort: ");
    /// test quick sort by iteration
    //testSortAlgorithm(QuickSortByIteration, "QuickSortByIteration: ");

    /// test heap sort
    //testSortAlgorithm(HeapSort, "HeapSort: ");

    /// test merge sort
    //testSortAlgorithm(MergeSort, "MergeSort: ");
    //testSortAlgorithm(MergeSortByIteration, "MergeSortByIteration: ");
    //testSortAlgorithm(MergeSortByIteration2, "MergeSortByIteration2: ");

    /// test count sort
    //testSpecialSortAlgo(CountSort, "CountSort: ");
    
    /// test radix sort
    testSpecialSortAlgo(RadixSort, "RadixSort: ");
    
    return 0;
}

