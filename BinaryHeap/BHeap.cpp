#include "BHeap.h"
#include <iostream>
#include <unordered_map>

int BHeap::Size() {
    return heap.size();
}
void BHeap::Insert(int ele) {
    heap.push_back(ele);
    heapifyup(heap.size() -1);
}
void BHeap::DeleteMin() {
    if (heap.size() == 0) {
        std::cout << "Heap is Empty" << std::endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
}

int BHeap::ExtractMin() {
    if (heap.size() == 0) {
        return -1;
    }
    else
        return heap.front();
}

// I know the code is hard to read, but this was written in haste as a proof of concept.
int BHeap::ExtractMin(int i) {
    if (i > this->Size() || i < 0) {
        std::cout << "Invalid parameter" << std::endl;
        return -1;
    }

    BHeap aux;
    // Ideally would have this class as a template and the aux heap element type will be pair.
    // Bypass it like this ))
    std::unordered_map<int, int> elementToIdx;
    aux.Insert(this->ExtractMin());
    int n = 1;
    elementToIdx.insert(std::pair<int, int>(this->ExtractMin(), 0));
    while (n < i) {
        int p = aux.ExtractMin();
        int pIdx = elementToIdx.at(p);
        aux.DeleteMin();
        if (this->l(pIdx) < this->Size()) {
            int elemIdx = this->l(pIdx);
            int elem = this->heap[elemIdx];
            elementToIdx.insert({elem, elemIdx});
            aux.Insert(elem);
        }
        if (this->r(pIdx) < this->Size()) {
            int elemIdx = this->r(pIdx);
            int elem = this->heap[elemIdx];
            elementToIdx.insert({elem, elemIdx});
            aux.Insert(elem);
        }
        ++n;
    }
    return aux.ExtractMin();
}

void BHeap::showHeap() {
    std::vector <int>::iterator pos = heap.begin();
    std::cout << "Heap --> ";
    while (pos != heap.end()) {
        std::cout << *pos << " ";
        pos++;
    }
    std::cout << std::endl;
}
int BHeap::l(int parent) {
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}
int BHeap::r(int parent) {
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}
int BHeap::par(int child) {
    int p = (child - 1)/2;
    if (child == 0)
        return -1;
    else
        return p;
}
void BHeap::heapifyup(int in) {
    if (in >= 0 && par(in) >= 0 && heap[par(in)] > heap[in]) {
        int temp = heap[in];
        heap[in] = heap[par(in)];
        heap[par(in)] = temp;
        heapifyup(par(in));
    }
}
void BHeap::heapifydown(int in) {
    int child = l(in);
    int child1 = r(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
        child = child1;
    }
    if (child > 0 && heap[in] > heap[child]) {
        int t = heap[in];
        heap[in] = heap[child];
        heap[child] = t;
        heapifydown(child);
    }
}