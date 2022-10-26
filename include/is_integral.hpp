/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:14:14 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/26 18:22:59 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include <type_traits>

namespace ft
{

	template<class T, T v>
	struct integral_constant 
	{
		static const T value = v;

		typedef T								value_type;
		typedef ft::integral_constant<T, v>		type;
	
		operator value_type() const { return value; }
	};

	typedef ft::integral_constant<bool, true>	true_type;
	typedef ft::integral_constant<bool, false>	false_type;

	template <class T>
	struct is_integral: public ft::integral_constant<T>
	{
		
	};


}


#endif