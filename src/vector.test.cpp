/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:16:10 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/25 18:12:03 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <iostream>
#include <vector>
#include <string>
#include "vector.hpp"

static void	print_title(const std::string& title)
{
	std::cout << std::endl;
	std::cout << "=============================================================\n";
	std::cout << title << std::endl;
	std::cout << "=============================================================\n";
	std::cout << std::endl;
}

static void	test_vector_typedef()
{
	print_title("VECTOR - TYPEDEF");

	std::cout << "sizeof(NS::vector<int>::value_type)      = " << sizeof(NS::vector<int>::value_type) << std::endl;
	std::cout << "sizeof(NS::vector<int>::allocator_type)  = " << sizeof(NS::vector<int>::allocator_type) << std::endl;
	std::cout << "sizeof(NS::vector<int>::size_type)       = " << sizeof(NS::vector<int>::size_type) << std::endl;
	std::cout << "sizeof(NS::vector<int>::difference_type) = " << sizeof(NS::vector<int>::difference_type) << std::endl;
	std::cout << "sizeof(NS::vector<int>::reference)       = " << sizeof(NS::vector<int>::reference) << std::endl;
	std::cout << "sizeof(NS::vector<int>::const_reference) = " << sizeof(NS::vector<int>::const_reference) << std::endl;
	std::cout << "sizeof(NS::vector<int>::pointer)         = " << sizeof(NS::vector<int>::pointer) << std::endl;
	std::cout << "sizeof(NS::vector<int>::const_pointer)   = " << sizeof(NS::vector<int>::const_pointer) << std::endl;
}

static void	test_vector_constructor()
{
	print_title("VECTOR - CONSTRUCTORS");

	// NS::vector<std::string> a;
	// NS::vector<std::string> b(10);
	// NS::vector<std::string> c(10, "0");

	NS::vector<int> a;
	// NS::vector<int> b(10);
	// NS::vector<int> c(10, 1);
}

void	main_vector()
{
	test_vector_typedef();
	test_vector_constructor();
}