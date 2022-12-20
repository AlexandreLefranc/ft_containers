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
		typedef Value							value_type;
		typedef typename value_type::first_type	key_type;
		typedef typename value_type::second_type	mapped_value;
		typedef Compare							key_compare;
		typedef Allocator						value_allocator_type;

	private: // setup node and allocators
		struct Node
		{
			Node*		parent;
			Node*		left;
			Node*		right;
			value_type	value;

			Node(const value_type& val)
				: parent(NULL), left(NULL), right(NULL), value(val)
			{}

			key_type	key() const {return value.first;}
		}; // Node

		typedef Node						node_type;
		typedef std::allocator<node_type>	node_allocator_type;

	public: // typedefs
		typedef typename node_allocator_type::size_type			size_type;
		typedef typename node_allocator_type::difference_type	difference_type;

		typedef typename value_allocator_type::reference		reference;
		typedef typename value_allocator_type::const_reference	const_reference;
		typedef typename value_allocator_type::pointer			pointer;
		typedef typename value_allocator_type::const_pointer	const_pointer;

		typedef typename node_allocator_type::pointer			node_pointer;

	private: // attributes
		value_allocator_type	_value_allocator;
		node_allocator_type		_node_allocator;
		key_compare				_compare;

		node_pointer	_root;
		size_type		_size;

	public: // iterator class
		class iterator
		{
		public:
			typedef difference_type					difference_type;
			typedef value_type						value_type;
			typedef pointer							pointer;
			typedef reference						reference;
			typedef ft::bidirectional_iterator_tag	iterator_category;

		private: // attributes
			node_pointer	_node;
			node_pointer	_root;

		public:
			node_pointer	node() const {return _node;}
			node_pointer	root() const {return _root;}

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
				while (parent != NULL && tmp == parent->left)
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
				_node = _predecessor();
				return tmp;
			}

		}; // class iterator

	public: // const_iterator class
		class const_iterator
		{
			public:
			typedef difference_type					difference_type;
			typedef value_type						value_type;
			typedef const_pointer					pointer;
			typedef const_reference					reference;
			typedef ft::bidirectional_iterator_tag	iterator_category;

		private:
			node_pointer	_node;
			node_pointer	_root;

		public: // constructor
			const_iterator()
				: _node(NULL), _root(NULL)
			{}

			const_iterator(const const_iterator& src)
				: _node(src._node), _root(src._root)
			{}

			const_iterator(node_pointer node, node_pointer root)
				: _node(node), _root(root)
			{}

			const_iterator(const iterator& src)
				: _node(src.node()), _root(src.root())
			{}

			const_iterator&	operator=(const const_iterator& rhs)
			{
				if (this == &rhs)
					return *this;
				_node = rhs._node;
				_root = rhs._root;
				return *this;
			}

		public: // comparison operators
			bool operator==(const const_iterator& rhs) {return _node == rhs._node;}
			bool operator!=(const const_iterator& rhs) {return _node != rhs._node;}
		
		public: // dereference
			const_reference	operator*() const {return _node->value;}
			const_pointer	operator->() const {return &(_node->value);}
		
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
			const_iterator&	operator++()
			{
				_node = _successor();
				return *this;
			}

			const_iterator&	operator--()
			{
				_node = _predecessor();
				return *this;
			}

			const_iterator	operator++(int)
			{
				const_iterator	tmp(*this);
				_node = _successor();
				return tmp;
			}

			const_iterator	operator--(int)
			{
				const_iterator	tmp(*this);
				_node = _successor();
				return tmp;
			}
		}; // const_iterator

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

	
	public: // element access
		reference	at(const key_type& key);

	public: // iterator
		iterator	begin() const
		{
			if (_root == NULL)
				return iterator(NULL, _root);
			node_pointer	tmp(_root);
			while (tmp->left != NULL)
				tmp = tmp->left;
			return iterator(tmp, _root);
		}

		iterator	end() const {return iterator(NULL, _root);}

		reverse_iterator	rbegin() const	{return reverse_iterator(end());}
		reverse_iterator	rend() const	{return reverse_iterator(begin());}

	public: // capacity
		bool		empty() const		{return _size == 0;}
		size_type	size() const		{return _size;}
		size_type	max_size() const	{return 0;}
	
	public: // modifiers: insert/swap
		ft::pair<iterator, bool> insert(const value_type& value)
		{
			node_pointer	parent = NULL;
			node_pointer	current = _root;
			while (current != NULL)
			{
				parent = current;
				if (value.first == current->key())
					return ft::pair<iterator, bool>(iterator(current, _root), false);
				else if (value.first < current->key())
					current = current->left;
				else
					current = current->right;
			}

			node_pointer	new_node = _node_allocator.allocate(1);
			_node_allocator.construct(new_node, node_type(value));

			new_node->parent = parent;
			if (new_node->parent == NULL)
				_root = new_node;
			else if (new_node->key() < parent->key())
				parent->left = new_node;
			else
				parent->right = new_node;
			
			_size++;

			return ft::pair<iterator, bool>(iterator(new_node, _root), true);
		}

	public: // modifiers: clear/erase
	public: // lookup
	public: // observers


	}; // Tree

}

#endif