#include <iostream>
#include <vector>
#include <cstdlib>      // std::rand
#include <algorithm>    // std::generate
#include <iterator>     // std::ostream_iterator
#include <cstring>      // std::string

/* Function Generator to generate random numbers between 5 and 15 */
int randomNumber() {
    return (std::rand()%11 + 5);
}

/* Function Generator to generate random string of length between 5 and 15 */
std::string randomAlphaString() {
    // Generate number in the range 5 and 15 inclusive
    int wordLength = randomNumber();

    const std::string alphabets = "abcdefghijklmnopqrstuvwxyz";
    std::string s(wordLength, 'x');

    for (int i = 0; i < wordLength; ++i) {
        s[i] = alphabets[rand() % 26];
    }

    s[wordLength] = 0;
    return s;
}
/* Comparator conforming to the Strict Weak Ordering model. */
bool sortByStringLength(std::string a, std::string b) {
    return (a.length() < b.length());
}

int main() {
    std::vector<std::string> values(100);

    std::generate(values.begin(), values.end(), randomAlphaString);

    /* Sort the vector lexically */
    std::sort(values.begin(), values.end());

    /* Display the vector delimited by comma */
    std::copy(values.begin(), values.end(),
        std::ostream_iterator<std::string>(std::cout, ", "));

    std::cout << "\n\n\n\n" << std::endl;

    /* Sort Vector by length */
    std::sort(values.begin(), values.end(), sortByStringLength);

    /* Display the vector delimited by comma */
    std::copy(values.begin(), values.end(),
        std::ostream_iterator<std::string>(std::cout, ", "));
}
