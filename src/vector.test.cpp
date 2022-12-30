/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:16:10 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/28 16:43:10 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>

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
void	vinfo(T& v)
{
	std::cout	<< "Vector size     = " << v.size() << std::endl;
	std::cout	<< "Vector capacity = " << v.capacity() << std::endl;
	std::cout << std::endl;
}

template <typename T>
void	print_vector(T& v)
{
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
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

	{
		std::cout << "Creating default vector" << std::endl;
		ns::vector<int> v;
	}
	std::cout << std::endl;
	{
		std::cout << "Creating count vector with default value" << std::endl;
		ns::vector<int> v(10);
		for (int i = 0; i < 10; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Creating count vector with custom value" << std::endl;
		ns::vector<int> v(10, 2);
		for (int i = 0; i < 10; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Creating iter vector" << std::endl;
		int tab[] = {1,2,3,4,5};
		ns::vector<int> v(tab, tab+5);
		for (int i = 0; i < 5; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Creating vector by copy" << std::endl;
		ns::vector<int> v1(10, 2);
		ns::vector<int> v2(v1);
		v1[0] = 11;
		for (int i = 0; i < 10; i++)
			std::cout << v1[i] << " ";
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << v2[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Creating default vector then assignation operator" << std::endl;
		ns::vector<int> v1(10, 2);
		ns::vector<int> v2 = v1;
		v1[0] = 11;
		for (int i = 0; i < 10; i++)
			std::cout << v1[i] << " ";
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << v2[i] << " ";
		std::cout << std::endl;
	}
}

static void	test_vector_assign()
{
	print_title("VECTOR - ASSIGN");

	{
		std::cout << "Assigning using count assign" << std::endl;
		ns::vector<int> v;
		v.assign(10, 2);
		for (int i = 0; i < 10; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Assigning using iter assign" << std::endl;
		int tab[] = {1,2,3,4,5};
		ns::vector<int> v;
		v.assign(tab, tab + 5);
		for (int i = 0; i < 5; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
	}
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
}

static void	test_vector_iterator2()
{
	print_title("VECTOR - ITERATOR2");

	std::list<int>				lst;
	std::list<int>::iterator	lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ns::vector<int> vct(lst.begin(), lst.end());
	print_vector(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	print_vector(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	print_vector(vct);
}

static void	test_vector_iterator3()
{
	print_title("VECTOR - ITERATOR3");

	const int size = 5;
	ns::vector<int> vct(size);
	ns::vector<int>::iterator it = vct.begin();
	ns::vector<int>::const_iterator ite = vct.begin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	ns::vector<int>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
	std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	print_vector(vct);
}

static void test_vector_insert()
{
	print_title("VECTOR - INSERT");

	{
		std::cout << "Insert single element tests" << std::endl;
		ns::vector<int> v(5, 1);
		print_vector(v);
		vinfo(v);
		
		std::cout << "Adding 42 at the end" << std::endl;
		v.insert(v.end(), 42);
		print_vector(v);
		vinfo(v);
		
		std::cout << "Adding 42 at the second position" << std::endl;
		v.insert(v.begin() + 1, 42);
		print_vector(v);
		vinfo(v);
	}
	std::cout << std::endl;
	{
		std::cout << "Insert fill tests" << std::endl;
		ns::vector<int> v(5, 1);
		print_vector(v);
		vinfo(v);
		
		std::cout << "Adding 3 * 42 at the end" << std::endl;
		v.insert(v.end(), 3, 42);
		print_vector(v);
		vinfo(v);
		
		std::cout << "Adding 3 * 42 at the second position" << std::endl;
		v.insert(v.begin() + 1, 3, 42);
		print_vector(v);
		vinfo(v);
	}
	std::cout << std::endl;
	{
		std::cout << "Insert range tests" << std::endl;
		int tab[] = {11,22,33};

		ns::vector<int> v(5, 1);
		print_vector(v);
		vinfo(v);
		
		std::cout << "Adding {11,22,33} at the end" << std::endl;
		v.insert(v.end(), tab, tab+3);
		print_vector(v);
		vinfo(v);
		
		std::cout << "Adding {11,22,33} at the second position" << std::endl;
		v.insert(v.begin() + 1, tab, tab+3);
		print_vector(v);
		vinfo(v);
	}
}

static void test_vector_erase()
{
	print_title("VECTOR - ERASE");

	{
		std::cout << "Erase single element tests" << std::endl;
		
		int tab[] = {1,2,3,4};
		ns::vector<int> v(tab, tab+4);
		print_vector(v);
		vinfo(v);

		std::cout << "Erase successively 2 elements at 2nd position" << std::endl;
		v.erase(v.erase(v.begin() + 1));
		print_vector(v);
		vinfo(v);
	}
	std::cout << std::endl;
	{
		std::cout << "Erase single element tests" << std::endl;
		
		int tab[] = {1,2,3,4,5,6};
		ns::vector<int> v(tab, tab+6);
		print_vector(v);
		vinfo(v);

		std::cout << "Erase from begin()+1 to end()-2" << std::endl;
		v.erase(v.begin()+1, v.end()-2);
		print_vector(v);
		vinfo(v);
	}
}

static void	test_vector_perf()
{
	int	size = 100000000;
	ns::vector<int>	v;


	for (int i = 0; i < size ;i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < size ;i++)
	{
		v[i] = i + 1;
	}
}

void	main_vector()
{
	test_vector_typedef();
	test_vector_constructor();
	test_vector_assign();
	test_vector_iterator();
	test_vector_iterator2();
	test_vector_iterator3();
	test_vector_insert();
	test_vector_erase();
	test_vector_perf();
}