/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:47:10 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/13 17:51:07 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:

		// Types
		typedef T						value_type;
		typedef Allocator				allocator_type;
		typedef value_type&				reference;
		typedef const value_type&		const_reference;

		// Constructors

		// Destructors

		// Iterators

		// Capacity

		// Element access

		// Modifiers

		//


	}
}

#endif