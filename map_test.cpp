/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:56:37 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/25 15:06:11 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

int main()
{
	std::map<char, int> m;

	m['a'] = 1;
	m['c'] = 3;
	m['b'] = 2;
	m['5'] = 55;
	m['6'] = 66;
	m['4'] = 44;

	for (std::map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;
}