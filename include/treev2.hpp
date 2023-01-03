/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treev2.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:05:39 by alefranc          #+#    #+#             */
/*   Updated: 2023/01/03 18:12:21 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEV2_HPP
# define TREEV2_HPP

namespace ft
{
	template <class Key, class T, class Compare, class Allocator>
	class Tree
	{
	public: // basic typedefs
		typedef Key						key_type;
		typedef T						mapped_type;
		typedef ft::pair<const Key, T>	value_type;
		typedef Compare					key_compare;
		typedef Allocator				value_allocator_type;

	private: // node
		enum class Color { RED, BLACK };

		struct Node
		{
			value_type	value;
			Color		color;
			Node*		left;
			Node*		right;
			Node*		parent;

			Node(int val = 0, Color color = Color::BLACK, Node *left = nullptr,
				Node *right = nullptr, Node *parent = nullptr)
				: value(val), color(color), left(left), right(right), parent(parent)
			{}
		}; // struct Node

		typedef Node												node_type;
		typedef typename Allocator::template rebind<Node>::other	node_allocator_type;
	
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

		node_pointer			_root;
		size_type				_size;

	private: // helper functions
		node_pointer _leftmost(node_pointer node)
		{
			while (node->left != nullptr)
			{
				node = node->left;
			}
			return node;
		}
		
		node_pointer _rightmost(node_pointer node)
		{
			while (node->right != nullptr)
			{
				node = node->right;
			}
			return node;
		}
		
		node_pointer _next(node_pointer node)
		{
			if (node->right != nullptr)
			{
				return _leftmost(node->right);
			}
			
			node_pointer parent = node->parent;
			while (parent != nullptr && node == parent->right)
			{
				node = parent;
				parent = parent->parent;
			}
			return parent;
		}
		
		node_pointer _prev(node_pointer node)
		{
			if (node->left != nullptr)
			{
				return _rightmost(node->left);
			}

			node_pointer parent = node->parent;
			while (parent != nullptr && node == parent->left)
			{
				node = parent;
				parent = parent->parent;
			}
			return parent;
		}

	public: // iterator class
		class iterator
		{
		public: // typedefs
			typedef typename Tree::value_type		value_type;
			typedef typename Tree::difference_type	difference_type;
			typedef typename Tree::reference		reference;
			typedef typename Tree::pointer			pointer;
			typedef ft::bidirectional_iterator_tag	iterator_category;

		private: // attribute
			node_pointer	_node;
		
		public: // constructor
			iterator()
				: _node(nullptr)
			{}
			
			iterator(node_pointer node)
				: _node(node)
			{}

		public: // dereference
			reference	operator*() { return _node->value; }
			pointer		operator->() { return &(_node->value); }
		
		public: // increment/decrement
			iterator&	operator++()
			{
				_node = Tree::_next(_node);
				return *this;
			}
			
			iterator&	operator--()
			{
				_node = Tree::_prev(_node);
				return *this;
			}

			iterator	operator++(int)
			{
				iterator	copy(*this);
				++(*this);
				return copy;
			}

			iterator	operator--(int)
			{
				iterator	copy(*this);
				--(*this);
				return copy;
			}
			
		public: // comparison
			bool operator==(const iterator& other) const { return _node == other._node; }
			bool operator!=(const iterator& other) const { return _node != other._node; }

		public: // conversion to const_iterator
			operator const_iterator() const
			{
				return const_iterator(_node);
			}
		}; // class iterator

	public: // const_iterator class
		class const_iterator
		{
		public: // typedefs
			typedef typename Tree::value_type		value_type;
			typedef typename Tree::difference_type	difference_type;
			typedef typename Tree::const_reference	reference;
			typedef typename Tree::const_pointer	pointer;
			typedef ft::bidirectional_iterator_tag	iterator_category;

		private: // attribute
			node_pointer _node;
		
		public: // constructor
			const_iterator()
				: _node(nullptr)
			{}
			
			const_iterator(node_pointer node)
				: _node(node)
			{}
			
			const_iterator(const iterator& other)
				: _node(other._node)
			{}

		public: // dereference
			reference	operator*() { return _node->value; }
			pointer		operator->() { return &(_node->value); }
			
		public: // increment/decrement
			const_iterator&	operator++()
			{
				_node = Tree::_next(_node);
				return *this;
			}
			
			const_iterator&	operator--()
			{
				_node = Tree::_prev(_node);
				return *this;
			}

			const_iterator	operator++(int)
			{
				const_iterator	copy(*this);
				++(*this);
				return copy;
			}

			const_iterator	operator--(int)
			{
				const_iterator	copy(*this);
				--(*this);
				return copy;
			}
			
		public: // comparison
			bool operator==(const const_iterator& other) const { return _node == other._node; }
			bool operator!=(const const_iterator& other) const { return _node != other._node; }
		}; // class const_iterator
	
	public: // constructors/destructo/operator=
		Tree()
			: _value_allocator(), _node_allocator(), _compare(), _root(NULL)
		{}

		Tree(const Tree& src)
			: _value_allocator(), _node_allocator(), _compare(), _root(NULL)
		{
			*this = src;
		}

		~Tree()
		{
			clear();
		}

		Tree&	operator=(const Tree& rhs)
		{
			if (this == &rhs)
			{
				return *this;
			}
			
			clear();
			_value_allocator = rhs._value_allocator;
			_node_allocator = rhs._node_allocator;
			_compare rhs._compare;
			insert(rhs.begin(), rhs.end());
			return *this;
		}

	public: // iterators
		iterator		begin()			{return iterator(_leftmost(_root));}
		const_iterator	begin() const	{return const_iterator(_leftmost(_root));}

		iterator		end()			{return iterator(NULL);}
		const_iterator	end() const		{return const_iterator(NULL);}
		
		reverse_iterator		rbegin()		{return reverse_iterator(end());}
		const_reverse_iterator	rbegin() const	{return const_reverse_iterator(end());}

		reverse_iterator		rend()			{return reverse_iterator(begin());}
		const_reverse_iterator	rend() const	{return const_reverse_iterator(begin());}
		
	public: // capacity
		bool empty() const			{return _root == NULL;}
		size_type size() const		{return _size;}
		size_type max_size() const	{return _node_allocator.max_size();}

	private: // modifers helper
		node_pointer _create_node(const value_type& value)
		{
			node_pointer node = _node_allocator.allocate(1);
			_node_allocator.construct(node, Node(value, Color::RED));
			return node;
		}

		void _destroy_node(node_pointer node)
		{
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
		}

		void _destroy_subtree(node_pointer node)
		{
			if (node != nullptr)
			{
				_destroy_subtree(node->left);
				_destroy_subtree(node->right);
				_destroy_node(node);
			}
		}

		void _rotate_left(node_pointer node)
		{
			node_pointer right = node->right;
			node->right = right->left;
			if (right->left != nullptr)
			{
				right->left->parent = node;
			}
			right->parent = node->parent;
			if (node->parent == nullptr)
			{
				_root = right;
			}
			else if (node == node->parent->left)
			{
				node->parent->left = right;
			}
			else
			{
				node->parent->right = right;
			}
			right->left = node;
			node->parent = right;
		}

		void _rotate_right(node_pointer node)
		{
			node_pointer left = node->left;
			node->left = left->right;
			if (left->right != nullptr)
			{
				left->right->parent = node;
			}
			left->parent = node->parent;
			if (node->parent == nullptr)
			{
				_root = left;
			}
			else if (node == node->parent->right)
			{
				node->parent->right = left;
			}
			else
			{
				node->parent->left = left;
			}
			left->right = node;
			node->parent = left;
		}

		void _insert_fixup(node_pointer node)
		{
			node_pointer parent = nullptr;
			node_pointer grand_parent = nullptr;
			while (node != _root && node->color == Color::RED && node->parent->color == Color::RED)
			{
				parent = node->parent;
				grand_parent = parent->parent;
				if (parent == grand_parent->left)
				{
					node_pointer uncle = grand_parent->right;
					if (uncle != nullptr && uncle->color == Color::RED)
					{
						parent->color = Color::BLACK;
						uncle->color = Color::BLACK;
						grand_parent->color = Color::RED;
						node = grand_parent;
					}
					else
					{
						if (node == parent->right)
						{
							_rotate_left(parent);
							node = parent;
							parent = node->parent;
						}
						parent->color = Color::BLACK;
						grand_parent->color = Color::RED;
						_rotate_right(grand_parent);
					}
				}
				else
				{
					node_pointer uncle = grand_parent->left;
					if (uncle != nullptr && uncle->color == Color::RED)
					{
						parent->color = Color::BLACK;
						uncle->color = Color::BLACK;
						grand_parent->color = Color::RED;
						node = grand_parent;
					}
					else
					{
						if (node == parent->left)
						{
							_rotate_right(parent);
							node = parent;
							parent = node->parent;
						}
						parent->color = Color::BLACK;
						grand_parent->color = Color::RED;
						_rotate_left(grand_parent);
					}
				}
			}
			_root->color = Color::BLACK;
		}

		node_pointer _erase(node_pointer node)
		{
			if (node->left == nullptr || node->right == nullptr)
			{
				node_pointer child = (node->left != nullptr) ? node->left : node->right;
				if (node->color == Color::BLACK)
				{
					node->color = (child != nullptr && child->color == Color::RED) ?
						Color::RED : Color::BLACK;
					_erase_fixup(node);
				}
				_destroy_node(node);
				return child;
			}
			else
			{
				node_pointer predecessor = _maximum(node->left);
				node->value = predecessor->value;
				node->left = _erase(predecessor);
				return node;
			}
		}

		void _erase_fixup(node_pointer node)
		{
			node_pointer sibling = nullptr;
			while (node != _root && (node == nullptr || node->color == Color::BLACK))
			{
				if (node == node->parent->left)
				{
					sibling = node->parent->right;
					if (sibling->color == Color::RED)
					{
						sibling->color = Color::BLACK;
						node->parent->color = Color::RED;
						_rotate_left(node->parent);
						sibling = node->parent->right;
					}
					if ((sibling->left == nullptr || sibling->left->color == Color::BLACK) &&
						(sibling->right == nullptr || sibling->right->color == Color::BLACK))
					{
						sibling->color = Color::RED;
						node = node->parent;
					}
					else
					{
						if (sibling->right == nullptr || sibling->right->color == Color::BLACK)
						{
							sibling->left->color = Color::BLACK;
							sibling->color = Color::RED;
							_rotate_right(sibling);
							sibling = node->parent->right;
						}
						sibling->color = node->parent->color;
						node->parent->color = Color::BLACK;
						sibling->right->color = Color::BLACK;
						_rotate_left(node->parent);
						node = _root;
					}
				}
				else
				{
					sibling = node->parent->left;
					if (sibling->color == Color::RED)
					{
						sibling->color = Color::BLACK;
						node->parent->color = Color::RED;
						_rotate_right(node->parent);
						sibling = node->parent->left;
					}
					if ((sibling->left == nullptr || sibling->left->color == Color::BLACK) &&
						(sibling->right == nullptr || sibling->right->color == Color::BLACK))
					{
						sibling->color = Color::RED;
						node = node->parent;
					}
					else
					{
						if (sibling->left == nullptr || sibling->left->color == Color::BLACK)
						{
							sibling->right->color = Color::BLACK;
							sibling->color = Color::RED;
							_rotate_left(sibling);
							sibling = node->parent->left;
						}
						sibling->color = node->parent->color;
						node->parent->color = Color::BLACK;
						sibling->left->color = Color::BLACK;
						_rotate_right(node->parent);
						node = _root;
					}
				}
			}
			if (node != nullptr)
			{
				node->color = Color::BLACK;
			}
		}
	
	public: // modifiers
		std::pair<iterator, bool> insert(const value_type& value)
		{
			node_pointer new_node = _create_node(value);
			node_pointer curr = _root;
			node_pointer parent = nullptr;
			while (curr != nullptr)
			{
				parent = curr;
				if (_compare(value.first, curr->value.first))
				{
					curr = curr->left;
				}
				else if (_compare(curr->value.first, value.first))
				{
					curr = curr->right;
				}
				else
				{
					_destroy_node(new_node);
					return std::pair<iterator, bool>(iterator(curr), false);
				}
			}
			
			new_node->parent = parent;
			if (parent == nullptr)
			{
				_root = new_node;
			}
			else if (_compare(value.first, parent->value.first))
			{
				parent->left = new_node;
			}
			else
			{
				parent->right = new_node;
			}
			_insert_fixup(new_node);
			++_size;
			return std::pair<iterator, bool>(iterator(new_node), true);
		}

		void erase(iterator position)
		{
			if (position._node == _root)
			{
				_root = _erase(_root);
			}
			else
			{
				node_pointer& child = (position._node == position._node->parent->left) ?
					position._node->parent->left : position._node->parent->right;
				child = _erase(position._node);
			}
			--_size;
		}

		void clear()
		{
			if (_root != nullptr)
			{
				_destroy_subtree(_root);
				_root = nullptr;
				_size = 0;
			}
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

	public: // operation
		iterator		find(const key_type& k)
		{
			node_pointer node = _root;
			while (node != nullptr)
			{
				if (_compare(k, node->value.first))
				{
					node = node->left;
				}
				else if (_compare(node->value.first, k))
				{
					node = node->right;
				}
				else
				{
					return iterator(node);
				}
			}
			return end();
		}

		const_iterator	find(const key_type& k) const
		{
			node_pointer node = _root;
			while (node != nullptr)
			{
				if (_compare(k, node->value.first))
				{
					node = node->left;
				}
				else if (_compare(node->value.first, k))
				{
					node = node->right;
				}
				else
				{
					return const_iterator(node);
				}
			}
			return end();
		}




	}; // class Tree
}

#endif