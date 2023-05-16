# DSA-Lab-8

Exercise:

A binary heap is represented using a complete binary tree. A complete binary tree is a binary tree in which all the nodes at each level are completely 
filled except for the leaf nodes and the nodes are as far as left.

While representing a heap as an array, assuming the index starts at 0, the root element is stored at 0. In general, if a parent node is at the position i, 
then the left child node is at the position (2*i + 1) and the right node is at (2*i + 2).

Implement Heapsort by creating max-heap in C++. Use the given “heap.cpp” file for your implementation.

  * In the given program, the function heapify() is used to convert the elements into a heap using recursion.
  * The function heapSort() sorts the array elements using heap sort. It starts from the nonleaf nodes and calls the heapify() on each of them. 
    This converts the array into a binary max heap.
  * The main() function only shows an example of a given set of numbers. Modify it to read numbers from the user or assign random values.
