/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:12:52 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/15 14:12:52 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include "iterator.hpp"

namespace ft
{

	template <class Value, class Compare, class Allocator>
	class Tree
	{
	public: // basic typedefs
		typedef Value			value_type;
		typedef Compare			key_compare;
		typedef Allocator		value_allocator_type;

	private: // setup node and allocators
		struct Node
		{
			Node*		parent;
			Node*		left;
			Node*		right;
			value_type	value;
		}; // Node

		typedef Node						node_type;
		typedef std::allocator<node_type>	node_allocator_type;

		value_allocator_type	_value_allocator;
		node_allocator_type		_node_allocator;
		key_compare				_compare;

	public: // typedefs
		typedef typename node_allocator_type::size_type			size_type;
		typedef typename node_allocator_type::difference_type	difference_type;

		typedef typename value_allocator_type::reference		reference;
		typedef typename value_allocator_type::const_reference	const_reference;
		typedef typename value_allocator_type::pointer			pointer;
		typedef typename value_allocator_type::const_pointer	const_pointer;

		typedef typename node_allocator_type::pointer			node_pointer;

	private: // attributes
		node_pointer	_root;
		size_type		_size;

	public: // iterators
		class iterator;
		class const_iterator;

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	public: // constructors/destructor/operator=
		Tree()
			: _value_allocator(), _node_allocator(), _compare(), _root(NULL), _size(0)
		{}

		Tree(const Tree& src)
			: _value_allocator(), _node_allocator(), _compare(), _root(NULL), _size(0)
		{*this = src;}

		~Tree()
		{}

		value_allocator_type	get_value_allocator() const {return _value_allocator;}




	
	
	}; // Tree

}

#endif