/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:37:01 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/09 17:08:01 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	
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

}

#endif