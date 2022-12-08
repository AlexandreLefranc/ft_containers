/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:00:51 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/08 17:15:00 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "tree.hpp"
# include "utils.hpp"
# include "functional.hpp"
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

		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		
		typedef ft::MapIterator< ft::Node<value_type> >			iterator;
		typedef ft::MapIterator< ft::Node<const value_type> >	const_iterator;
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

		typedef	ft::Node<value_type>		node_type;

		node_type*		_root;
		size_type		_size;

		key_compare		_compare;
		allocator_type	_alloc;

		std::allocator<node_type>	_alloc_node;

		void	_destroy(node_type* root)
		{
			if (root != NULL)
			{
				_destroy(root->left);
				_destroy(root->right);
				_alloc_node.deallocate(root, 1);
			}
		}

	public:

		/* BASICS - SYNOPSIS

		map();
		explicit map( const Compare& comp, const Allocator& alloc = Allocator());
		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
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

		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
		// 	: _root(NULL), _size(0), _compare(comp), _alloc(alloc)
		// {}

		~map()
		{}
		
		map&			operator=( const map& other )
		{
			if (this == &other)
				return (*this);
			// do stuff
			return (*this);
		}

		allocator_type	get_allocator() const {return (_alloc);}

		/* ELEMENT ACCESS - SYNOPSIS
		
		T& at( const Key& key );
		const T& at( const Key& key ) const;

		T& operator[]( const Key& key );
		
		*/

		T&			at( const Key& key );
		const T&	at( const Key& key ) const;

		T& operator[]( const Key& key )
		{
			// Key doesnt exists
			if (find() == end())
			{
				value_type	p(key, mapped_type());
				insert(p);
				return p.second();
			}

			
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
			ft::Node<value_type>*	tmp(_root);
			while (tmp->left != NULL)
				tmp = tmp->left;
			return iterator(tmp);
		}
		
		const_iterator begin() const
		{
			ft::Node<value_type>*	tmp(_root);
			while (tmp->left != NULL)
				tmp = tmp->left;
			return const_iterator(tmp);
		}

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;










		/* CAPACITY - SYNOPSIS

		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		*/

		bool empty() const {return _size == 0;}
		size_type size() const {return _size;}
		size_type max_size() const {return _alloc_node.max_size();}





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
			if (find() != end())
				return 1;
			return 0;
		}

		iterator		find( const Key& key )
		{
			node_type* node = _root;
			
			while ()
		}
		
		const_iterator	find( const Key& key ) const;





		/* OBSERVERS - SYNOPSIS

		key_compare					key_comp() const;
		ft::map::value_compare		value_comp() const;

		*/


		void	test()
		{
			
		}

	}; // class map

} // namespace ft

#endif