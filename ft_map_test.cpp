/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:18:42 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/01 17:34:27 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "tree.hpp"
#include "map.hpp"

int main()
{
	ft::BSTree<int, int> tree;
	std::cout << "Hi" << std::endl;
	std::cout << tree.search(0) << std::endl;
	return (0);
}