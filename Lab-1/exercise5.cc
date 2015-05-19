#include <iostream>
#include <vector>
#include <cstdlib>      // std::rand
#include <algorithm>    // std::generate
#include <iterator>     // std::ostream_iterator

template <typename BidirectionalIterator>
void my_reverse(BidirectionalIterator first, BidirectionalIterator last) {
    // Your implementation here!
}

/* Function Generator: Generates random integer in [1, 100] */
int randomNumber() {return (std::rand()%100 + 1); }

/* Helper Function Prototype */
void test(int size);

int main() {
    int testSize[] = {20, 17, 0, 1};

    for (size_t i = 0; i < (sizeof(testSize)/sizeof(*testSize)); i++) {
        test(testSize[i]);
        std::cout << std::endl;
    }
}

/* Helper Function Definition */
void test(int size) {
    std::cout << "Size: " << size << std::endl;

    /* Declare the vector */
    std::vector<int> v(size);

    /* Populate vector with random integers */
    std::generate(v.begin(), v.end(), randomNumber);

    /* Print to the console */
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    /* Reverse the vector */
    my_reverse(v.begin(), v.end());

    /* Print to the console */
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
