# Implementations and modifications of some data structures and algorithms in C++

## Binary Heap

This is an implementation of an ordinary Binary Heap, using a dynamic array as underlying data structure. This Binary 
Heap has `ExtractMin(int)` method overload, which, if the heap contains n elements, will find ith minimum element with 
time complexity of `O(i*lgi)`. This is useful when `n >> i`.