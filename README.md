# Min Heap Implementation

This repository contains a C++ implementation of a Min Heap data structure. The code demonstrates the basic operations such as insertion, removal, and sifting up and down to maintain the min heap property.

## Usage

1. Clone the repository.
2. Compile the `main.cpp` file.
3. Run the compiled binary.

## Functions

The following functions are implemented in the `minHeap` class:

- `siftUp(int pos)`: Sifts up the element at the given position.
- `siftDown(int pos)`: Sifts down the element at the given position.
- `minHeap(vector<int> data)`: Constructor that takes a vector of integers as input and creates a min heap.
- `insert(int value)`: Inserts a value into the heap.
- `removeMin()`: Removes and returns the minimum value from the heap.

## Example

The `main()` function demonstrates the usage of the min heap by creating an instance of the `minHeap` class with an input vector of integers, inserting additional elements into the heap, and removing the minimum values one by one.

```cpp
vector<int> input = {1, 2, 3, 4, 5, 11, 12, 13, 14, 15};
vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
vector<int> heapTest;

minHeap h(input);

h.insert(6);
h.insert(10);
h.insert(7);
h.insert(9);
h.insert(8);

```
The test checks whether the removed minimum values match the expected results.
