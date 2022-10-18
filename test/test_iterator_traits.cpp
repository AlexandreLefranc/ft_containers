#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) {
        typename std::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}

int main()
{
	int a[] = {1, 2, 3, 4, 5};
    std::vector<int> v(a, a + 5);
    my_reverse(v.begin(), v.end());
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::list<int> l(a, a + 5);
    my_reverse(l.begin(), l.end());
    for (int n : l) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    my_reverse(a, a + std::size(a));
    for (int n : a) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

//    std::istreambuf_iterator<char> i1(std::cin), i2;
//    my_reverse(i1, i2); // compilation error

}