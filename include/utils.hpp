/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:02:33 by alefranc          #+#    #+#             */
/*   Updated: 2023/01/04 17:49:52 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{

/*********************************SYNOPSIS**************************************
*                                 ENABLE_IF                                    *
*                                 PAIR                                         *
*                                 EQUAL                                        *
*                                 IS_INTEGRAL                                  *
*******************************************************************************/

/*******************************************************************************
*                                 ENABLE_IF                                    *
*******************************************************************************/

template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

/*******************************************************************************
*                                   PAIR                                       *
*******************************************************************************/

template <typename T1, typename T2>
struct pair
{
	typedef	T1	first_type;
	typedef	T2	second_type;

	T1	first;
	T2	second;
	
	/* SYNOPSIS

	pair();
	pair(const T1& one, const T2& two);
	pair(const pair<T1, T2>& src);

	template< class U1, class U2 >
	pair( const pair<U1, U2>& p );

	pair<T1, T2>& operator=(const pair<T1, T2>& other);
	
	*/
	pair()
		: first(T1()), second(T2())
	{}

	pair(const T1& one, const T2& two)
		: first(one), second(two)
	{}

	pair(const pair<T1, T2>& src)
		: first(src.first), second(src.second)
	{}

	template< class U1, class U2 >
	pair( const pair<U1, U2>& p )
		: first(p.first), second(p.second)
	{}

	pair& operator=(const pair& other)
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

/*******************************************************************************
*                                   EQUAL                                      *
*******************************************************************************/

/* SYNOPSIS

template <typename InputIt1, typename InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);

template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p);

template <typename InputIt1, typename InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);

template <typename InputIt1, typename InputIt2, typename Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp);

*/
template <typename InputIt1, typename InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	while (first1 != last1)
	{
	if (!(*first1 == *first2))
		return false;
	++first1;
	++first2;
	}
	return true;
}

template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
{
	while (first1 != last1)
	{
		if (!p(*first1, *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <typename InputIt1, typename InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <typename InputIt1, typename InputIt2, typename Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

/*******************************************************************************
*                                  IS_INTEGRAL                                 *
*******************************************************************************/

template<class T, T v>
struct integral_constant 
{
	static const T value = v;

	typedef T								value_type;
	typedef ft::integral_constant<T, v>		type;

	operator value_type() const { return value; }
};

// Specialization alias
typedef ft::integral_constant<bool, true>	true_type;
typedef ft::integral_constant<bool, false>	false_type;

// Any non specialized type -> false_type
template <class T>
struct is_integral: public false_type {};

// List of specialized type -> true_type
template <>
struct is_integral<bool>: public true_type {};

template <>
struct is_integral<char>: public true_type {};

template <>
struct is_integral<wchar_t>: public true_type {};

template <>
struct is_integral<signed char>: public true_type {};

template <>
struct is_integral<short int>: public true_type {};

template <>
struct is_integral<int>: public true_type {};

template <>
struct is_integral<long int>: public true_type {};

template <>
struct is_integral<long long int>: public true_type {};

template <>
struct is_integral<unsigned char>: public true_type {};

template <>
struct is_integral<unsigned short int>: public true_type {};

template <>
struct is_integral<unsigned int>: public true_type {};

template <>
struct is_integral<unsigned long int>: public true_type {};

template <>
struct is_integral<unsigned long long int>: public true_type {};

template <>
struct is_integral<const bool>: public true_type {};

template <>
struct is_integral<const char>: public true_type {};

template <>
struct is_integral<const wchar_t>: public true_type {};

template <>
struct is_integral<const signed char>: public true_type {};

template <>
struct is_integral<const short int>: public true_type {};

template <>
struct is_integral<const int>: public true_type {};

template <>
struct is_integral<const long int>: public true_type {};

template <>
struct is_integral<const long long int>: public true_type {};

template <>
struct is_integral<const unsigned char>: public true_type {};

template <>
struct is_integral<const unsigned short int>: public true_type {};

template <>
struct is_integral<const unsigned int>: public true_type {};

template <>
struct is_integral<const unsigned long int>: public true_type {};

template <>
struct is_integral<const unsigned long long int>: public true_type {};
	
}

#endif