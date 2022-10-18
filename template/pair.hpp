/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:34:01 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/18 16:46:49 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		// Typedefs
		typedef	T1	first_type;
		typedef	T2	second_type;

		// Attributes
		T1	first;
		T2	second;

		// Constructors
		pair();
		pair(T1 one, T2 two);
		pair(const pair<T1, T2>& src);

		// Operator overload
		pair<T1, T2>& operator=(const pair<T1, T2>& other);
	};

	// Non-member function
	template <typename T1,typename T2>
	pair<T1,T2> make_pair(T1 x, T2 y);

	template <typename T1,typename T2>
	bool operator==(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator!=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator<(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator<=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator>(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator>=(const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs);

	#include "pair.tpp"
}

#endif
