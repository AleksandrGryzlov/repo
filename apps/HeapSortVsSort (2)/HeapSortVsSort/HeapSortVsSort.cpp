#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// implementation of heapsort function

template <typename T>
void heapsort(std::vector<T>& arr) {
    // create a heap from the vector
    std::make_heap(arr.begin(), arr.end());

    // repeatedly extract the maximum element from the heap and put it at the end of the vector
    for (int i = arr.size() - 1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        std::make_heap(arr.begin(), arr.begin() + i);
    }
}

// function to generate a random vector of integers

std::vector<int> generate_random_vector(int size) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand();
    }
    return vec;
}

// test the heapsort and std::sort functions using randomly generated vectors of various sizes

int main() {
    std::vector<int> sizes = { 100, 500, 1000, 5000, 10000, 100000, 500000 };

    for (int size : sizes) {
        std::vector<int> vec1 = generate_random_vector(size);
        std::vector<int> vec2 = vec1;

        // test heapsort
        auto start1 = std::chrono::high_resolution_clock::now();
        heapsort(vec1);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);

        // test std::sort
        auto start2 = std::chrono::high_resolution_clock::now();
        std::sort(vec2.begin(), vec2.end());
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);

        std::cout << "Sorting " << size << " integers using heapsort took " << duration1.count() << " milliseconds." << std::endl;
        std::cout << "Sorting " << size << " integers using std::sort took " << duration2.count() << " milliseconds." << std::endl;
    }

    return 0;
}
