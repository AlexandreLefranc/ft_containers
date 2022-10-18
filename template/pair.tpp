#ifndef PAIR_TPP
# define PAIR_TPP

// Constructors
template <typename T1, typename T2>
pair<T1, T2>::pair()
{}

template <typename T1, typename T2>
pair<T1, T2>::pair(T1 one, T2 two)
	: first(one), second(two)
{}

template <typename T1, typename T2>
pair<T1, T2>::pair(const pair<T1, T2>& other)
	: first(other.first), second(other.second)
{}

// Operator overload
template <typename T1, typename T2>
pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& other)
{
	if (this != &other)
	{
		this->first = other.first;
		this->second = other.second;
	}
	return (*this);
}

// Non-member function
template <typename T1,typename T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{
	return (pair<T1,T2>(x,y));
}

template <typename T1,typename T2>
bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
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


#endif