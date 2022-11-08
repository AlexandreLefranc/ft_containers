/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.test.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:08:59 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/08 18:07:42 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#ifdef FT
	#include "iterator_traits.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	#include <iterator>
	namespace ns = std;
#endif

static void	print_title(const std::string& title)
{
	std::cout << std::endl;
	std::cout << "=============================================================\n";
	std::cout << title << std::endl;
	std::cout << "=============================================================\n";
	std::cout << std::endl;
}

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
	typename ns::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
	for (--n; n > 0; n -= 2) {
		typename ns::iterator_traits<BidirIt>::value_type tmp = *first;
		*first++ = *--last;
		*last = tmp;
	}
}

static void	test_cppreference()
{
	print_title("ITERATOR_TRAITS - CPPREFERENCE");
	
	int a[] = {1, 2, 3, 4, 5};
	my_reverse(a, a + 5);
	for (size_t i = 0; i < 5; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;

	std::vector<int> v(a, a + 5);
	my_reverse(v.begin(), v.end());
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
 
	std::list<int> l(v.begin(), v.end());
	my_reverse(l.begin(), l.end());
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
 
}

void main_iterator_traits()
{
	test_cppreference();
}