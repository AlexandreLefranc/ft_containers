/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:14:14 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/26 18:30:23 by alefranc         ###   ########.fr       */
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

	// Specialization alias
	typedef ft::integral_constant<bool, true>	true_type;
	typedef ft::integral_constant<bool, false>	false_type;

	// Any non specialized type -> false_type
	template <class T>
	struct is_integral: public false_type {};

	// List of specialized type -> true_type
	template <>
	bool

	template <>
	char

	template <>
	char16_t

	template <>
	char32_t

	template <>
	wchar_t

	template <>
	signed char

	template <>
	short int

	template <>
	int

	template <>
	long int

	template <>
	long long int

	template <>
	unsigned char

	template <>
	unsigned short int

	template <>
	unsigned int

	template <>
	unsigned long int

	template <>
	unsigned long long int

	template <>
	bool

	template <>
	char

	template <>
	char16_t

	template <>
	char32_t

	template <>
	wchar_t

	template <>
	signed char

	template <>
	short int

	template <>
	int

	template <>
	long int

	template <>
	long long int

	template <>
	unsigned char

	template <>
	unsigned short int

	template <>
	unsigned int

	template <>
	unsigned long int

	template <>
	unsigned long long int

}


#endif