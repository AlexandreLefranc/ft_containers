/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:16:10 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/22 17:20:06 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifdef FT
	#include "vector.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	#include <vector>
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

template <typename T>
static void	vinfo(ns::vector<T>& v)
{
	std::cout	<< "Vector size     = " << v.size() << std::endl;
	std::cout	<< "Vector capacity = " << v.capacity() << std::endl;
	std::cout << std::endl;
}




static void	test_vector_typedef()
{
	print_title("VECTOR - TYPEDEF");

	std::cout << "sizeof(ns::vector<int>::value_type)      = " << sizeof(ns::vector<int>::value_type) << std::endl;
	std::cout << "sizeof(ns::vector<int>::allocator_type)  = " << sizeof(ns::vector<int>::allocator_type) << std::endl;
	std::cout << "sizeof(ns::vector<int>::size_type)       = " << sizeof(ns::vector<int>::size_type) << std::endl;
	std::cout << "sizeof(ns::vector<int>::difference_type) = " << sizeof(ns::vector<int>::difference_type) << std::endl;
	std::cout << "sizeof(ns::vector<int>::reference)       = " << sizeof(ns::vector<int>::reference) << std::endl;
	std::cout << "sizeof(ns::vector<int>::const_reference) = " << sizeof(ns::vector<int>::const_reference) << std::endl;
	std::cout << "sizeof(ns::vector<int>::pointer)         = " << sizeof(ns::vector<int>::pointer) << std::endl;
	std::cout << "sizeof(ns::vector<int>::const_pointer)   = " << sizeof(ns::vector<int>::const_pointer) << std::endl;
}

static void	test_vector_constructor()
{
	print_title("VECTOR - CONSTRUCTORS");

	// ns::vector<std::string> a;
	// ns::vector<std::string> b(10);
	// ns::vector<std::string> c(10, "0");

	std::cout << "Creating default vector" << std::endl;
	ns::vector<int> a;

	std::cout << "Creating count vector" << std::endl;
	ns::vector<int> b(10, 2);
	for (int i = 0; i < 10; i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	ns::vector<int> v1(100, 5);
	ns::vector<int> v2(80, 5);

	std::cout << "Info v1:" << std::endl;
	vinfo(v1);
	std::cout << "Info v1:" << std::endl;
	vinfo(v2);

	v2 = v1;

	std::cout << "Info v1:" << std::endl;
	vinfo(v1);
	std::cout << "Info v1:" << std::endl;
	vinfo(v2);

	// ns::vector<int> b(10);
	// ns::vector<int> c(10, 1);
}

static void	test_vector_iterator()
{
	print_title("VECTOR - ITERATOR");

	{
		std::cout << "Implicit conversion iterator to const_iterator" << std::endl;
		ns::vector<int> v(6, 0);
		
		ns::vector<int>::iterator		it = v.begin();
		ns::vector<int>::const_iterator	cit = it;
		
		(void)cit;
	}

	{
		ns::vector<int> v(6, 0);
		v[1] = 1;
		v[2] = 2;
		v[3] = 3;
		v[4] = 4;
		v[5] = 5;
		std::cout << "Non-const vector and non-const iterator" << std::endl;
		for (ns::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
			
		std::cout << "Non-const vector and const iterator" << std::endl;
		for (ns::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;

		std::cout << "Non-const vector and non-const reverse iterator" << std::endl;
		for (ns::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;

		std::cout << "Non-const vector and const reverse iterator" << std::endl;
		for (ns::vector<int>::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ns::vector<int> v1(6, 0);
		v1[1] = 1;
		v1[2] = 2;
		v1[3] = 3;
		v1[4] = 4;
		v1[5] = 5;
		const ns::vector<int> v(v1);
		v1[5] = 10;
		std::cout << "Const vector and const iterator" << std::endl;
		for (ns::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;

		std::cout << "Const vector and const reverse iterator" << std::endl;
		for (ns::vector<int>::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;

	}


	
	// int tab[] = {1,2,3,4};

	// ns::vector<int> v(tab, tab + 4);
	// for (ns::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
}

static void test_vector_assign()
{
	print_title("VECTOR - ASSIGN");

	// ns::vector<int> first;
	// ns::vector<int> second;
	// ns::vector<int> third;

	// first.assign(7, 100);             // 7 ints with a value of 100

	// ns::vector<int>::iterator it;
	// it = first.begin() + 1;

	// second.assign(it, first.end() - 1); // the 5 central values of first

	// int myints[] = {1776, 7, 4};
	// third.assign(myints, myints + 3);  // assigning from array.

	// std::cout << "Size of first: " << int(first.size()) << '\n';
	// std::cout << "Size of second: " << int(second.size()) << '\n';
	// std::cout << "Size of third: " << int(third.size()) << '\n';
}

void	main_vector()
{
	test_vector_typedef();
	test_vector_constructor();
	test_vector_iterator();

	test_vector_assign();
}