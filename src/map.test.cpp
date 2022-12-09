/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:49:34 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/09 14:49:41 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#ifdef FT
	#include "map.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	#include <map>
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

static void	test_map_capacity()
{
	print_title("MAP CAPACITY");
	std::cout << std::boolalpha;

	ns::map<char, int> m;

	std::cout << "m.empty() = " << m.empty() << std::endl;
	std::cout << "m.size() = " << m.size() << std::endl;
}

static void	test_map_iterator()
{
	print_title("MAP ITERATOR");

	ns::map<char, int> m;

	// ns::map<char, int>::iterator it = m.begin();
	// std::cout << it->first << std::endl;

	// ns::map<char, int>::iterator ite = m.end();
	// std::cout << ite->first << std::endl;
	// m.end();

	// ns::map<char, int>::iterator it;
	// std::cout << it.base() << std::endl;
}

static void	test_map_lookup()
{
	print_title("MAP LOOKUP");

	ns::map<char, int> m;
}

// static void	test_map_test()
// {
// 	print_title("MAP TEST");

// 	typedef ft::pair< const char, int >		value_type;
// 	typedef ft::Node< value_type >			node_type;
// 	typedef ft::MapIterator< node_type >	iter_type;

// 	node_type 	node(ft::pair<const char, int>('a', 42));
// 	node_type*	node_ptr = &node;
	
// 	iter_type	it(node_ptr, node_ptr);

// 	value_type	v = *it;
// 	std::cout << v.first << "->" << v.second << std::endl;
// 	std::cout << it->first << "->" << it->second << std::endl;

// 	std::cout << it._ptr << std::endl;
// 	std::cout << (++it)._ptr << std::endl;

// 	if (it._ptr == NULL)
// 		std::cout << "cnul" << std::endl;
// 	else
// 		std::cout << "cpanul" << std::endl;

// 	std::cout << (--it)._ptr << std::endl;

// 	if (it._ptr == NULL)
// 		std::cout << "cnul" << std::endl;
// 	else
// 		std::cout << "cpanul" << std::endl;
// }

void	main_map()
{
	test_map_capacity();
	test_map_iterator();
	test_map_lookup();
	// test_map_test();
}