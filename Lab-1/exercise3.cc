#include <iostream>
#include <vector>
#include <cstdlib>      // std::rand
#include <algorithm>    // std::generate
#include <iterator>     // std::ostream_iterator

/* Function Generator
 * Generates random integer in [1, 100] */
int randomNumber() {return (std::rand()%100 + 1); }

int main() {
    std::vector<int> values(100);

    std::generate(values.begin(), values.end(), randomNumber);

    std::copy(values.begin(), values.end(),
        std::ostream_iterator<int>(std::cout, ", "));
}
