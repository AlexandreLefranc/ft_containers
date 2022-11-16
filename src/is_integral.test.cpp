/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:22:17 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/15 14:23:21 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
	#include "utils.hpp"
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

static	void	test_cplusplus()
{
	print_title("IS_INTEGRAL - CPLUSPLUS");

	std::cout << std::boolalpha;
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << ns::is_integral<char>::value << std::endl;
	std::cout << "int: " << ns::is_integral<int>::value << std::endl;
	std::cout << "float: " << ns::is_integral<float>::value << std::endl;
}

void	main_is_integral()
{
	test_cplusplus();
}