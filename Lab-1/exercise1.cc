#include <iostream>
#include <vector>
#include <cstdlib>      // std::rand
#include <algorithm>    // std::generate
#include <iterator>     // std::ostream_iterator

/* Function Generator */
int randomNumber() {return (std::rand()%100 + 1); }

int main() {
    std::vector<int> values(100);

    std::generate(values.begin(), values.end(), randomNumber);

    std::copy(values.begin(), values.end(),
        std::ostream_iterator<int>(std::cout, ", "));

    // int i = 0;
    // std::cout << "myvector contains:" << std::endl;
    // for (std::vector<int>::iterator it = values.begin(); it != values.end(); ++it) {
    //     std::cout << "Vector[" << i << "] = " << *it << std::endl;
    //     i++;
    // }
}
