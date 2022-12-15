/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:49:34 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/15 17:34:11 by alefranc         ###   ########.fr       */
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

// template <typename T, typename U>
// static void	print_map(ns::map<T, U>& m)
// {
// 	std::cout << "size = " << m.size() << std::endl;
// 	for (typename ns::map<T, U>::iterator it = m.begin(); it != m.end(); it++)
// 		std::cout << it->first << " -> " << it->second << std::endl;
// 	std::cout << std::endl;
// }

// static void	test_map_capacity()
// {
// 	print_title("MAP CAPACITY");
// 	std::cout << std::boolalpha;

// 	ns::map<char, int> m;

// 	std::cout << "m.empty() = " << m.empty() << std::endl;
// 	std::cout << "m.size() = " << m.size() << std::endl;
// }

// static void	test_map_iterator()
// {
// 	print_title("MAP ITERATOR");

// 	ns::map<char, int> m;
// 	m.insert(ns::pair<char, int>('m', 13));
// 	m.insert(ns::pair<char, int>('a', 1));
// 	m.insert(ns::pair<char, int>('z', 26));

// 	std::cout << "      ['m', 13]       " << std::endl;
// 	std::cout << "      /       \\      " << std::endl;
// 	std::cout << "['a', 1]     ['z', 26]" << std::endl;
// 	std::cout << std::endl;



// 	ns::map<char, int>::iterator it;
// 	ns::map<char, int>::iterator ite;
// 	ns::map<char, int>::iterator tmpit;
	
// 	it = m.begin();
// 	ite = m.end();
	
// 	std::cout << "it = m.begin()" << std::endl;
// 	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
// 	std::cout << std::endl;
	
// 	std::cout << "tmpit = ++it" << std::endl;
// 	tmpit = ++it;
// 	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
// 	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "tmpit = it++" << std::endl;
// 	tmpit = it++;
// 	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
// 	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
// 	std::cout << std::endl;

// 	++it;
// 	--it;

// 	std::cout << "tmpit = --it" << std::endl;
// 	tmpit = --it;
// 	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
// 	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "tmpit = it--" << std::endl;
// 	tmpit = it--;
// 	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
// 	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
// 	std::cout << std::endl;

// 	print_map(m);

// 	std::cout << "Implicit conversion from iterator to const_iterator" << std::endl;
// 	it = m.begin();

// 	ns::map<char, int>::const_iterator cit;
// 	cit = it;
// }

// static void	test_map_reverse_iterator()
// {
// 	print_title("MAP REVERSE ITERATOR");

// 	ns::map<char, int> m;
// 	m.insert(ns::pair<char, int>('m', 13));
// 	m.insert(ns::pair<char, int>('a', 1));
// 	m.insert(ns::pair<char, int>('z', 26));

// 	std::cout << "      ['m', 13]       " << std::endl;
// 	std::cout << "      /       \\      " << std::endl;
// 	std::cout << "['a', 1]     ['z', 26]" << std::endl;
// 	std::cout << std::endl;

// 	ns::map<char, int>::reverse_iterator rit;
// 	ns::map<char, int>::reverse_iterator rite;

// 	for (rit = m.rbegin(); rit != m.rend(); rit++)
// 		std::cout << rit->first << " -> " << rit->second << std::endl;
// }

// static void	test_map_const_copy()
// {
// 	print_title("MAP CONST COPY");

// 	ns::map<char, int> m;
// 	m.insert(ns::pair<char, int>('m', 13));
// 	m.insert(ns::pair<char, int>('a', 1));
// 	m.insert(ns::pair<char, int>('z', 26));

// 	std::cout << "      ['m', 13]       " << std::endl;
// 	std::cout << "      /       \\      " << std::endl;
// 	std::cout << "['a', 1]     ['z', 26]" << std::endl;
// 	std::cout << std::endl;

// 	const ns::map<char, int> m2;

// 	ft::MapIterator<ft::pair<char, int> > it;
// 	ft::MapIterator<const ft::pair<char, int> > cit = it;
// 	// m2.begin();
// }

// static void	test_map_lookup()
// {
// 	print_title("MAP LOOKUP");

// 	ns::map<char, int> m;
// }

// static void	test_map_modifiers()
// {
// 	print_title("MAP MODIFIERS");

// 	ns::map<int, int> m;

// 	ns::pair<ns::map<int, int>::iterator, bool> out = m.insert(ns::pair<int, int>(100, 3));
// 	std::cout << "Inserted? " << out.second
// 			<< " mapped_value = " << out.first->second
// 			<< " size = " << m.size() << std::endl;

// 	out = m.insert(ns::pair<int, int>(100, 3));
// 	std::cout << "Inserted? " << out.second
// 			<< " mapped_value = " << out.first->second
// 			<< " size = " << m.size() << std::endl;

// 	// print_map(m);	
// }

static void	test_map_test()
{
	print_title("MAP TEST");

	ns::map<char, int> m;
}

void	main_map()
{
	// test_map_capacity();
	// test_map_iterator();
	// test_map_reverse_iterator();
	// test_map_const_copy();
	// test_map_lookup();
	// test_map_modifiers();
	test_map_test();
}