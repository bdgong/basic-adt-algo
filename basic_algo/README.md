## Basic Algorithms

- Sorting
- Searching

### Sorting 

按平均时间

1. 简单排序，O(n^2)：插入排序，选择排序，冒泡排序
2. 线性对数阶排序，O(nlgn)：快速排序，堆排序，归并排序，但是快速排序最坏情况下为O(n^2)
3. O(n^(1+x))排序：希尔排序(x为介于0～1之间的常数)
4. 线性阶排序：基数排序，计数排序，桶排序

按稳定性

1. 稳定的排序算法：插入，冒泡，归并，基数排序，计数排序，桶排序
2. 不稳定的排序算法：选择，快速，堆，希尔排序

> Notice: 
> 
> 1. 简单排序算法中，直接插入最好，快速排序平均性能最好；当待排序数为正序时，直接插入和冒泡均最佳。
> 2. 当待排序的N个关键字随机分布时，任何借助于“比较”的排序算法，至少需要O(nlgn)的时间。

### Searching

