#include "minHeap.h"
#include <vector>
#include <iostream>

// Sifts up the element at the given position
void minHeap::siftUp(int pos) {
    int parent = (pos - 1) / 2;
    int child = pos;

    while (child != 0 && heap[parent] > heap[child]) {
        // Swap child and parent
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = (parent - 1) / 2;
    }
}

// Sifts down the element at the given position
void minHeap::siftDown(int pos) {
    int parent = pos;
    // Get left and right children of the parent
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    int swap = -1;
    int temp;

    // Check left child
    if (leftChild < (int)heap.size() && heap[leftChild] < heap[parent])
        swap = leftChild;

    // Check right child
    if (rightChild < (int)heap.size() && heap[rightChild] < heap[parent]) {
        if (swap == -1)
            swap = rightChild;
        // Take the minimum
        else if (heap[rightChild] < heap[leftChild])
            swap = rightChild;
    }

    // No swap needed
    if (swap == -1)
        return;

    // Swap parent with the swap value
    temp = heap[parent];
    heap[parent] = heap[swap];
    heap[swap] = temp;
    siftDown(swap);
}

// Constructor that takes a vector of integers as input
minHeap::minHeap(vector<int> data) {
    // Clear heap
    heap.resize(0);

    // Fill vector
    for (int &i : data)
        heap.push_back(i);

    // Sift down all elements
    for (int i = heap.size() - 1; i >= 0; i--)
        siftDown(i);
}

// Inserts a value into the heap
void minHeap::insert(int value) {
    // Insert at the back of the vector
    heap.push_back(value);
    int position = heap.size() - 1;
    // Move the last element up
    siftUp(position);
}

// Removes and returns the minimum value from the heap
int minHeap::removeMin() {
    int temp;

    // Check if the heap is empty
    if (heap.empty())
        return -1;

    // Swap the head with the last element
    temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap[heap.size() - 1] = temp;
    heap.pop_back();
    siftDown(0);
    return temp;
}

int main()
{
    vector<int> input={1,2,3,4,5,11,12,13,14,15};
    vector<int> test={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    vector<int> heapTest;

    for (int i=9; i>0; i--) swap(input[i], input[rand()%i]);

    minHeap h(input);

    h.insert(6);
    h.insert(10);
    h.insert(7);
    h.insert(9);
    h.insert(8);

    for (int i=0; i<15; i++) heapTest.push_back(h.removeMin());

    //ASSERT_THAT(heapTest, ElementsAreArray(test));
    for (int i=0; i<15; i++)
    {
        if (heapTest[i] != test[i])
        {
            cout << "Mismatch in heapTest at position " << i << ": expected/correct value " << test[i] << ", actual value when testing " << heapTest[i] << ".\n";
            return 1;
        }
    }
    cout << "Passed" << endl;
    return 0;
}
