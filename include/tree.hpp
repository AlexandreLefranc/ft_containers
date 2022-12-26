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

			size_t	count_children()
			{
				size_type	count = 0;
				if (left != NULL)
					++count;
				if (right != NULL)
					++count;
				return count;
			}
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

		public: // attributes
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

		public:
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
				while (parent != NULL && tmp == parent->left)
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
				_node = _predecessor();
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
		{_destroy(_root);}

		Tree&	operator=(const Tree& rhs)
		{
			if (this == &rhs)
				return *this;
			_destroy(_root);
			_value_allocator = rhs._value_allocator;
			_node_allocator = rhs._node_allocator;
			_compare = rhs._compare;
			_copy(rhs);
			return *this;
		}

		value_allocator_type	get_value_allocator() const {return _value_allocator;}

	private: // internal function
		void	_copy(const Tree& src)
		{
			for (const_iterator it = src.begin(); it != src.end(); it++)
				insert(*it);
		}

		void	_destroy(node_pointer& node)
		{
			if (node != NULL)
			{
				_destroy(node->left);
				_destroy(node->right);
				_node_allocator.deallocate(node, 1);
				node = NULL;
				--_size;
			}
		}

		node_pointer	_min(const node_pointer& node) const
		{
			node_pointer	tmp(node);
			while (tmp != NULL)
				tmp = tmp->left;
			return tmp;
		}
	
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
			// std::cout << "Allocate node " << new_node << std::endl;
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

		void	swap(Tree& other)
		{
			value_allocator_type	tmp_value_allocator = other._value_allocator;
			node_allocator_type		tmp_node_allocator = other._node_allocator;
			key_compare				tmp_compare = other._compare;
			node_pointer			tmp_root = other._root;
			size_type				tmp_size = other._size;

			other._value_allocator = _value_allocator;
			other._node_allocator = _node_allocator;
			other._compare = _compare;
			other._root = _root;
			other._size = _size;

			_value_allocator = tmp_value_allocator;
			_node_allocator = tmp_node_allocator;
			_compare = tmp_compare;
			_root = tmp_root;
			_size = tmp_size;
		}

	public: // modifiers: clear/erase
		void	clear() {_destroy(_root);}

		void	erase(iterator pos)
		{
			if (pos == end())
				return;

			node_pointer	node = pos.node();
			// std::cout << pos->first << node->count_children() << std::endl;
			if (node->count_children() == 0)
			{
				// unlink parent and node
				if (node->parent == NULL)
					_root = NULL;
				else if (node->parent->left == node)
					node->parent->left = NULL;
				else
					node->parent->right = NULL;

				_node_allocator.deallocate(node, 1);
				--_size;
				return;
			}

			if (node->count_children() == 1)
			{
				// get the node child
				node_pointer	child;
				if (node->left != NULL)
					child = node->left;
				else
					child = node->right;
				
				// link node parent to node child
				if (node->parent == NULL)
					_root = child;
				else if (node->parent->left == node)
					node->parent->left = child;
				else
					node->parent->right = child;
				
				// link the node child to node parent
				child->parent = node->parent;

				_node_allocator.deallocate(node, 1);
				--_size;
				return;
			}
			
			if (node->count_children() == 2)
			{
				// get minimum of the successor of node. Also get the child of the succesor
				node_pointer	min = (++pos).node();
				node_pointer	min_child;
				if (min->left != NULL)
					min_child = min->left;
				else
					min_child = min->right;
				// link minimum parent to minimum child
				if (min->parent->left == min)
					min->parent->left = min_child;
				else
					min->parent->right = min_child;
				
				// link minimum child to minimum parent
				if (min_child != NULL)
					min_child->parent = min->parent;

				// link node parent to minimum
				if (node->parent == NULL)
					_root = min;
				else if (node->parent->left == node)
					node->parent->left = min;
				else
					node->parent->right = min;

				// link node child to minimum
				node->left->parent = min;
				if (node->right != NULL)
					node->right->parent = min;

				// link minimum to node parent and node child
				min->parent = node->parent;
				min->left = node->left;
				min->right = node->right;

				_node_allocator.deallocate(node, 1);
				--_size;
				return;
			}
		}

	public: // lookup
		size_type	count(const key_type& key) const
		{
			if (find(key) != end())
				return 1;
			return 0;
		}

		iterator	find(const key_type& key) const
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (it->first == key)
					return it;
			}
			return end();
		}

		iterator	lower_bound(const key_type& key) const
		{
			iterator	it = begin();
			while (it != end() && it->first < key)
				it++;
			return it;
		}

		iterator	upper_bound(const key_type& key) const
		{
			iterator	it = begin();
			while (it != end())
			{
				if (it->first > key)
					return it;
				it++;
			}
			return end();
		}

		ft::pair<iterator, iterator>	equal_range(const key_type& key) const
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}
		

	public: // observers


	}; // Tree

}

#endif