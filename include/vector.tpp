/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:09:20 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/25 18:21:43 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP


// Constructor/Destructor/Assignation
template <typename T, typename Allocator>
vector<T, Allocator>::vector()
	: _data(NULL), _size(0)
{}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type count, const T& value/*, const Allocator& alloc = Allocator()*/)
	: _data(new T[count]), _size(count)
{
	for (size_type i = 0; i < count; i++)
				_data[i] = value;
}

template <typename T, typename Allocator>
vector<T, Allocator>::~vector()
{
	delete [] _data;
}

#endif