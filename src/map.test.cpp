/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:49:34 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/22 19:56:03 by alex             ###   ########.fr       */
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

template <typename T, typename U>
static void	print_map(const ns::map<T, U>& m)
{
	std::cout << "size = " << m.size() << std::endl;
	for (typename ns::map<T, U>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;
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
	m.insert(ns::pair<char, int>('m', 13));
	m.insert(ns::pair<char, int>('a', 1));
	m.insert(ns::pair<char, int>('z', 26));

	std::cout << "      ['m', 13]       " << std::endl;
	std::cout << "      /       \\      " << std::endl;
	std::cout << "['a', 1]     ['z', 26]" << std::endl;
	std::cout << std::endl;



	ns::map<char, int>::iterator it;
	ns::map<char, int>::iterator ite;
	ns::map<char, int>::iterator tmpit;
	
	it = m.begin();
	ite = m.end();
	
	std::cout << "it = m.begin()" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;
	
	std::cout << "tmpit = ++it" << std::endl;
	tmpit = ++it;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "tmpit = it++" << std::endl;
	tmpit = it++;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "++it" << std::endl;
	++it;
	std::cout << "--it" << std::endl;
	--it;

	std::cout << "tmpit = --it" << std::endl;
	tmpit = --it;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "tmpit = it--" << std::endl;
	tmpit = it--;
	std::cout << "tmpit = ['" << tmpit->first << "', " << tmpit->second << "]" << std::endl;
	std::cout << "it    = ['" << it->first << "', " << it->second << "]" << std::endl;
	std::cout << std::endl;

	print_map(m);

	std::cout << "Implicit conversion from iterator to const_iterator" << std::endl;
	it = m.begin();

	ns::map<char, int>::const_iterator cit;
	cit = it;
}

static void	test_map_reverse_iterator()
{
	print_title("MAP REVERSE ITERATOR");

	ns::map<char, int> m;
	m.insert(ns::pair<char, int>('m', 13));
	m.insert(ns::pair<char, int>('a', 1));
	m.insert(ns::pair<char, int>('z', 26));

	std::cout << "      ['m', 13]       " << std::endl;
	std::cout << "      /       \\      " << std::endl;
	std::cout << "['a', 1]     ['z', 26]" << std::endl;
	std::cout << std::endl;

	ns::map<char, int>::reverse_iterator rit;
	ns::map<char, int>::reverse_iterator rite;

	for (rit = m.rbegin(); rit != m.rend(); rit++)
		std::cout << rit->first << " -> " << rit->second << std::endl;
}

static void	test_map_copy()
{
	print_title("MAP COPY");

	ns::map<char, int> m;
	m.insert(ns::pair<char, int>('m', 13));
	m.insert(ns::pair<char, int>('a', 1));
	m.insert(ns::pair<char, int>('z', 26));

	std::cout << "      ['m', 13]       " << std::endl;
	std::cout << "      /       \\      " << std::endl;
	std::cout << "['a', 1]     ['z', 26]" << std::endl;
	std::cout << std::endl;

	{
		std::cout << "Const copy by assignation" << std::endl;
		const ns::map<char, int> m2 = m;
		print_map(m2);
	}

	{
		std::cout << "Const copy by copy" << std::endl;
		const ns::map<char, int> m2(m);
		print_map(m2);
	}

	{
		std::cout << "Double copy" << std::endl;
		ns::map<char, int> m2 = m;
		m2 = m;
		print_map(m2);
	}
}

static void	test_map_erase()
{
	print_title("MAP ERASE");

	ns::map<char, int> m;

	m['c']=30;
	m['f']=60;
	m['b']=20;
	m['d']=40;
	m['a']=10;
	m['e']=50;

	print_map(m);

	std::cout << "Erase 2nd element via iterator" << std::endl;
	m.erase((++m.begin()));
	print_map(m);

	std::cout << "Erase 'c' via key" << std::endl;
	m.erase('c');
	print_map(m);

	std::cout << "Erase begin() to end() via range iterator" << std::endl;
	m.erase(m.begin(), m.end());
	print_map(m);

}

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

  ns::map<char,int> mymap;
  ns::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  std::cout << "found b\n";
  mymap.erase (it);                   // erasing by iterator
  std::cout << "erase iterator to b\n";
  mymap.erase ('c');                  // erasing by key
  std::cout << "erase by key 'c'\n";
  it=mymap.find ('e');
  std::cout << "erase by range 'e' to end\n";
  mymap.erase ( it, mymap.end() );    // erasing by range

  std::cout << " display :\n";
  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void	main_map()
{
	test_map_capacity();
	test_map_iterator();
	test_map_reverse_iterator();
	test_map_copy();
	test_map_erase();
	// test_map_lookup();
	// test_map_modifiers();
	test_map_test();
}