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

	private: // Setup tree representation
		typedef Tree<value_type, key_compare, allocator_type> tree_type;
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
		map(): _t() {}

		// explicit map( const Compare& comp, const Allocator& alloc = Allocator())
		// {}
		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
		// map( const map& other );
		
		~map() {}

		// map&	operator=( const map& other );
		allocator_type	get_allocator() const {return _t.get_value_allocator();}

	public: // element access
		T&			at( const Key& key );
		const T&	at( const Key& key ) const;
		T& operator[]( const Key& key );

	public: // iterators
		iterator		begin();
		const_iterator	begin() const;

		iterator		end();
		const_iterator	end() const;

		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;

		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

	public: // capacity
	public: // modifiers: insert/swap
	public: // modifiers: clear/erase
	public: // lookup
	public: // observers

	}; // map

} // ft

#endif