#include <iostream>
#include <vector>
#include <cstdlib>      // std::rand
#include <algorithm>    // std::generate
#include <iterator>     // std::ostream_iterator
#include <functional>   // std::unary_function

/* Function Generator
 * Generates random integer in [1, 100]
 */
int randomNumber() {return (std::rand()%100 + 1); }

/* Function Object implementing the unary_function model
 * Counts and maintain the even and odd number in the array
 */
struct countEvenOdd : public std::unary_function<int, void> {
    int evenCount;
    int oddCount;
    countEvenOdd() : evenCount(0), oddCount(0) {}
    void operator()(int x) {
        if (x % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
};

int main() {
    std::vector<int> values(100);

    std::generate(values.begin(), values.end(), randomNumber);

    /* Uncomment the below block if want to print the integers
    std::copy(values.begin(), values.end(),
        std::ostream_iterator<int>(std::cout, ", "));
    */

    countEvenOdd result = for_each(values.begin(), values.end(), countEvenOdd());

    std::cout << "Number of Even Integers is " << result.evenCount << std::endl;
    std::cout << "Number of Odd Integers is " << result.oddCount << std::endl;
}
