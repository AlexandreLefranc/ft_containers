/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.test.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:57:20 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/09 17:02:10 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#ifdef FT
	#include "reverse_iterator.hpp"
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

static void	test_constructors()
{
	print_title("REVERSE_ITERATOR - CONSTRUCTORS");

	std::vector<int> myvec;
	for (int i=0; i<10; i++)
		myvec.push_back(i);
	
	std::cout << "Default constructor" << std::endl;
	ns::reverse_iterator< std::vector<int>::iterator >	rev_it;

	std::cout << "Default constructor" << std::endl;

}

static void	test_move_accessors()
{
	print_title("REVERSE_ITERATOR - MOVE ACCESSORS");

	int a[] = {0, 1, 2, 3, 4};
	ns::reverse_iterator<int*> rv(a + 5); // move to the end and then make it behave as reverse_iterator
	std::cout	<< *rv << " "       // 4
				<< *(rv++) << " "   // 4 (print then change)
				<< *(++rv) << " "   // 2 (change then print)
				<< *(rv--) << " "   // 2 (print then change)
				<< *(--rv) << " "   // 4 (change then print)
				<< *(rv + 3) << " " // 1
				<< *(rv + 3 - 2) << " " // 3
				<< std::endl;

	rv += 3;
	std::cout << *rv << std::endl;   // 1
	rv -= 2;
	std::cout << *rv << std::endl;   // 3
	rv--;
	std::cout << *rv << std::endl;   // 4

	std::cout << rv[0] << std::endl;   // 4
	std::cout << rv[1] << std::endl;   // 3
	std::cout << rv[4] << std::endl;   // 0	
	
}

static void	test_comparators()
{
	print_title("REVERSE_ITERATOR - COMPARATORS");
	
	int a[] = {0, 1, 2, 3};
	//		    	 ↑  └───── x, y
	//			     └──────── z
 
	ns::reverse_iterator<int*> x(a + 4);
	ns::reverse_iterator<int*> y(a + 4);
	ns::reverse_iterator<int*> z(a + 3);
 
	std::cout << std::boolalpha
		<< "*x == " << *x << '\n' // 3
		<< "*y == " << *y << '\n' // 3
		<< "*z == " << *z << '\n' // 2
		<< "x == y ? " << (x == y) << '\n' // true
		<< "x != y ? " << (x != y) << '\n' // false
		<< "x <  y ? " << (x <  y) << '\n' // false
		<< "x <= y ? " << (x <= y) << '\n' // true
		<< "x == z ? " << (x == z) << '\n' // false
		<< "x != z ? " << (x != z) << '\n' // true
		<< "x <  z ? " << (x <  z) << '\n' // true!
		<< "x <= z ? " << (x <= z) << '\n' // true
		;
}

void	main_reverse_iterator()
{
	test_constructors();
	test_move_accessors();
	test_comparators();
}