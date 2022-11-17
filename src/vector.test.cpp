/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:16:10 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/17 17:11:15 by alefranc         ###   ########.fr       */
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

	ns::vector<int> a;
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

	ns::vector<int>::iterator	it;
	std::cout << sizeof(ns::vector<int>::iterator) << std::endl;
}

void	main_vector()
{
	test_vector_typedef();
	test_vector_constructor();
	test_vector_iterator();
}