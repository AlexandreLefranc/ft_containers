/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:02:07 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/17 17:51:24 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <limits>

# include "iterator.hpp"

namespace ft
{

	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		
	public:

		// Typedefs
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef ft::VectorIterator<value_type>			iterator;
		typedef ft::VectorIterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


	private:
	
		pointer			_data;
		size_type		_size;
		size_type		_capacity;
		allocator_type	_alloc;

	public:

		/* CONSTRUCTOR DESTRUCTOR ASSIGN - SYNOPSIS

		vector();
		explicit vector( const Allocator& alloc );
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		
		vector& operator=( const vector& rhs );
		
		~vector();

		void assign( size_type count, const T& value );
		
		template < class InputIt >
		void assign( InputIt first, InputIt last );

		allocator_type get_allocator() const;

		*/

		vector()
			: _data(NULL), _size(0), _capacity(0), _alloc(Allocator())
		{}
		
		explicit vector( const Allocator& alloc )
			: _data(NULL), _size(0), _capacity(0), _alloc(alloc)
		{}

		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())
			: _data(NULL), _size(count), _capacity(count), _alloc(alloc)
		{
			_data = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, value);
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
			clear();
			if (count > _capacity)
				reserve(count);
		}
		
		template < class InputIt >
		void assign( InputIt first, InputIt last )
		{
			
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

		/* ELEMENT ACCESS - SYNOPSIS

		reference 		at( size_type pos );
		const_reference	at( size_type pos ) const;

		reference 		operator[]( size_type pos );
		const_reference	operator[]( size_type pos ) const;
		
		reference 		front();
		const_reference	front() const;

		reference		back();
		const_reference	back() const;

		T* data();
		const T* data() const;
		
		*/

		reference 		at( size_type pos )
		{
			if (pos >= size())
				throw std::out_of_range();
			return (_data[pos]);
		}
		
		const_reference	at( size_type pos ) const
		{
			if (pos >= size())
				throw std::out_of_range();
			return (_data[pos]);
		}

		reference 		operator[]( size_type pos )
		{
			return (_data[pos]);
		}

		const_reference	operator[]( size_type pos ) const
		{
			return (_data[pos]);
		}
		
		reference 		front()
		{
			return (_data[0]);
		}
		
		const_reference	front() const
		{
			return (_data[0]);
		}

		reference		back()
		{
			return (_data[size() - 1]);
		}
		
		const_reference	back() const
		{
			return (_data[size() - 1]);
		}

		T* data()
		{
			return (_data);
		}
		
		const T* data() const
		{
			return (_data);
		}
		
		/* ITERATORS - SYNOPSIS
		
		iterator				begin();
		const_iterator			begin() const;

		iterator				end();
		const_iterator			end() const;

		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;

		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		*/
	

	
		/* CAPACITY - SYNOPSIS
		
		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;
		void		reserve( size_type new_cap );
		size_type	capacity() const;

		*/

		bool		empty() const
		{
			// return (begin() == end());
			return (size() == 0);
		}

		size_type	size() const
		{
			// return (std::distance(begin(), end()));
			return (_size);
		}

		size_type	max_size() const
		{
			return (std::numeric_limits<difference_type>::max());
		}

		void		reserve( size_type new_cap )
		{
			if (new_cap > max_size())
				throw std::length_error("new_cap > max_size()");
			if (new_cap > capacity())
			{
				T* tmp = _alloc.allocate(new_cap);
				_capacity = new_cap;
				size_type i = 0;
				try
				{
					for (; i < size(); i++)
						_alloc.construct(tmp + i, _data[i]);
				}
				catch (std::exception& e)
				{
					for (size_type j = 0; j < i; i++)
						_alloc.destroy(tmp + i);
					_alloc.deallocate(tmp, new_cap);
				}

			}
		}
		
		size_type	capacity() const
		{
			return (_capacity);
		}

		/* MODIFIER - SYNOPSIS
		
		void		clear();

		iterator	insert( const_iterator pos, const T& value );
		iterator	insert( const_iterator pos, size_type count, const T& value );
		
		template< class InputIt >
		iterator	insert( const_iterator pos, InputIt first, InputIt last );

		iterator	erase( iterator pos );
		iterator	erase( iterator first, iterator last );

		void		push_back( const T& value );
		void		pop_back();

		void		resize( size_type count, T value = T() );

		void		swap( vector& other );

		*/

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.destroy(_data + i);
			}
			_size = 0;
		}

	};

}

#endif