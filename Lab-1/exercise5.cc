#include <iostream>
#include <vector>
#include <cstdlib>      // std::rand
#include <algorithm>    // std::generate

template <typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last) {
    // Your implementation here!
}

/* Function Generator: Generates random integer in [1, 100] */
int randomNumber() {return (std::rand()%100 + 1); }

/* Helper Function Prototype */
void test(int size);

int main() {
    
}

/* Helper Function Definition */
void test(int size) {
    std::cout << "Size: " << size << std::endl;

    std::vector<int> v(size);

    std::generate(v.begin(), v.end(), randomNumber);
}
