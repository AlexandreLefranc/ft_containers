/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:10:10 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/24 18:17:56 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace ft
{
	
template < class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef Arg1	first_argument_type;
	typedef Arg2	second_argument_type;
	typedef Result	result_type;
};

template < class T >
struct less : public binary_function<T, T, bool>
{
	bool	operator()(const T& lhs, const T& rhs) const	{return lhs < rhs;}
};

} // namespace ft


#endif