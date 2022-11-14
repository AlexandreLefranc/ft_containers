/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:02:07 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/14 09:33:01 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

namespace ft
{

	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{

	private:
	
		class VectorIterator: ft::iterator_traits<T*>
		{
		private:
			T* _ptr;
			
		public:
			VectorIterator() : _ptr(NULL) {}
			VectorIterator(const VectorIterator& src) : _ptr(src._ptr) {}
			VectorIterator& operator=(const VectorIterator& rhs)
			{
				if (this != &rhs)
					_ptr = rhs._ptr;
				return (*this);
			}

			// *it
			// it->
			// ++it
			// it++
			// --it
			// it--
			// it += n
			// it -= n
			// it + a
			// a + it
			// it - a
			// it1 - it2
			// a[]
			// ==
			// !=
			// <
			// >
			// <=
			// >=



		};

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
		typedef VectorIterator							iterator;
		// typedef const std::iterator						const_iterator;
		// /!\ change to ft ns
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;


	private:

		pointer		_data;
		size_type	_size;
		size_type	_capacity;

	public:

		// Constructor/Destructor/Assignation
		vector();
		// explicit vector(const Allocator& alloc);
		explicit vector(size_type count, const T& value = T()/*, const Allocator& alloc = Allocator()*/);
		// 	: _data(new T[count]), _size(count)
		// {
		// 	for (size_type i = 0; i < count; i++)
		// 				_data[i] = value;
		// }
		// template<typename InputIt>
		// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		// vector(const vector& other);
		~vector();


		// Element Access

		// Iterators

	private:


	};

	#include "vector.tpp"

}

#endif