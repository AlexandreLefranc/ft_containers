/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:52:48 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/28 15:49:11 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.hpp"

int main()
{
#ifdef FT
    std::cout << "Using FT" << std::endl;
#endif
#ifdef STD
    std::cout << "Using STD" << std::endl;
#endif

    main_vector();
    // main_stack();
    // main_map();

    return (0);
}