/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:52:48 by alefranc          #+#    #+#             */
/*   Updated: 2023/01/05 16:38:35 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

void	main_vector();
void	main_stack();
void	main_map();

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