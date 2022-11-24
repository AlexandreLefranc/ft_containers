/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:52:48 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/24 14:40:56 by alefranc         ###   ########.fr       */
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

    // main_pair();
    // main_equal();
    // main_is_integral();
    // main_vector();
    // main_iterator_traits();
    // main_reverse_iterator();
    main_stack();

    return (0);
}