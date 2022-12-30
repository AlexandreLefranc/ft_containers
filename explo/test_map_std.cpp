/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:56:37 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/20 16:30:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

int main()
{
	{
		const std::pair<int, int> p(1,2);
		std::cout << p.first << " / " << p.second << std::endl;
		p.first = 3;
	}






	// {
	// 	std::map<char, int> m;

	// 	m['a'] = 1;
	// 	m['c'] = 3;
	// 	m['b'] = 2;
	// 	m['5'] = 55;
	// 	m['6'] = 66;
	// 	m['4'] = 44;

	// 	for (std::map<char, int>::iterator it = m.begin(); it != m.end(); it++)
	// 	{
	// 		std::cout << it->first << " -> " << it->second << std::endl;
	// 		// std::cout << *it << std::endl;
	// 	}

	// 	std::map<char, int>::iterator ite = m.end();
	// 	std::cout << (--ite)->first << std::endl;
	// }
}