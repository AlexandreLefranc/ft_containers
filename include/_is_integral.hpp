/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:14:14 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/15 14:19:18 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

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
	struct is_integral<bool>: public true_type {};

	template <>
	struct is_integral<char>: public true_type {};

	template <>
	struct is_integral<wchar_t>: public true_type {};

	template <>
	struct is_integral<signed char>: public true_type {};

	template <>
	struct is_integral<short int>: public true_type {};

	template <>
	struct is_integral<int>: public true_type {};

	template <>
	struct is_integral<long int>: public true_type {};

	template <>
	struct is_integral<long long int>: public true_type {};

	template <>
	struct is_integral<unsigned char>: public true_type {};

	template <>
	struct is_integral<unsigned short int>: public true_type {};

	template <>
	struct is_integral<unsigned int>: public true_type {};

	template <>
	struct is_integral<unsigned long int>: public true_type {};

	template <>
	struct is_integral<unsigned long long int>: public true_type {};

	template <>
	struct is_integral<const bool>: public true_type {};

	template <>
	struct is_integral<const char>: public true_type {};

	template <>
	struct is_integral<const wchar_t>: public true_type {};

	template <>
	struct is_integral<const signed char>: public true_type {};

	template <>
	struct is_integral<const short int>: public true_type {};

	template <>
	struct is_integral<const int>: public true_type {};

	template <>
	struct is_integral<const long int>: public true_type {};

	template <>
	struct is_integral<const long long int>: public true_type {};

	template <>
	struct is_integral<const unsigned char>: public true_type {};

	template <>
	struct is_integral<const unsigned short int>: public true_type {};

	template <>
	struct is_integral<const unsigned int>: public true_type {};

	template <>
	struct is_integral<const unsigned long int>: public true_type {};

	template <>
	struct is_integral<const unsigned long long int>: public true_type {};

}


#endif