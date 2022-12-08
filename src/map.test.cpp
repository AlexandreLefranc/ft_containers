/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:49:34 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/08 15:12:51 by alefranc         ###   ########.fr       */
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

void	main_map()
{
	test_map_capacity();
	test_map_iterator();
	test_map_lookup();
}