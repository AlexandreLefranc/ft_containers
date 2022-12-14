/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:08:49 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/15 14:17:29 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "utils.hpp"
# include "functional.hpp"
# include "tree.hpp"

namespace ft
{

	template <	class Key,
				class T,
				class Compare = ft::less<Key>,
				class Allocator = std::allocator< ft::pair<const Key, T> >
			>
	class map
	{
	public: // basic typedefs
		typedef Key							key_type;
		typedef T							mapped_type;
		typedef ft::pair<const Key, T>		value_type;
		typedef Compare						key_compare;
		typedef Allocator					allocator_type;

		class value_compare
			: public ft::binary_function<value_type, value_type, bool>
		{
		friend class ft::map<Key, T, Compare, Allocator>;
		protected :
			Compare comp;
			value_compare(Compare c) : comp(c) {}
		public:
			bool operator()(const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		}; // value_compare

	private: // compare and alloc attributes
		Compare		_compare;
		Allocator	_allocator;

	private: // setup tree representation
		typedef Tree<key_type, mapped_type, key_compare, allocator_type> tree_type;
		tree_type	_t;

	public: // typedefs derived from tree
		typedef typename tree_type::size_type			size_type;
		typedef typename tree_type::difference_type		difference_type;

		typedef typename tree_type::reference			reference;
		typedef typename tree_type::const_reference		const_reference;
		typedef typename tree_type::pointer				pointer;
		typedef typename tree_type::const_pointer		const_pointer;

		typedef typename tree_type::iterator			iterator;
		typedef typename tree_type::const_iterator		const_iterator;
		typedef typename tree_type::reverse_iterator	reverse_iterator;
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

	public: // constructor/destructor/operator=
		map()
			: _compare(), _allocator(), _t()
		{}

		explicit map( const Compare& comp, const Allocator& alloc = Allocator())
			: _compare(comp), _allocator(alloc), _t()
		{}

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			: _compare(comp), _allocator(alloc), _t()
		{
			while (first != last)
			{
				_t.insert(first);
				first++;
			}
		}

		map( const map& src )
			: _compare(src._compare), _allocator(src._allocator), _t(src._t)
		{}

		~map() {}

		map&	operator=( const map& rhs )
		{
			if (this == &rhs)
				return *this;
			_compare = rhs._compare;
			_allocator = rhs._allocator;
			_t = rhs._t;
			return *this;
		}

	public: // element access
		T&			at( const key_type& key )		{return _t.at(key);}
		const T&	at( const key_type& key ) const	{return _t.at(key);}

		T&			operator[]( const key_type& key )
		{
			return (*((insert(value_type(key, T()))).first)).second;
		}

	public: // iterators
		iterator		begin()			{return _t.begin();}
		const_iterator	begin() const	{return _t.begin();}

		iterator		end()			{return _t.end();}
		const_iterator	end() const		{return _t.end();}

		reverse_iterator		rbegin()		{return _t.rbegin();}
		const_reverse_iterator	rbegin() const	{return _t.rbegin();}

		reverse_iterator		rend()			{return _t.rend();}
		const_reverse_iterator	rend() const	{return _t.rend();}

	public: // capacity
		bool empty() const			{return _t.empty();}
		size_type size() const		{return _t.size();}
		size_type max_size() const	{return _t.max_size();}

	public: // modifiers: insert/swap
		ft::pair<iterator, bool>	insert( const value_type& value )
		{
			return _t.insert(value);
		}

		iterator					insert( iterator pos, const value_type& value )
		{
			(void)pos;
			return _t.insert(value).first;
		}

		template< class InputIt >
		void						insert( InputIt first, InputIt last )
		{
			for (; first != last; first++)
				_t.insert(*first);
		}

		void swap( map& other )	{_t.swap(other._t);}

	public: // modifiers: clear/erase
		void	clear()									{_t.clear();}
		void	erase( iterator pos )					{_t.erase(pos);}
		void	erase( iterator first, iterator last )
		{
			while (first != last)
				_t.erase(first++);
		}

		size_type	erase( const key_type& key )
		{
			iterator	it = find(key);
			if (it == end())
				return 0;
			_t.erase(it);
			return 1;
		}

	public: // lookup
		size_type		count( const key_type& key ) const	{return _t.count(key);}
		iterator		find( const key_type& key )			{return _t.find(key);}
		const_iterator	find( const key_type& key ) const	{return _t.find(key);}

		ft::pair<iterator,iterator>				equal_range( const key_type& key )
		{return _t.equal_range(key);}

		ft::pair<const_iterator,const_iterator>	equal_range( const key_type& key ) const
		{return _t.equal_range(key);}

		iterator		lower_bound( const key_type& key )			{return _t.lower_bound(key);}
		const_iterator	lower_bound( const key_type& key ) const	{return _t.lower_bound(key);}
		iterator		upper_bound( const key_type& key )			{return _t.upper_bound(key);}
		const_iterator	upper_bound( const key_type& key ) const	{return _t.upper_bound(key);}

	public: // observers
		allocator_type	get_allocator() const	{return _t.get_value_allocator();}
		key_compare		key_comp() const		{return _t.key_comp();}
		value_compare	value_comp() const		{return value_compare(Compare());}

	}; // map

	// Non member functions
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
		{
			return false;
		}

		typename ft::map<Key,T,Compare,Alloc>::const_iterator	lhs_it = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator	rhs_it = rhs.begin();
		while (lhs_it != lhs.end())
		{
			if (*lhs_it != *rhs_it)
				return false;
			++lhs_it;
			++rhs_it;
		}
		return true;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator< ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return lhs < rhs || lhs == rhs;
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator> ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs <= rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif
