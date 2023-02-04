#include <vector>

class BHeap {
private:
    std::vector<int> heap;
    int l(int parent);
    int r(int parent);
    int par(int child);
    void heapifyup(int index);
    void heapifydown(int index);
public:
    BHeap() {}
    void Insert(int element);
    void DeleteMin();
    int ExtractMin();
    void showHeap();
    int Size();
    int ExtractMin(int i);
};