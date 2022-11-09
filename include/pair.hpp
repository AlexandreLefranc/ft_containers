/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:34:01 by alefranc          #+#    #+#             */
/*   Updated: 2022/11/09 17:33:53 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		// Typedefs
		typedef	T1	first_type;
		typedef	T2	second_type;

		// Attributes
		T1	first;
		T2	second;
		
		/* SYNOPSIS

		// Constructors
		pair();
		pair(const T1& one, const T2& two);
		pair(const pair<T1, T2>& src);

		// Operator overload
		pair<T1, T2>& operator=(const pair<T1, T2>& other);
		
		*/
		// Constructors
		pair()
			: first(T1()), second(T2())
		{}
		
		pair(const T1& one, const T2& two)
			: first(one), second(two)
		{}

		pair(const pair<T1, T2>& src)
			: first(src.first), second(src.second)
		{}

		// Operator overload
		pair<T1, T2>& operator=(const pair<T1, T2>& other)
		{
			if (this != &other)
			{
				this->first = other.first;
				this->second = other.second;
			}
			return (*this);
		}
		
	};


	/* NON-MEMBER FUNCTION - SYNOPSIS
	
	template <typename T1,typename T2>
	pair<T1,T2> make_pair(T1 x, T2 y);

	template <typename T1,typename T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);

	template <typename T1,typename T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);
	
	*/
	template <typename T1,typename T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}

	template <typename T1,typename T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template <typename T1,typename T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <typename T1,typename T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		if (lhs.first != rhs.first)
		{
			return (lhs.first < rhs.first);
		}
		else
		{
			return (lhs.second < rhs.second);
		}
	}

	template <typename T1,typename T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		if (lhs.first != rhs.first)
		{
			return (lhs.first <= rhs.first);
		}
		else
		{
			return (lhs.second <= rhs.second);
		}
	}

	template <typename T1,typename T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		if (lhs.first != rhs.first)
		{
			return (lhs.first > rhs.first);
		}
		else
		{
			return (lhs.second > rhs.second);
		}
	}

	template <typename T1,typename T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{
		if (lhs.first != rhs.first)
		{
			return (lhs.first >= rhs.first);
		}
		else
		{
			return (lhs.second >= rhs.second);
		}
	}

}

#endif
