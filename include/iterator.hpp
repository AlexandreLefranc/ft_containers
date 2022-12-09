/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:00:31 by alefranc          #+#    #+#             */
/*   Updated: 2022/12/09 16:37:41 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{

/*********************************SYNOPSIS**************************************
*                              ITERATOR_TRAITS                                 *
*                              REVERSE_ITERATOR                                *
*                              VECTOR_ITERATOR                                 *
*                              MAP_ITERATOR                                    *
*                              UTILS_ITERATOR                                  *
*******************************************************************************/

/*******************************************************************************
*                              ITERATOR_TRAITS                                 *
*******************************************************************************/

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<class T>
struct iterator_traits
{
	typedef typename T::difference_type		difference_type;
	typedef typename T::value_type			value_type;
	typedef typename T::pointer				pointer;
	typedef typename T::reference			reference;
	typedef typename T::iterator_category	iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ft::random_access_iterator_tag	iterator_category;
};

template< class T >
struct iterator_traits<const T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef ft::random_access_iterator_tag	iterator_category;
};

/*******************************************************************************
*                              REVERSE_ITERATOR                                *
*******************************************************************************/

template <class Iter>
class reverse_iterator
{
public:

	// Typedefs
	typedef Iter													iterator_type;
	typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iter>::value_type			value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer				pointer;
	typedef typename ft::iterator_traits<Iter>::reference			reference;

private:

	iterator_type	current;

public:

	/* CONSTRUCTOR - SYNOPSIS

	reverse_iterator();
	explicit reverse_iterator(iterator_type x);
	template<class U>
	reverse_iterator(const reverse_iterator<U>& other);

	template<class U>
	reverse_iterator& operator=(const reverse_iterator<U>& rhs);

	*/
	reverse_iterator()
		: current(Iter())
	{}
	
	explicit reverse_iterator(iterator_type x)
		: current(x)
	{}
	
	template<class U>
	reverse_iterator(const reverse_iterator<U>& other)
		: current(other.base())
	{}

	template< class U >
	reverse_iterator& operator=(const reverse_iterator<U>& rhs)
	{
		if (this != &rhs)
		{
			current = rhs.base();
		}
		return (*this);
	}

	/* ACCESSOR - SYNOPSIS

	iterator_type	base() const;
	reference		operator*() const;
	pointer			operator->() const;
	reference		operator[](difference_type n) const;

	*/
	iterator_type base() const
	{
		return current;
	}

	reference		operator*() const
	{
		iterator_type tmp = current;
		return *(--tmp);
	}
	
	pointer			operator->() const
	{
		return &(this->operator*());
	}

	reference		operator[](difference_type n) const
	{
		return (base()[-n - 1]);
	}
	
	/* MOVE - SYNOPSIS
	
	reverse_iterator& operator++();
	reverse_iterator& operator--();
	reverse_iterator operator++( int );
	reverse_iterator operator--( int );
	reverse_iterator operator+( difference_type n ) const;
	reverse_iterator operator-( difference_type n ) const;
	reverse_iterator& operator+=( difference_type n );
	reverse_iterator& operator-=( difference_type n );
	
	*/
	reverse_iterator& operator++()
	{
		--current;
		return (*this);
	}
	
	reverse_iterator& operator--()
	{
		++current;
		return (*this);
	}
	
	reverse_iterator operator++( int )
	{
		reverse_iterator	tmp = *this;
		--current;
		return (tmp);
	}
	
	reverse_iterator operator--( int )
	{
		reverse_iterator	tmp = *this;
		++current;
		return (tmp);
	}

	reverse_iterator operator+( difference_type n ) const
	{
		return (reverse_iterator(base() - n));
	}

	reverse_iterator operator-( difference_type n ) const
	{
		return (reverse_iterator(base() + n));
	}
	
	reverse_iterator& operator+=( difference_type n )
	{
		current -= n;
		return (*this);
	}
	
	reverse_iterator& operator-=( difference_type n )
	{
		current += n;
		return (*this);
	}

};

/* NON-MEMBER FUNCTION - SYNOPSIS

template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs );
template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs );
template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs );
template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs );
template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs );
template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs );

template <class Iter>
reverse_iterator<Iter>
	operator+(	typename reverse_iterator<Iter>::difference_type n,
				const ft::	reverse_iterator<Iter>& it );

template <class Iter>
typename reverse_iterator<Iterator>::difference_type
	operator-(	const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs );

*/

template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() <= rhs.base());
}

template <class Iter>
reverse_iterator<Iter>
	operator+(	typename ft::reverse_iterator<Iter>::difference_type n,
				const ft::reverse_iterator<Iter>& it )
{
	return (ft::reverse_iterator<Iter>(it.base() - n));
}

template <class Iter>
typename ft::reverse_iterator<Iter>::difference_type
	operator-(	const ft::reverse_iterator<Iter>& lhs,
				const ft::reverse_iterator<Iter>& rhs )
{
	return (rhs.base() - lhs.base());
}

/*******************************************************************************
*                              VECTOR_ITERATOR                                 *
*******************************************************************************/

template <typename T>
class VectorIterator
{
public:
	// Typedefs
	typedef typename iterator_traits<T*>::difference_type	difference_type;
	typedef typename iterator_traits<T*>::value_type		value_type;
	typedef typename iterator_traits<T*>::pointer			pointer;
	typedef typename iterator_traits<T*>::reference			reference;
	typedef ft::random_access_iterator_tag					iterator_category;

private:
	pointer	_ptr;

public:

	/* CONSTRUCTOR - SYNOPSIS

	VectorIterator();
	VectorIterator(const VectorIterator<T>& src);
	VectorIterator(pointer ptr);
	VectorIterator& operator=(const VectorIterator<T>& rhs);

	*/
	VectorIterator()
		: _ptr(NULL)
	{}
	
	VectorIterator(const VectorIterator<T>& src)
		: _ptr(src._ptr)
	{}

	VectorIterator(pointer ptr)
		: _ptr(ptr)
	{}
	
	VectorIterator& operator=(const VectorIterator<T>& rhs)
	{
		if (this != &rhs)
			_ptr = rhs._ptr;
		return (*this);
	}

	/* ACCESSOR - SYNOPSYS
	
	const pointer	base() const;
	reference		operator*() const;
	pointer			operator->() const;
	reference		operator[](difference_type n);

	*/
	pointer		base() const					{return _ptr;}
	reference	operator*() const				{return *_ptr;}
	pointer		operator->() const				{return _ptr;}
	reference	operator[](difference_type n)	{return _ptr[n];}
	
	/* MOVE - SYNOPSIS
	
	VectorIterator&	operator++();
	VectorIterator&	operator--();
	VectorIterator	operator++( int );
	VectorIterator	operator--( int );
	VectorIterator	operator+( difference_type n ) const;
	VectorIterator	operator-( difference_type n ) const;
	VectorIterator&	operator+=( difference_type n );
	VectorIterator&	operator-=( difference_type n );
	difference_type operator-(VectorIterator const& r) const;

	*/
	VectorIterator&	operator++() {++_ptr; return (*this);}
	VectorIterator&	operator--() {--_ptr; return (*this);}
	
	VectorIterator	operator++( int ) 
	{
		VectorIterator tmp(*this);
		++_ptr;
		return (tmp);
	}

	VectorIterator	operator--( int )
	{
		VectorIterator tmp(*this);
		--_ptr;
		return (tmp);
	}
	
	VectorIterator	operator+( difference_type n ) const
	{
		VectorIterator tmp(*this);
		tmp._ptr += n;
		return (tmp);
	}
	
	VectorIterator	operator-( difference_type n ) const
	{
		VectorIterator tmp(*this);
		tmp._ptr -= n;
		return (tmp);
	}

	VectorIterator&	operator+=( difference_type n ) {_ptr += n; return (*this);}
	VectorIterator&	operator-=( difference_type n ) {_ptr -= n; return (*this);}
	difference_type operator-(VectorIterator const& r) const {return (_ptr - r._ptr);}

	operator VectorIterator<const T>() const {return (VectorIterator<const T>(this->_ptr));}

};

/* NON-MEMBER FUNCTION - SYNOPSIS

template <typename T, typename U>
bool	operator==(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs);

template <typename T, typename U>
bool	operator!=(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs);

template <typename T, typename U>
bool	operator<(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs);

template <typename T, typename U>
bool	operator<=(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs);

template <typename T, typename U>
bool	operator>(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs);

template <typename T, typename U>
bool	operator>=(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs);

*/
template <typename T, typename U>
bool	operator==(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename T, typename U>
bool	operator!=(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <typename T, typename U>
bool	operator<(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <typename T, typename U>
bool	operator<=(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <typename T, typename U>
bool	operator>(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <typename T, typename U>
bool	operator>=(const VectorIterator<T>& lhs, const VectorIterator<U>& rhs)
{
	return (lhs.base() >= rhs.base());
}

/*******************************************************************************
*                              MAP_ITERATOR                                    *
*******************************************************************************/

// C'est un pointeur qui pointe vers un noeud de l'arbre
// T est donc un Node< pair<Key, T> >

template <typename T>
class MapIterator
{

public:
	// Typedefs
	typedef typename iterator_traits<T>::difference_type	difference_type;
	typedef typename iterator_traits<T>::value_type			value_type;
	typedef typename iterator_traits<T>::pointer			pointer;
	typedef typename iterator_traits<T>::reference			reference;
	typedef ft::bidirectional_iterator_tag					iterator_category;

private:

	T*	_ptr;
	T*	_root;

	T*	_minimum(T* node)
	{
		while (node->left != NULL)
			node = node->left;
		return (node);
	}

	T*	_maximum(T* node)
	{
		while (node->right != NULL)
			node = node->right;
		return (node);
	}

	T*	_successor()
	{
		T*	tmp(_ptr);
		
		if (tmp->right != NULL)
			return _minimum(tmp->right);

		T* parent(tmp->parent);
		// added by me
		if (parent == NULL)
			return (NULL);

		while (parent != NULL && tmp == parent->right)
		{
			tmp = parent;
			parent = tmp->parent;
		}
		return (tmp);
	}

	T*	_predecessor()
	{
		T*	tmp(_ptr);

		// added by me
		if (tmp == NULL)
			return _maximum(_root);
		
		if (tmp->left != NULL)
			return _maximum(tmp->left);

		T* parent(tmp->parent);
		// added by me
		if (parent == NULL)
			return (NULL);

		while (parent != NULL && tmp == parent->left)
		{
			tmp = parent;
			parent = tmp->parent;
		}
		return (tmp);
	}

public:

	/* CONSTRUCTOR - SYNOPSIS

	MapIterator();
	MapIterator(const MapIterator<T>& src);
	MapIterator(pointer ptr);
	MapIterator& operator=(const MapIterator<T>& rhs);
	
	~MapIterator();

	*/

	MapIterator()
		: _ptr(NULL), _root(NULL)
	{}
	
	MapIterator(const MapIterator<T>& src)
		: _ptr(src._ptr), _root(src._root)
	{}
	
	MapIterator(T* ptr, T* root)
		: _ptr(ptr), _root(root)
	{}
	
	MapIterator& operator=(const MapIterator<T>& rhs)
	{
		if (this != &rhs)
		{
			_ptr = rhs._ptr;
			_root = rhs._root;
		}
		return (*this);
	}

	~MapIterator() {}

	/* ACCESSOR - SYNOPSYS

	T*				base() const;
	reference		operator*() const;
	pointer			operator->() const;

	*/

	T*			base() const {return _ptr;}
	reference	operator*() const	{return _ptr->data;}
	pointer		operator->() const	{return &_ptr->data;}

	/* MOVE - SYNOPSIS

	MapIterator&	operator++();
	MapIterator&	operator--();
	MapIterator		operator++( int );
	MapIterator		operator--( int );

	*/

	MapIterator&	operator++()
	{
		_ptr = _successor();
		return (*this);
	}

	MapIterator&	operator--()
	{
		_ptr = _predecessor();
		return (*this);
	}

	MapIterator		operator++( int )
	{
		MapIterator tmp(*this);
		_ptr = _successor();
		return (tmp);
	}

	MapIterator		operator--( int )
	{
		MapIterator tmp(*this);
		_ptr = _predecessor();
		return (tmp);
	}

}; // class MapIterator

/* NON-MEMBER FUNCTION - SYNOPSIS

template <typename T, typename U>
bool	operator==(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator!=(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator<(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator<=(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator>(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator>=(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

*/

template <typename T, typename U>
bool	operator==(const MapIterator<T>& lhs, const MapIterator<U>& rhs)
{
	if (lhs.base() == NULL && rhs.base() == NULL)
		return true;
	return lhs->first == rhs->first;
}

template <typename T, typename U>
bool	operator!=(const MapIterator<T>& lhs, const MapIterator<U>& rhs)
{
	return !operator==(lhs, rhs);
}

template <typename T, typename U>
bool	operator<(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator<=(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator>(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

template <typename T, typename U>
bool	operator>=(const MapIterator<T>& lhs, const MapIterator<U>& rhs);

/*******************************************************************************
*                              UTILS_ITERATOR                                  *
*******************************************************************************/

namespace detail
{

template<class It>
typename ft::iterator_traits<It>::difference_type 
	do_distance(It first, It last, ft::input_iterator_tag)
{
	typename ft::iterator_traits<It>::difference_type result = 0;
	while (first != last) {
		++first;
		++result;
	}
	return result;
}
 
template<class It>
typename ft::iterator_traits<It>::difference_type 
	do_distance(It first, It last, ft::random_access_iterator_tag)
{
	return last - first;
}

} // namespace detail
 
template<class It>
typename ft::iterator_traits<It>::difference_type 
	distance(It first, It last)
{
	return detail::do_distance(first, last,
							   typename ft::iterator_traits<It>::iterator_category());
}

} // namespace ft

#endif