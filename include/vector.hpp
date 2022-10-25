#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{

	template < typename T, typename Allocator = std::allocator<T> >
	class vector
	{

	public:

		// Types
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		// typedef std::iterator							iterator;
		// typedef const std::iterator						const_iterator;
		// // /!\ change to ft ns
		// typedef std::reverse_iterator<iterator>			reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

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

		pointer		_data;
		size_type	_size;


	};

	#include "vector.tpp"

}

#endif