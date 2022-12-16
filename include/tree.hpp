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

	public: // iterator classes
		class iterator
		{
		public:
			typedef typename ft::iterator_traits< value_type >::difference_type	difference_type;
			typedef typename ft::iterator_traits< value_type >::value_type		value_type;
			typedef typename ft::iterator_traits< value_type >::pointer			pointer;
			typedef typename ft::iterator_traits< value_type >::reference		reference;
			typedef ft::bidirectional_iterator_tag							iterator_category;

		private:
			node_pointer	_node;
			node_pointer	_root;

		public: // constructor
			iterator()
				: _node(NULL), _root(NULL)
			{}

			iterator(const iterator& src)
				: _node(src._node), _root(src._root)
			{}

			iterator(node_pointer node, node_pointer root)
				: _node(node), _root(root)
			{}

			iterator&	operator=(const iterator& rhs)
			{
				if (this == &rhs)
					return *this;
				_node = rhs._node;
				_root = rhs._root;
				return *this;
			}

		public: // comparison operators
			bool operator==(const iterator& rhs) {return _node == rhs._node;}
			bool operator!=(const iterator& rhs) {return _node != rhs._node;}
		
		public: // dereference
			reference	operator*() const {return _node->value;}
			pointer		operator->() const {return &(_node->value);}
		
		private: // internal incrementor / decrement
			node_pointer	_min(node_pointer node)
			{
				while (node->left != NULL)
					node = node->left;
				return node;
			}

			node_pointer	_max(node_pointer node)
			{
				while (node->right != NULL)
					node = node->right;
				return node;
			}

			node_pointer	_successor()
			{
				node_pointer	tmp(_node);

				if (tmp->right != NULL)
					return _min(tmp->right);
				
				node_pointer	parent(tmp->parent);
				while (parent != NULL && tmp == parent->right)
				{
					tmp = parent;
					parent = tmp->parent;
				}
				return parent;
			}

			node_pointer	_predecessor()
			{
				if (_node == NULL)
					return _max(_root);
				
				node_pointer	tmp(_node);

				if (tmp->left != NULL)
					return _max(tmp->left);
				
				node_pointer	parent(tmp->parent);
				while (parent != NULL && tmp != parent->left)
				{
					tmp = parent;
					parent = tmp->parent;
				}
				return parent;
			}

		public: // incrementors/decrementors
			iterator&	operator++()
			{
				_node = _successor();
				return *this;
			}

			iterator&	operator--()
			{
				_node = _predecessor();
				return *this;
			}

			iterator	operator++(int)
			{
				iterator	tmp(*this);
				_node = _successor();
				return tmp;
			}

			iterator	operator--(int)
			{
				iterator	tmp(*this);
				_node = _successor();
				return tmp;
			}

		}; // class iterator

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

		Tree&	operator=(const Tree& rhs)
		{
			if (this == &rhs)
				return (*this);
			// do stuff
			return (*this);
		}

		value_allocator_type	get_value_allocator() const {return _value_allocator;}

	public: // iterator manip
		iterator	begin()
		{
			node_pointer	tmp(_root);
			while (tmp->left != NULL)
				tmp = tmp->left;
			return iterator(tmp, _root);
		}



	}; // Tree

}

#endif