/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:56:52 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/25 15:37:30 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include "utils.hpp"

namespace ft
{
	template <typename Key, typename T>
	struct BSTNode
	{
		ft::pair<Key, T>		value;
		BSTNode<Key, T>*		parent;
		BSTNode<Key, T>*		left;
		BSTNode<Key, T>*		right;

		BSTNode(const ft::pair<Key, T>& val)
			: value(val), parent(NULL), left(NULL), right(NULL)
		{}
	}; // struct BSTNode

	template <typename Key, typename T>
	class BSTree
	{
	private:

		BSTNode<Key, T>*	_root;

	}; // class BSTree

} // namespece ft

#endif