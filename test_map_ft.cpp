/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_ft.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:31:20 by alex              #+#    #+#             */
/*   Updated: 2022/12/20 16:32:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "include/map.hpp"

int main()
{
    {
        const ft::pair<int, int> p(1,2);
		std::cout << p.first << " / " << p.second << std::endl;
		p.first = 3;
    }
}