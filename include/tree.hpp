/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:56:52 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/24 18:00:50 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

namespace ft
{
	template <typename T>
	struct BSTNode
	{
		T	value;
		BSTNode<T>*	parent;
		BSTNode<T>*	left;
		BSTNode<T>*	right;
	};

	class BSTree
	{
		
	}; // class BSTree

} // namespece ft

#endif