/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:00:51 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/14 16:26:35 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>

# include "utils.hpp"
# include "functional.hpp"
# include "tree.hpp"
# include "iterator.hpp"

namespace ft
{

	template <	class Key,
				class T,
				class Compare = ft::less<Key>,
				class Allocator = std::allocator< ft::pair<const Key, T> >
			>
	class map
	{

	public:

		// typedef
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef ft::pair<const Key, T>			value_type;
		
		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					difference_type;

		typedef Compare							key_compare;
		typedef Allocator						allocator_type;

		typedef			value_type&		reference;
		typedef	const	value_type&		const_reference;
		typedef			value_type*		pointer;
		typedef const	value_type*		const_pointer;
		
		typedef	ft::Node<value_type>			node_type;

		typedef ft::MapIterator<value_type>						iterator;
		typedef ft::MapIterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		
		class value_compare: public ft::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			Compare comp;
			value_compare(Compare c): comp(c) {}
		public:
			bool operator()( const value_type& lhs, const value_type& rhs) const
			{return comp(lhs.first, rhs.first);}
		};

	private:

		node_type*					_root;
		size_type					_size;

		key_compare					_compare;
		allocator_type				_alloc;

		std::allocator<node_type>	_alloc_node;

		void	_destroy(node_type* node)
		{
			if (node != NULL)
			{
				_destroy(node->left);
				_destroy(node->right);
				_alloc_node.deallocate(node, 1);
			}
		}

	public:

		/* BASICS - SYNOPSIS

		map();
		explicit map( const Compare& comp, const Allocator& alloc = Allocator());
		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
		map( const map& other );
		
		~map();

		map&			operator=( const map& other );	
		allocator_type	get_allocator() const;

		*/

		map()
			: _root(NULL), _size(0), _compare(Compare()), _alloc(Allocator()), _alloc_node(std::allocator<node_type>())
		{}

		explicit map( const Compare& comp, const Allocator& alloc = Allocator())
			: _root(NULL), _size(0), _compare(comp), _alloc(alloc), _alloc_node(std::allocator<node_type>())
		{}

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			: _root(NULL), _size(0), _compare(comp), _alloc(alloc), _alloc_node(std::allocator<node_type>())
		{
			insert(first, last);
		}

		map( const map& other )
			: _root(NULL), _size(0), _compare(Compare()), _alloc(Allocator()), _alloc_node(std::allocator<node_type>())
		{
			insert(other.begin(), other.end());
		}

		~map()
		{
			_destroy(_root);
		}

		map&			operator=( const map& other )
		{
			if (this == &other)
				return (*this);
			clear();
			insert(other.begin(), other.end());
			return (*this);
		}

		allocator_type	get_allocator() const {return (_alloc);}

		/* ELEMENT ACCESS - SYNOPSIS
		
		T& at( const Key& key );
		const T& at( const Key& key ) const;

		T& operator[]( const Key& key );
		
		*/

		T& at( const Key& key )
		{
			iterator	it = find(key);
			if (it != end())
				return it->second;
			throw std::out_of_range("out of range");
		}

		const T& at( const Key& key ) const
		{
			const_iterator	it = find(key);
			if (it != end())
				return it->second;
			throw std::out_of_range("out of range");
		}

		T& operator[]( const Key& key )
		{
			return insert(std::make_pair(key, T())).first->second;
		}




		/* ITERATORS - SYNOPSIS

		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

		*/

		iterator begin()
		{
			node_type*	tmp(_root);
			while (tmp->left != NULL)
				tmp = tmp->left;
			return iterator(tmp, _root);
		}

		const_iterator begin() const
		{
			node_type*	tmp(_root);
			while (tmp->left != NULL)
				tmp = tmp->left;
			return const_iterator(tmp, _root);
		}

		iterator end()
		{
			return iterator(NULL, _root);
		}

		const_iterator end() const
		{
			return const_iterator(NULL, _root);
		}

		reverse_iterator		rbegin()		{return reverse_iterator(end());}
		const_reverse_iterator	rbegin() const	{return const_reverse_iterator(end());}

		reverse_iterator		rend()			{return reverse_iterator(begin());}		
		const_reverse_iterator	rend() const	{return const_reverse_iterator(begin());}







		/* CAPACITY - SYNOPSIS

		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		*/

		bool empty() const			{return _size == 0;}
		size_type size() const		{return _size;}
		size_type max_size() const	{return _alloc_node.max_size();}





		/* MODIFIERS - SYNOPSIS

		void clear();

		ft::pair<iterator, bool>	insert( const value_type& value );
		iterator					insert( iterator pos, const value_type& value );
		template< class InputIt >
		void						insert( InputIt first, InputIt last );

		iterator	erase( iterator pos );
		iterator	erase( iterator first, iterator last );
		size_type	erase( const Key& key );

		void swap( map& other );

		*/

		void clear()
		{
			_destroy(_root);
			_size = 0;
		}

		ft::pair<iterator, bool>	insert( const value_type& value )
		{
			node_type*	parent = NULL;
			node_type*	current = _root;
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

			node_type*	new_node = _alloc_node.allocate(1);
			_alloc_node.construct(new_node, node_type(value));

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
		
		iterator					insert( iterator pos, const value_type& value )
		{
			(void)pos;
			return insert(value).first;
		}
		
		template< class InputIt >
		void						insert( InputIt first, InputIt last )
		{
			for (; first != last; first++)
				insert(*first);
		}






		/* LOOKUP - SYNOPSIS

		size_type		count( const Key& key ) const;
		iterator		find( const Key& key );
		const_iterator	find( const Key& key ) const;
		ft::pair<iterator,iterator>				equal_range( const Key& key );
		ft::pair<const_iterator,const_iterator>	equal_range( const Key& key ) const;
		iterator		lower_bound( const Key& key );
		const_iterator	lower_bound( const Key& key ) const;
		iterator		upper_bound( const Key& key );
		const_iterator	upper_bound( const Key& key ) const;

		*/

		size_type		count( const Key& key ) const
		{
			if (find(key) != end())
				return 1;
			return 0;
		}

		iterator		find( const Key& key )
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (it->first == key)
					return it;
			}
			return end();
		}

		const_iterator	find( const Key& key ) const
		{
			for (const_iterator it = begin(); it != end(); it++)
			{
				if (it->first == key)
					return it;
			}
			return end();
		}

		ft::pair<iterator,iterator>				equal_range( const Key& key )
		{return ft::make_pair(lower_bound(key), upper_bound(key));}
		
		ft::pair<const_iterator,const_iterator>	equal_range( const Key& key ) const
		{return ft::make_pair(lower_bound(key), upper_bound(key));}

		iterator		lower_bound( const Key& key )
		{
			return --find(key);
		}
		
		const_iterator	lower_bound( const Key& key ) const
		{return --find(key);}
		
		iterator		upper_bound( const Key& key )
		{return ++find(key);}

		const_iterator	upper_bound( const Key& key ) const
		{return ++find(key);}



		/* OBSERVERS - SYNOPSIS

		key_compare					key_comp() const;
		ft::map::value_compare		value_comp() const;

		*/

		key_compare					key_comp() const
		{
			return _compare;
		}
		
		value_compare		value_comp() const
		{
			return value_compare();
		}

	}; // class map

} // namespace ft

#endif