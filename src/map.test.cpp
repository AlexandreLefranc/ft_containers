/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:49:34 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/02 10:19:48 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

static void	test_map_iterator()
{
	print_title("MAP ITERATOR");

	ft::BSTNode< ft::pair<int, int> > node(ft::pair<int, int>(1,1));
	node.parent = &node.data + 1;
	node.left   = &node.data + 2;
	node.right  = &node.data + 3;

	std::cout << node.parent << std::endl;
	std::cout << node.left << std::endl;
	std::cout << node.right << std::endl;

	ft::map<int, int>::iterator it(&node);
	// std::cout << *it << std::endl;
}

void	main_map()
{
	test_map_iterator();
}