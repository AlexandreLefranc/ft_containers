/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:09:44 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/08 16:45:26 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
	#include "enable_if.hpp"
	#include "is_integral.hpp"
	namespace ns = ft;
#endif
#ifdef STD
	#include <type_traits>
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

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ns::enable_if<ns::is_integral<T>::value,bool>::type
	is_odd (T i)
{
	return bool(i%2);
}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename ns::enable_if<ns::is_integral<T>::value>::type >
bool is_even (T i)
{
	return !bool(i%2);
}

static void	test_cplusplus()
{
	print_title("ENABLE_IF - CPLUSPLUS");
	short int i = 1;    // code does not compile if type of i is not integral

	std::cout << std::boolalpha;
	std::cout << "i is odd: " << is_odd(i) << std::endl;
	std::cout << "i is even: " << is_even(i) << std::endl;
}

void	main_enable_if()
{
	test_cplusplus();
}