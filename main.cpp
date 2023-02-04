#include "BHeap/BHeap.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;
void shuffle_vector(std::vector<int>& vec) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(vec.begin(), vec.end(), generator);
}

int main() {
    BHeap h;

    int num;
    int i;
    std::cout << "Enter n to construct a heap containing 1-n elements\n";
    std::cin >> num;
    std::cout << "Which min element you want to find?\n";
    std::cin >> i;

    std::vector<int> vec(num);
    for (int j = 0; j < num; ++j) {
        vec[j] = j;
    }
    shuffle_vector(vec);
    for (auto n : vec) {
        h.Insert(n);
    }

    std::cout << i << " min element is " << h.ExtractMin(i);

    return 0;
}
