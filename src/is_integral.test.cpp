/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:22:17 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/26 14:34:39 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>

#include "is_integral.hpp"

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
	std::cout << "char: " << NS::is_integral<char>::value << std::endl;
	std::cout << "int: " << NS::is_integral<int>::value << std::endl;
	std::cout << "float: " << NS::is_integral<float>::value << std::endl;
}

void	main_is_integral()
{
	test_cplusplus();
}