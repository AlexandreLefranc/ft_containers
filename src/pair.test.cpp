/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:52:41 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/08 15:56:15 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#ifdef FT
	#include "pair.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	#include <utility>
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

static void	test_pair_constructors()
{
	print_title("PAIR - CONSTRUCTORS");

	ns::pair<int, std::string>	pair1;
	ns::pair<int, std::string>	pair2(1, "bob");
	ns::pair<int, std::string>	pair3(pair2);

	std::cout	<< "pair1.first = " << pair1.first
				<< " | pair1.second = " << pair1.second << std::endl;

	std::cout	<< "pair2.first = " << pair2.first
				<< " | pair2.second = " << pair2.second << std::endl;

	std::cout	<< "pair3.first = " << pair3.first
				<< " | pair3.second = " << pair3.second << std::endl;

	pair1 = pair2;
	std::cout	<< "pair1.first = " << pair1.first
				<< " | pair1.second = " << pair1.second << std::endl;
}

static void	test_pair_make_pair()
{
	print_title("PAIR - MAKE_PAIR");

	ns::pair<int, std::string> p1 = ns::make_pair<int, std::string>(42, "4 et 2");
	std::cout	<< "p1.first = " << p1.first
				<< " | p1.second = " << p1.second << std::endl;
}

static void	test_pair_comparison()
{
	print_title("PAIR - COMPARISON");

	std::cout << std::boolalpha;
	std::cout << "pair(1, 1) == pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(1,1) == ns::pair<int, int>(1,1)) << std::endl;
	std::cout << "pair(1, 2) == pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(1,2) == ns::pair<int, int>(1,1)) << std::endl;
	std::cout << "pair(2, 1) == pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) == ns::pair<int, int>(1,1)) << std::endl;

	std::cout << "pair(2, 1) != pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) != ns::pair<int, int>(1,1)) << std::endl;

	std::cout << std::endl;
	std::cout << "pair(2, 1) > pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) > ns::pair<int, int>(1,1)) << std::endl;
	std::cout << "pair(2, 1) > pair(2, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) > ns::pair<int, int>(2,1)) << std::endl;
	std::cout << "pair(2, 1) > pair(2, 2) = ";
	std::cout << (ns::pair<int, int>(2,1) > ns::pair<int, int>(2,2)) << std::endl;

	std::cout << std::endl;
	std::cout << "pair(2, 1) >= pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) >= ns::pair<int, int>(1,1)) << std::endl;
	std::cout << "pair(2, 1) >= pair(2, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) >= ns::pair<int, int>(2,1)) << std::endl;
	std::cout << "pair(2, 1) >= pair(2, 2) = ";
	std::cout << (ns::pair<int, int>(2,1) >= ns::pair<int, int>(2,2)) << std::endl;

	std::cout << std::endl;
	std::cout << "pair(2, 1) < pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) < ns::pair<int, int>(1,1)) << std::endl;
	std::cout << "pair(2, 1) < pair(2, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) < ns::pair<int, int>(2,1)) << std::endl;
	std::cout << "pair(2, 1) < pair(2, 2) = ";
	std::cout << (ns::pair<int, int>(2,1) < ns::pair<int, int>(2,2)) << std::endl;

	std::cout << std::endl;
	std::cout << "pair(2, 1) <=pair(1, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) <=ns::pair<int, int>(1,1)) << std::endl;
	std::cout << "pair(2, 1) <=pair(2, 1) = ";
	std::cout << (ns::pair<int, int>(2,1) <=ns::pair<int, int>(2,1)) << std::endl;
	std::cout << "pair(2, 1) <=pair(2, 2) = ";
	std::cout << (ns::pair<int, int>(2,1) <=ns::pair<int, int>(2,2)) << std::endl;
}

void main_pair()
{
	test_pair_constructors();
	test_pair_make_pair();
	test_pair_comparison();
}
