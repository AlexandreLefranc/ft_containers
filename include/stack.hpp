/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:12:40 by alefranc          #+#    #+#             */
/*   Updated: 2023/01/05 16:08:02 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

	template < class T, class Container = ft::vector<T> >
	class stack
	{
	public: // typedefs
		typedef typename Container::value_type		value_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;
		typedef typename Container::size_type		size_type;
		typedef Container							container_type;
	
	protected: // underlying container

		Container c;
	
	public: // constructor/destructor/operator=		
		explicit stack(const Container& cont = Container())
			: c(cont)
		{}

		~stack() {}

		stack& operator=( const stack& other )
		{
			if (this == &other)
				return (*this);
			c = other.c;
			return (*this);
		}

	public: // element access
		reference top()					{return c.back();}
		const_reference top() const		{return c.back();}

	public: // capacity
		bool empty() const			{return c.empty();}
		size_type size() const		{return c.size();}

	public: // modifiers
		void push( const value_type& value )	{c.push_back(value);}
		void pop()								{c.pop_back();}

	public: // friend functions
		friend bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
		{return x.c == y.c;}
		
		friend bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
		{return x.c != y.c;}

		friend bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
		{return x.c < y.c;}
		
		friend bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
		{return x.c > y.c;}
		
		friend bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
		{return x.c <= y.c;}
		
		friend bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
		{return x.c >= y.c;}

	}; // class stack

} // namespace ft

#endif