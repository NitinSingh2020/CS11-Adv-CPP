#include <iostream>
#include <vector>
#include <algorithm>       // std::copy
#include <iterator>        // std::ostream_iterator
#include <ext/functional>  // __gnu_cxx::compose1


/*
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

   std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;
}
