/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:02:07 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/28 16:40:03 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <limits>

# include "iterator.hpp"
# include "utils.hpp"

namespace ft
{

	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public: // typedefs
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef ft::VectorIterator<T>					iterator;
		typedef ft::VectorIterator<const T>				const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private: // attributes
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;

	public: // constructor/destructor/operator=
		vector()
			: _data(NULL), _size(0), _capacity(0), _alloc(Allocator())
		{/*std::cout << "Default constructor" << std::endl;*/}
		
		explicit vector( const Allocator& alloc )
			: _data(NULL), _size(0), _capacity(0), _alloc(alloc)
		{/*std::cout << "Alloc constructor" << std::endl;*/}

		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
			: _data(NULL), _size(count), _capacity(count), _alloc(alloc)
		{
			// std::cout << "Count constructor" << std::endl;
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, value);
		}

		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(),
				typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type* = NULL)
			: _data(NULL), _size(0), _capacity(0), _alloc(alloc)
		{
			// std::cout << "Iter constructor" << std::endl;

			difference_type	dist = ft::distance(first, last);

			_data = _alloc.allocate(dist);
			_size = dist;
			_capacity = dist;
			for (size_type i = 0; first != last; first++, i++)
				_alloc.construct(_data + i, *first);
		}

		vector( const vector& other )
			: _data(NULL), _size(other._size), _capacity(other._size), _alloc(other._alloc)
		{
			// std::cout << "Copy constructor" << std::endl;
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, other[i]);
		}

		vector& operator=( const vector& rhs )
		{
			if (this != &rhs)
			{
				clear();
				reserve(rhs.size());
				for (size_type i = 0; i < rhs.size(); i++)
				{
					_alloc.construct(_data + i, rhs[i]);
					_size++;
				}
			}
			return (*this);
		}
		
		~vector()
		{
			for (size_type i = 0; i < size(); i++)
				_alloc.destroy(_data + i);
			_alloc.deallocate(_data, _capacity);
		}

		void assign( size_type count, const T& value )
		{
			// std::cout << "Call assign count" << std::endl;
			clear();
			reserve(count);
			for (size_type i = 0; i < count; i++)
			{
				_alloc.construct(_data + i, value);
				_size++;
			}
		}
		
		template < class InputIt >
		typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type
		assign( InputIt first, InputIt last )
		{
			// std::cout << "Call assign iter" << std::endl;
			difference_type dist = ft::distance(first, last);
			clear();
			reserve(dist);
			for (size_type i = 0; first != last; first++, i++)
			{
				_alloc.construct(_data + i, *first);
				_size++;
			}
		}

		allocator_type get_allocator() const {return (_alloc);}

	public: // element access
		reference 		at( size_type pos )
		{
			if (pos >= size())
				throw std::out_of_range("Ouf of range");
			return (_data[pos]);
		}
		
		const_reference	at( size_type pos ) const
		{
			if (pos >= size())
				throw std::out_of_range("Ouf of range");
			return (_data[pos]);
		}

		reference 		operator[]( size_type pos )			{return _data[pos];}
		const_reference	operator[]( size_type pos ) const	{return _data[pos];}
		
		reference 		front()			{return _data[0];}
		const_reference	front() const	{return _data[0];}

		reference		back()			{return _data[size() - 1];}
		const_reference	back() const	{return _data[size() - 1];}

		T* 			data()			{return _data;}
		const T*	data() const	{return _data;}
		
	public: // iterators
		iterator				begin()			{return iterator(_data);}
		const_iterator			begin() const	{return const_iterator(_data);}

		iterator				end()		{return iterator(_data + _size);}
		const_iterator			end() const	{return const_iterator(_data + _size);}
		
		reverse_iterator		rbegin()		{return reverse_iterator(end());}
		const_reverse_iterator	rbegin() const	{return const_reverse_iterator(end());}

		reverse_iterator		rend()			{return reverse_iterator(begin());}		
		const_reverse_iterator	rend() const	{return const_reverse_iterator(begin());}

	public: // capacity
		bool		empty() const	{return size() == 0;}
		size_type	size() const	{return _size;}
		size_type	max_size() const	{return _alloc.max_size();}

		void		reserve( size_type new_cap )
		{
			if (new_cap > max_size())
				throw std::length_error("vector::reserve");
			if (new_cap > capacity())
			{
				T* tmp = _alloc.allocate(new_cap);
				for (size_type i = 0; i < size(); i++)
					_alloc.construct(tmp + i, _data[i]);
				
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);

				_data = tmp;
				_capacity = new_cap;
			}
		}

		size_type	capacity() const	{return _capacity;}

	public: // modifiers
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_data + i);
			_size = 0;
		}

		iterator	insert( const_iterator pos, const T& value )
		{
			ft::vector<T> tmp(pos, static_cast<const_iterator>(end()));

			difference_type dist = ft::distance(static_cast<const_iterator>(begin()), pos);
			resize(dist);
			push_back(value);
			for (const_iterator it = tmp.begin(); it != tmp.end(); it++)
				push_back(*it);
			return iterator(_data + dist);
		}
		
		iterator	insert( const_iterator pos, size_type count, const T& value )
		{
			ft::vector<T> tmp(pos, static_cast<const_iterator>(end()));

			difference_type dist = ft::distance(static_cast<const_iterator>(begin()), pos);
			resize(dist);
			for (size_type i = 0; i < count; i++)
				push_back(value);
			for (const_iterator it = tmp.begin(); it != tmp.end(); it++)
				push_back(*it);
			return iterator(_data + dist);
		}
		
		template< class InputIt >
		typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type
		insert( const_iterator pos, InputIt first, InputIt last )
		{
			ft::vector<T> tmp(pos, static_cast<const_iterator>(end()));

			difference_type dist = ft::distance(static_cast<const_iterator>(begin()), pos);
			resize(dist);
			for (; first != last; ++first)
				push_back(*first);
			for (const_iterator it = tmp.begin(); it != tmp.end(); it++)
				push_back(*it);
			return iterator(_data + dist);
		}

		iterator	erase( iterator pos )
		{

			_alloc.destroy(pos.base());
			
			for (iterator tmp(pos); tmp != (end()-1); tmp++)
			{
				_alloc.construct(tmp.base(), *(tmp+1));
				_alloc.destroy((tmp+1).base());
			}
			_size--;

			return (pos);
		}
		
		iterator	erase( iterator first, iterator last )
		{
			iterator		tmp;
			difference_type	dist = last - first;

			for (tmp = first; tmp != last; tmp++)
				_alloc.destroy(tmp.base());

			for (tmp = first; tmp != (end()-dist); tmp++)
			{
				_alloc.construct(tmp.base(), *(tmp+dist));
				_alloc.destroy((tmp+dist).base());
			}
			_size -= dist;

			return (first);
		}

		void		push_back( const T& value )
		{
			if (_size == 0)
				reserve(1);
			else if (_size + 1 > _capacity)
				reserve(_capacity * 2);
				
			_alloc.construct(_data + _size, value);
			_size++;
		}
		
		void		pop_back()
		{
			_alloc.destroy(_data + _size - 1);
			_size--;
		}

		void		resize( size_type count, T value = T() )
		{
			if (_size > count)
			{
				while (_size != count)
					pop_back();
			}
			else if (_size < count)
			{
				while (_size != count)
					push_back(value);
			}
		}

		void		swap( ft::vector<T>& other )
		{
			pointer	tmp_data = other._data;
			other._data = _data;
			_data = tmp_data;

			size_type	tmp_size = other._size;
			other._size = _size;
			_size = tmp_size;

			size_type	tmp_capacity = other._capacity;
			other._capacity = _capacity;
			_capacity = tmp_capacity;

			allocator_type	tmp_alloc = other._alloc;
			other._alloc = _alloc;
			_alloc = tmp_alloc;
		}

	}; // class vector

	template< class T, class Alloc >
	void swap( ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs )
	{
		lhs.swap(rhs);
	}

	template< class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		if (lhs.size() == rhs.size())
		{
			for (typename ft::vector<T,Alloc>::size_type i = 0; i < rhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return (false);
			}
			return (true);
		}
		return (false);
	}

	template< class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return rhs < lhs;
	}

	template< class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs > rhs);
	}

	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}

} // namespace ft

#endif