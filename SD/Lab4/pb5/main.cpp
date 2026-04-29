#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class MinHeap {
private:
    vector<int> heap;
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[parent(index)]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    void heapifyDown(int index) {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    int top() {
        if (heap.empty()) {
            throw out_of_range("E gol");
        }
        return heap[0];
    }
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }
};