#include <iostream>
#include <vector>


std::vector<std::vector<int>> *mat_multiply(std::vector<std::vector<int>> &mat1, std::vector<std::vector<int>> &mat2) {
    return new std::vector<std::vector<int>>({
                                                     {
                                                             mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0],
                                                             mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]
                                                     },
                                                     {
                                                             mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0],
                                                             mat1[0][1] * mat2[0][1] + mat1[1][1] * mat2[1][1]
                                                     }
                                             });
}

std::vector<std::vector<int>> *mat_power(std::vector<std::vector<int>> &mat, int pow) {
    if (pow == 1) {
        return &mat;
    }
    if ((pow & 1) == 0) {
        return mat_power(*mat_multiply(mat, mat), pow / 2);
    } else {
        return mat_multiply(mat, *mat_power(*mat_multiply(mat, mat), pow / 2));
    }
}

// Nth number is equal to the [0][1]th element of this matrix mat^n.
// Calculate nth fibonacci number in O(log(n)).
int nth_fibonacci(int n) {
    std::vector<std::vector<int>> mat{
            {1, 1},
            {1, 0},
    };

    return (*mat_power(mat, n))[0][1];
}

int main() {
    int n;
    std::cout << "Enter 'n' to calculate nth Fibonacci number (n>0): ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Incorrect number\n";
        return -1;
    }
    std::cout << std::endl << "fibonacci(" << n << ") = " << nth_fibonacci(n);

    return 0;
}
