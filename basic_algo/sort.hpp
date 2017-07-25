/*
 * Sort algorithms, use int type as example.
 *
 *  + 插入排序
 *
 *      - 直接插入排序
 *      - 其它插入排序
 *      - 希尔排序
 *
 *  + 基于交换的排序
 *
 *      - 冒泡排序
 *      - 快速排序
 *
 *  + 基于选择的排序
 *
 *      - 简单选择排序
 *      - 树形选择排序
 *      - 堆排序（筛选法）
 *
 *  + 归并排序
 *  + 基数排序，计数排序，桶排序
 * */
#include <iostream>
#include <stack>
#include <queue>
#include "print.hpp"

/*
 * Insert sort given arr from ~ to(exclusive).
 *
 *  - ascending
 * */
void InsertSort(int arr[], const int from, const int to)
{
    for (int i=from+1; i<to ; ++i) {
        int elem = arr[i];
        int k = i;
        while(k > from && elem < arr[k-1]) {
            arr[k] = arr[k-1];
            --k;
        }
        arr[k] = elem;
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
 * Bubble sort given arr from ~ to(exclusive).
 *
 *  - ascending
 * */
void BubbleSort(int arr[], const int from, const int to)
{
    for (int i=from+1; i<to ; ++i) {
        bool changed = false;
        for (int j=to-1; j>=i ; --j) {
            if(arr[j] < arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
                changed = true;
            }
            else {}
        }
        if(!changed) {
            //std::cout << "End bubble sort without change with loop=" << i << std::endl;
            break;
        }
        else {}
    }
}

/*
 * Select sort given arr from ~ to(exclusive).
 *
 *  - ascending
 * */
void SelectSort(int arr[], const int from, const int to)
{
    for(int i=from; i<to-1 ; ++i) {
        int minIndex = i;
        for(int j=i+1; j<to ; ++j) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(i != minIndex) {
            swap(&arr[i], &arr[minIndex]);
        }
        else {}
    }
}

/*
 * Quick sort partition.
 *
 * @return The mid position.
 * */
int QuickSortPartition(int arr[], const int from, const int to)
{
    int low = from, high = to - 1;
    int tmp = arr[low];
    while (low < high) {
        // from high to low, find an element less than tmp
        while(arr[high] >= tmp && high > low)
            --high;
        arr[low] = arr[high];
        // from low to hight, find an element bigger than tmp
        while(arr[low] <= tmp && low < high)
            ++low;
        arr[high] = arr[low];
    }   // while.  After this: low==high
    arr[low] = tmp;
    return low;
}

/*
 * Quick sort give arr from ~ to(exclusive) in recursive way.
 *
 *  - ascending
 * */
void QuickSort(int arr[], const int from, const int to)
{
    if(from < to) {
        int mid = QuickSortPartition(arr, from, to);
        QuickSort(arr, from, mid);
        QuickSort(arr, mid+1, to);
    }
}

/*
 * Quick sort give arr from ~ to(exclusive) in iteration way.
 *
 * Depends on stack(or queue).
 *
 *  - ascending
 * */
void QuickSortByIteration(int arr[], int const from, const int to)
{
    std::stack<std::pair<int, int>> sortStack;
    sortStack.push(std::make_pair(from, to));
    while(!sortStack.empty()) {
        auto pair = sortStack.top();
        sortStack.pop();

        int start = pair.first, end = pair.second;
        if(start < end) {
            int mid = QuickSortPartition(arr, start, end);

            sortStack.push(std::make_pair(start, mid));
            sortStack.push(std::make_pair(mid+1, end));
        }
        else {}
    }
}

/*
 * Sieve method for heap.
 *
 * @param arr The array
 * @param rootIndex The root index, start from 1
 * @param lastIndex The last index
 * */
void sieve(int arr[], const int rootIndex, const int lastIndex)
{
    bool hasFinished = false;
    int currRootIndex = rootIndex;
    int tmp = arr[currRootIndex];
    int lChildIndex = currRootIndex * 2;
    int rChildIndex = lChildIndex + 1;
    int minIndex;
    while (lChildIndex<=lastIndex && !hasFinished) {
        if(lChildIndex<lastIndex && arr[lChildIndex] > arr[rChildIndex]) {
            minIndex = rChildIndex;
        }
        else {
            minIndex = lChildIndex;
        }

        if(arr[minIndex] < tmp) {
            arr[currRootIndex] = arr[minIndex];
            currRootIndex = minIndex;
            lChildIndex = currRootIndex * 2;
            rChildIndex = lChildIndex + 1;
        }
        else {
            hasFinished = true;
        }
    }
    arr[currRootIndex] = tmp;
}

/*
 * Make heap start by from, end by to(inclusive).
 *
 *  堆是一个完全二叉树，对于有n个结点的完全二叉树，它的第一个非叶子结点在n/2处。
 *  叶子结点可看作是待筛选的堆，从下往上，即可完成建堆。
 * */
void HeapMake(int arr[], const int from, const int to)
{
    for(int i=to/2; i>=from ; --i)
        sieve(arr, i, to);
}

/*
 * Copy the heap sorted result arrCopy to original arr.
 * */
void HeapWrite(int arr[], const int from, const int to, int arrCopy[])
{
    for(int i=from; i<to ; ++i) {
        arr[i] = arrCopy[1];   // the arrCopy start from 1
        arrCopy[1] = arrCopy[to-i];
        sieve(arrCopy, 1, to-i-1);
    }
}

/*
 * Heap sort, from ~ to(exclusive).
 *
 *  - ascending
 * */
void HeapSort(int arr[], const int from, const int to)
{
    int len = to - from + 1;
    int *arrCopy = new int[len];        // leave arrCopy[0] unused
    for(int i=from; i<to; ++i) 
        arrCopy[i-from+1] = arr[i];

    HeapMake(arrCopy, 1, len-1);

    //std::cout << "=======\nHeap result: " << std::endl;
    //PrintAll(arrCopy, 1, len);
    //std::cout << "/=======" << std::endl;

    HeapWrite(arr, from, to, arrCopy);
    delete [] arrCopy;
}

/*
 * Merge from~mid, mid~to to array arr.  Element belong to [begin, end).
 * */
void Merge(int arr[], const int from, const int to, const int mid)
{
    int len = to - from;
    int *arrTmp;
    try {
        arrTmp = new int[len];
    } 
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
        return;
    }
    int iNext = 0, i1 = from, i2 = mid;
    while(i1 < mid && i2 < to) {
        if(arr[i1] <= arr[i2]) {
            arrTmp[iNext++] = arr[i1++];
        }
        else {
            arrTmp[iNext++] = arr[i2++];
        }
    }
    while(i1 < mid) {
        arrTmp[iNext++] = arr[i1++];
    }
    while(i2 < to) {
        arrTmp[iNext++] = arr[i2++];
    }
    for(i1 = from; i1<to ; ++i1)
        arr[i1] = arrTmp[i1-from];
    delete [] arrTmp;
}

/*
 * Merge sort given arr from ~ to(exclusive).
 *
 *  - ascending
 * */
void MergeSort(int arr[], const int from, const int to)
{
    if(from+1 < to) {   // since the end is exclusive, from+1 is VIP!!!
        int mid = (from + to) / 2;
        MergeSort(arr, from, mid);
        MergeSort(arr, mid, to);
        Merge(arr, from, to, mid);
    }
}

/*
 * Merge sort by iteration.
 *
 * Use two stack: the lookupStack loop up all possible partition,
 * the sortStack do sort operation.  Bottom->Top.
 * */
void MergeSortByIteration(int arr[], const int from, const int to)
{
    std::stack<std::pair<int, int>> sortStack, lookupStack;
    std::pair<int, int> firstPair = std::make_pair(from, to);
    sortStack.push(firstPair);
    lookupStack.push(firstPair);
    // look up every possible segment
    while(!lookupStack.empty()) {
        auto pair = lookupStack.top();
        lookupStack.pop();
        int low = pair.first, high = pair.second;
        if(low+1 < high) {
            int mid = (low + high) / 2;
            std::pair<int, int> lowPair = std::make_pair(low, mid);
            std::pair<int, int> highPair = std::make_pair(mid, high);
            sortStack.push(lowPair);
            sortStack.push(highPair);
            lookupStack.push(lowPair);
            lookupStack.push(highPair);
        }
        else {}
    }

    while(!sortStack.empty()) {
        auto pair = sortStack.top();
        sortStack.pop();
        int low = pair.first, high = pair.second;
        if(low+1 < high) {
            int mid = (low + high) / 2;
            Merge(arr, low, high, mid);
        }
    }
}

/*
 * Merge sort with one-one sub-array.
 * */
void MergeSortByIteration2(int arr[], const int from, const int to)
{
    int len = to - from; 
    int step = 1;
    int l, r, mid;
    while (step < len) {
        for(int i=from; i<=to-2*step ; i+=2*step) { // the loop end condition is reach r
            l = i, r = i+2*step, mid=(l+r) / 2;     // since end is exclusive, r should plus 1
            Merge(arr, l, r, mid);
        }
        if(l==from) { // merge the last segment
            Merge(arr, from, to, r);
        }
        else {}

        step *= 2;
    }
}

/*
 * Return a pair of min,max element of array arr in range from ~ to.
 * */
const std::pair<int, int> minmax(const int arr[], const int from, const int to)
{
    int iMin=from, iMax=from;
    for(int i=from; i<to ; ++i) {
        if(arr[i] < arr[iMin]) {
            iMin = i;
        }
        else if(arr[i] > arr[iMax]) {
            iMax = i;
        }
        else {}
    }
    return std::make_pair(arr[iMin], arr[iMax]);
}

/*
 * Counting sort given arr.
 *
 *  - ascending
 *  - assume arr contains positive number 
 * */
void CountSort(int arr[], const int from, const int to) 
{
    auto mm = minmax(arr, from, to);
    //std::cout << mm.first << " " << mm.second << std::endl;
    int k = mm.second - mm.first + 1;
    int len = to - from;
    int *arrCount = new int[k];
    int *arrCopy = new int[len];

    int i;
    for(i=0; i<k ; ++i)
        arrCount[i] = 0;
    for(i=from; i<to ; ++i)
        arrCount[arr[i] - mm.first] += 1;      // arrCount now contains the number of elements equal to i.
    for(i=1; i<k ; ++i)
        arrCount[i] += arrCount[i-1];          // arrCount now contains the number of elements less than or equal to i.
    for(i=to-1; i>=from ; --i) {
        arrCopy[arrCount[arr[i] - mm.first] - 1] = arr[i];
        arrCount[arr[i] - mm.first] -= 1;
    }

    //PrintAll(arrCopy, 0, len);
    for(i=0; i<len ; ++i)
        arr[from+i] = arrCopy[i];

    delete [] arrCount;
    delete [] arrCopy;
}

/*
 * Get max digits in array arr[from, to).
 *
 *  - assume elements are positive
 * */
const int maxDigits(const int arr[], const int from, const int to)
{
    int maxD = 0;
    for(int i=from; i<to ; ++i) {
        int elem = arr[i];
        int d = 0;
        while(elem > 0) {
            ++d;
            elem /= 10;
        }
        if(d > maxD) {
            maxD = d;
        }
        else {}
    }
    return maxD;
}

/*
 * Radix sort given array arr.
 *
 *  - ascending
 *  - element radix=10
 *  - assume arr contains positive number 
 * */
void RadixSort(int arr[], const int from, const int to)
{
    const int radix = 10;
    int d = maxDigits(arr, from, to);
    //std::cout << "maxDigits=" << d << std::endl;
    int divide = 1;
    std::queue<int> bucket[radix];
    for(int k=1; k<=d ; ++k, divide*=radix) {
        // arrange
        for(int i=from; i<to ; ++i) {
            int pos = (arr[i] / divide) % radix;     // find bucket position for this element
            bucket[pos].push(arr[i]);
        }
        // collect
        for(int next=from, i=0; i<radix ; ++i) {
            while(!bucket[i].empty()) {
                arr[next++] = bucket[i].front();
                bucket[i].pop();
            }
        }
        //PrintAll(arr, from, to);
    }
}

/*
 * Bucket sort given arry arr.
 *
 *  - ascending
 *  - assume arr contains positive number 
 * */
void BucketSort(int arr[], const int from, const int to)
{
    auto mm = minmax(arr, from, to);
    const int k = mm.second - mm.first + 1;
    std::vector<std::queue<int>> bucket;
    bucket.resize(k);
    for(int i=from; i<to ; ++i) {
        bucket[arr[i]-mm.first].push(arr[i]);
    }

    for(int i=0, next=from; i<k ; ++i) {
        while(!bucket[i].empty()) {
            arr[next++] = bucket[i].front();
            bucket[i].pop();
        }
    }
}

