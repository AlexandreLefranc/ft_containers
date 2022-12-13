/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:56:52 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/13 19:03:58 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include <cstdlib>

#include "utils.hpp"

namespace ft
{
	// T is ft::pair<const Key, T>

	template <typename T>
	struct Node
	{
		typedef std::ptrdiff_t	difference_type;
		typedef T				value_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef	int				iterator_category;

		typedef	typename T::first_type	first_type;
		typedef	typename T::second_type	second_type;

		T			data;
		Node*		parent;
		Node*		left;
		Node*		right;

		Node(const T& val)
			: data(val), parent(NULL), left(NULL), right(NULL)
		{}
		
		const first_type&	key() const
		{
			return data.first;
		}

		const second_type&	mapped_value() const
		{
			return data.second;
		}

		operator Node<const T>()
		{
			return Node<const T>(data);
		}

	}; // struct Node

} // namespece ft

#endif