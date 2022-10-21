/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:34:28 by alefranc          #+#    #+#             */
/*   Updated: 2022/10/21 17:58:17 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
    template <typename InputIt1, typename InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);

    template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p);

    template <typename InputIt1, typename InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2);

    template <typename InputIt1, typename InputIt2, typename Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp);

    # include "equal.tpp"
}

#endif