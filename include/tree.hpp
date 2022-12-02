/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:56:52 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/02 10:05:20 by alefranc         ###   ########.fr       */
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
	struct BSTNode
	{
		T		data;
		T*		parent;
		T*		left;
		T*		right;

		BSTNode(const T& val)
			: data(val), parent(NULL), left(NULL), right(NULL)
		{}
	}; // struct BSTNode

} // namespece ft

#endif