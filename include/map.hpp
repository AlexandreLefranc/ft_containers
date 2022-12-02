/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:00:51 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/02 10:06:23 by alefranc         ###   ########.fr       */
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
				class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map
	{

	public:

		// typedef
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef ft::pair<const Key, T>								value_type;
		typedef std::size_t											size_type;
		typedef std::ptrdiff_t										difference_type;
		typedef Compare												key_compare;
		typedef Allocator											allocator_type;
		typedef value_type&											reference;
		typedef const value_type&									const_reference;
		typedef typename Allocator::pointer							pointer;
		typedef typename Allocator::const_pointer					const_pointer;
		typedef ft::MapIterator< ft::BSTNode<value_type> >			iterator;
		typedef ft::MapIterator< ft::BSTNode<const value_type> >	const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		
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

		ft::BSTNode<value_type>*	_tree_root;
		size_type					_tree_size;
		key_compare					_compare;
		allocator_type				_alloc;

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
			: _tree_root(NULL), _tree_size(0), _compare(Compare()), _alloc(Allocator())
		{}

		explicit map( const Compare& comp, const Allocator& alloc = Allocator())
			: _tree_root(NULL), _tree_size(0), _compare(comp), _alloc(alloc)
		{}

		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
		// 	: _tree_root(NULL), _tree_size(0), _compare(comp), _alloc(alloc)
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

		T& operator[]( const Key& key );



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












		/* CAPACITY - SYNOPSIS

		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		*/










		/* MODIFIERS - SYNOPSIS

		void clear();

		std::pair<iterator, bool>	insert( const value_type& value );
		iterator					insert( iterator pos, const value_type& value );
		template< class InputIt >
		void						insert( InputIt first, InputIt last );

		iterator	erase( iterator pos );
		iterator	erase( iterator first, iterator last );
		size_type	erase( const Key& key );

		void swap( map& other );

		*/






		/* LOOKUP - SYNOPSIS

		size_type	count( const Key& key ) const;
		iterator		find( const Key& key );
		const_iterator	find( const Key& key ) const;
		std::pair<iterator,iterator>				equal_range( const Key& key );
		std::pair<const_iterator,const_iterator>	equal_range( const Key& key ) const;
		iterator		lower_bound( const Key& key );
		const_iterator	lower_bound( const Key& key ) const;
		iterator		upper_bound( const Key& key );
		const_iterator	upper_bound( const Key& key ) const;

		*/







		/* OBSERVERS - SYNOPSIS

		key_compare					key_comp() const;
		std::map::value_compare		value_comp() const;

		*/


	}; // class map

} // namespace ft

#endif