/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:56:52 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/08 15:50:50 by alefranc         ###   ########.fr       */
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
		// typedef std::ptrdiff_t	difference_type;
		// typedef T				value_type;
		// typedef T*				pointer;
		// typedef T&				reference;
		// typedef	int	iterator_category;

		T			data;
		Node*		parent;
		Node*		left;
		Node*		right;
		bool		sentinel;

		Node(const T& val)
			: data(val), parent(NULL), left(NULL), right(NULL), sentinel(false)
		{}

		explicit Node(bool	sent)
			: data(T()), parent(NULL), left(NULL), right(NULL), sentinel(true)
		{}

		bool	is_leaf()
		{
			if (left == NULL && right == NULL)
				return true;
			return false;
		}

		bool	has_left()
		{
			if (left != NULL)
				return true;
			return false;
		}

		bool	has_right()
		{
			if (right != NULL)
				return true;
			return false;
		}
		
	}; // struct Node

} // namespece ft

#endif