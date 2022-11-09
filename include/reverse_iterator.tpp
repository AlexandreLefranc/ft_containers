/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:51:23 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/09 13:57:42 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

// Constructors
// template <class Iter>
// reverse_iterator<Iter>::reverse_iterator()
// 	: current(Iter())
// {}

// template <class Iter>
// reverse_iterator<Iter>::reverse_iterator(iterator_type x)
// 	: current(x)
// {}

template <class Iter>
template <class U>
reverse_iterator<Iter>::reverse_iterator( const reverse_iterator<U>& other )
	: current(other.base())
{}


// Accessor
template <class Iter>
typename iterator_type reverse_iterator<Iter>::base() const
{return current;}

#endif