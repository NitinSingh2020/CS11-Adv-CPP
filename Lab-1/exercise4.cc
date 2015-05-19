#include <ext/functional>  // __gnu_cxx::compose1
#include <iostream>
#include <vector>
#include <algorithm>       // std::copy
#include <iterator>        // std::ostream_iterator

/* 
* 1) Function to remove the even elements from the array
* 2) Its broken because when printing it iterates to the end of the vector
* 3) While retrieving the altered vector iterate till the new_end iterator
*/

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::vector<int>::iterator new_end =
        remove_if(v.begin(), v.end(),
            __gnu_cxx::compose1(bind2nd(std::equal_to<int>(), 0),
                bind2nd(std::modulus<int>(), 2)));

    /* Buggy Code */
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    /* Intended Code */
    for (std::vector<int>::iterator it = v.begin(); it != new_end; ++it) {
        std::cout << *it;
        std::cout << " ";
    }
    std::cout << std::endl;
}
