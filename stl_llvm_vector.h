// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_VECTOR
#define _LIBCPP_VECTOR

/*
    vector synopsis

namespace std
{

template <class T, class Allocator = allocator<T> >
class vector
{
public:
    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    vector()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit vector(const allocator_type&);
    explicit vector(size_type n);
    explicit vector(size_type n, const allocator_type&); // C++14
    vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    vector(const vector& x);
    vector(vector&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    vector(initializer_list<value_type> il);
    vector(initializer_list<value_type> il, const allocator_type& a);
    ~vector();
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    vector& operator=(initializer_list<value_type> il);
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& u);
    void assign(initializer_list<value_type> il);

    allocator_type get_allocator() const noexcept;

    iterator               begin() noexcept;
    const_iterator         begin()   const noexcept;
    iterator               end() noexcept;
    const_iterator         end()     const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin()  const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend()    const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit() noexcept;

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    value_type*       data() noexcept;
    const value_type* data() const noexcept;

    void push_back(const value_type& x);
    void push_back(value_type&& x);
    template <class... Args>
        reference emplace_back(Args&&... args); // reference in C++17
    void pop_back();

    template <class... Args> iterator emplace(const_iterator position, Args&&... args);
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, value_type&& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() noexcept;

    void resize(size_type sz);
    void resize(size_type sz, const value_type& c);

    void swap(vector&)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

    bool __invariants() const;
};

template <class Allocator = allocator<T> >
class vector<bool, Allocator>
{
public:
    typedef bool                                     value_type;
    typedef Allocator                                allocator_type;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef iterator                                 pointer;
    typedef const_iterator                           const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    class reference
    {
    public:
        reference(const reference&) noexcept;
        operator bool() const noexcept;
        reference& operator=(bool x) noexcept;
        reference& operator=(const reference& x) noexcept;
        iterator operator&() const noexcept;
        void flip() noexcept;
    };

    class const_reference
    {
    public:
        const_reference(const reference&) noexcept;
        operator bool() const noexcept;
        const_iterator operator&() const noexcept;
    };

    vector()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit vector(const allocator_type&);
    explicit vector(size_type n, const allocator_type& a = allocator_type()); // C++14
    vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    vector(const vector& x);
    vector(vector&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    vector(initializer_list<value_type> il);
    vector(initializer_list<value_type> il, const allocator_type& a);
    ~vector();
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    vector& operator=(initializer_list<value_type> il);
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& u);
    void assign(initializer_list<value_type> il);

    allocator_type get_allocator() const noexcept;

    iterator               begin() noexcept;
    const_iterator         begin()   const noexcept;
    iterator               end() noexcept;
    const_iterator         end()     const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin()  const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend()    const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit() noexcept;

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    void push_back(const value_type& x);
    template <class... Args> reference emplace_back(Args&&... args);  // C++14; reference in C++17
    void pop_back();

    template <class... Args> iterator emplace(const_iterator position, Args&&... args);  // C++14
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() noexcept;

    void resize(size_type sz);
    void resize(size_type sz, value_type x);

    void swap(vector&)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17
    void flip() noexcept;

    bool __invariants() const;
};

template <class InputIterator, class Allocator = allocator<typename iterator_traits<InputIterator>::value_type>>
   vector(InputIterator, InputIterator, Allocator = Allocator())
   -> vector<typename iterator_traits<InputIterator>::value_type, Allocator>; // C++17

template <class Allocator> struct hash<std::vector<bool, Allocator>>;

template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class T, class Allocator, class U>
typename vector<T, Allocator>::size_type
erase(vector<T, Allocator>& c, const U& value);       // C++20
template <class T, class Allocator, class Predicate>
typename vector<T, Allocator>::size_type
erase_if(vector<T, Allocator>& c, Predicate pred);    // C++20

}  // std

*/

#include <__algorithm/copy.h>
#include <__algorithm/equal.h>
#include <__algorithm/fill_n.h>
#include <__algorithm/lexicographical_compare.h>
#include <__algorithm/remove.h>
#include <__algorithm/remove_if.h>
#include <__algorithm/rotate.h>
#include <__algorithm/unwrap_iter.h>
#include <__assert> // all public C++ headers provide the assertion handler
#include <__bit_reference>
#include <__config>
#include <__debug>
#include <__format/enable_insertable.h>
#include <__functional/hash.h>
#include <__functional/unary_function.h>
#include <__iterator/advance.h>
#include <__iterator/iterator_traits.h>
#include <__iterator/reverse_iterator.h>
#include <__iterator/wrap_iter.h>
#include <__memory/allocate_at_least.h>
#include <__memory/pointer_traits.h>
#include <__memory/swap_allocator.h>
#include <__memory/temp_value.h>
#include <__memory/uninitialized_algorithms.h>
#include <__memory_resource/polymorphic_allocator.h>
#include <__split_buffer>
#include <__type_traits/is_allocator.h>
#include <__type_traits/noexcept_move_assign_container.h>
#include <__utility/forward.h>
#include <__utility/move.h>
#include <__utility/swap.h>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iosfwd> // for forward declaration of vector
#include <limits>
#include <stdexcept>
#include <type_traits>
#include <version>

// standard-mandated includes

// [iterator.range]
#include <__iterator/access.h>
#include <__iterator/data.h>
#include <__iterator/empty.h>
#include <__iterator/reverse_access.h>
#include <__iterator/size.h>

// [vector.syn]
#include <compare>
#include <initializer_list>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_PUSH_MACROS
#include <__undef_macros>


_LIBCPP_BEGIN_NAMESPACE_STD

template <class _Tp, class _Allocator /* = allocator<_Tp> */>
class _LIBCPP_TEMPLATE_VIS vector
{
private:
    typedef allocator<_Tp>                                  __default_allocator_type;
public:
    typedef vector                                          __self;
    typedef _Tp                                             value_type;
    typedef _Allocator                                      allocator_type;
    typedef allocator_traits<allocator_type>                __alloc_traits;
    typedef value_type&                                     reference;
    typedef const value_type&                               const_reference;
    typedef typename __alloc_traits::size_type              size_type;
    typedef typename __alloc_traits::difference_type        difference_type;
    typedef typename __alloc_traits::pointer                pointer;
    typedef typename __alloc_traits::const_pointer          const_pointer;
    typedef __wrap_iter<pointer>                            iterator;
    typedef __wrap_iter<const_pointer>                      const_iterator;
    typedef std::reverse_iterator<iterator>               reverse_iterator;
    typedef std::reverse_iterator<const_iterator>         const_reverse_iterator;

    static_assert((is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

    static_assert(is_same<allocator_type, __rebind_alloc<__alloc_traits, value_type> >::value,
                  "[allocator.requirements] states that rebinding an allocator to the same type should result in the "
                  "original allocator");

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector() _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value)
    {
        std::__debug_db_insert_c(this);
    }
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI explicit vector(const allocator_type& __a)
#if _LIBCPP_STD_VER <= 14
        _NOEXCEPT_(is_nothrow_copy_constructible<allocator_type>::value)
#else
        _NOEXCEPT
#endif
        : __end_cap_(nullptr, __a)
    {
        std::__debug_db_insert_c(this);
    }
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI explicit vector(size_type __n);
#if _LIBCPP_STD_VER > 11
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI explicit vector(size_type __n, const allocator_type& __a);
#endif
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI vector(size_type __n, const value_type& __x);

    template <class = __enable_if_t<__is_allocator<_Allocator>::value> >
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector(size_type __n, const value_type& __x, const allocator_type& __a)
        : __end_cap_(nullptr, __a)
    {
      std::__debug_db_insert_c(this);
      if (__n > 0)
      {
          __vallocate(__n);
          __construct_at_end(__n, __x);
      }
    }

  template <class _InputIterator,
            __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible<value_type, typename iterator_traits<_InputIterator>::reference>::value,
                          int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI vector(_InputIterator __first, _InputIterator __last);
  template <class _InputIterator,
            __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible<value_type, typename iterator_traits<_InputIterator>::reference>::value,
                          int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a);

  template <
      class _ForwardIterator,
      __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible<value_type, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI vector(_ForwardIterator __first, _ForwardIterator __last);

  template <class _ForwardIterator,
      __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible<value_type, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    ~vector()
    {
      __annotate_delete();
      std::__debug_db_erase_c(this);

      if (this->__begin_ != nullptr)
      {
        __clear();
        __alloc_traits::deallocate(__alloc(), this->__begin_, capacity());
      }
    }

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI vector(const vector& __x);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI vector(const vector& __x, const __type_identity_t<allocator_type>& __a);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector& operator=(const vector& __x);

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector(initializer_list<value_type> __il);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector(initializer_list<value_type> __il, const allocator_type& __a);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector& operator=(initializer_list<value_type> __il)
        {assign(__il.begin(), __il.end()); return *this;}
#endif // !_LIBCPP_CXX03_LANG

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector(vector&& __x)
#if _LIBCPP_STD_VER > 14
        noexcept;
#else
        _NOEXCEPT_(is_nothrow_move_constructible<allocator_type>::value);
#endif

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector(vector&& __x, const __type_identity_t<allocator_type>& __a);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    vector& operator=(vector&& __x)
        _NOEXCEPT_((__noexcept_move_assign_container<_Allocator, __alloc_traits>::value));

  template <class _InputIterator,
            __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible<value_type, typename iterator_traits<_InputIterator>::reference>::value,
                          int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void assign(_InputIterator __first, _InputIterator __last);
  template <
      class _ForwardIterator,
      __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible<value_type, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void assign(_ForwardIterator __first, _ForwardIterator __last);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void assign(size_type __n, const_reference __u);

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void assign(initializer_list<value_type> __il)
        {assign(__il.begin(), __il.end());}
#endif

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    allocator_type get_allocator() const _NOEXCEPT
        {return this->__alloc();}

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator               begin() _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_iterator         begin()   const _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator               end() _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_iterator         end()     const _NOEXCEPT;

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    reverse_iterator       rbegin() _NOEXCEPT
        {return       reverse_iterator(end());}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const_reverse_iterator rbegin()  const _NOEXCEPT
        {return const_reverse_iterator(end());}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    reverse_iterator       rend() _NOEXCEPT
        {return       reverse_iterator(begin());}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const_reverse_iterator rend()    const _NOEXCEPT
        {return const_reverse_iterator(begin());}

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const_iterator         cbegin()  const _NOEXCEPT
        {return begin();}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const_iterator         cend()    const _NOEXCEPT
        {return end();}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const_reverse_iterator crbegin() const _NOEXCEPT
        {return rbegin();}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const_reverse_iterator crend()   const _NOEXCEPT
        {return rend();}

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    size_type size() const _NOEXCEPT
        {return static_cast<size_type>(this->__end_ - this->__begin_);}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    size_type capacity() const _NOEXCEPT
        {return static_cast<size_type>(__end_cap() - this->__begin_);}
    _LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    bool empty() const _NOEXCEPT
        {return this->__begin_ == this->__end_;}
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI size_type max_size() const _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void reserve(size_type __n);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void shrink_to_fit() _NOEXCEPT;

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI reference       operator[](size_type __n) _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_reference operator[](size_type __n) const _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI reference       at(size_type __n);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_reference at(size_type __n) const;

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI reference       front() _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "front() called on an empty vector");
        return *this->__begin_;
    }
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_reference front() const _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "front() called on an empty vector");
        return *this->__begin_;
    }
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI reference       back() _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "back() called on an empty vector");
        return *(this->__end_ - 1);
    }
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI const_reference back()  const _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "back() called on an empty vector");
        return *(this->__end_ - 1);
    }

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    value_type*       data() _NOEXCEPT
        {return std::__to_address(this->__begin_);}

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const value_type* data() const _NOEXCEPT
        {return std::__to_address(this->__begin_);}

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void push_back(const_reference __x);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void push_back(value_type&& __x);

    template <class... _Args>
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
#if _LIBCPP_STD_VER > 14
        reference emplace_back(_Args&&... __args);
#else
        void      emplace_back(_Args&&... __args);
#endif

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void pop_back();

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator insert(const_iterator __position, const_reference __x);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator insert(const_iterator __position, value_type&& __x);
    template <class... _Args>
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator emplace(const_iterator __position, _Args&&... __args);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    iterator insert(const_iterator __position, size_type __n, const_reference __x);

  template <class _InputIterator,
            __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible< value_type, typename iterator_traits<_InputIterator>::reference>::value,
                          int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator
  insert(const_iterator __position, _InputIterator __first, _InputIterator __last);

  template <
      class _ForwardIterator,
      __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible< value_type, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator
  insert(const_iterator __position, _ForwardIterator __first, _ForwardIterator __last);

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    iterator insert(const_iterator __position, initializer_list<value_type> __il)
        {return insert(__position, __il.begin(), __il.end());}
#endif

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator erase(const_iterator __position);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI iterator erase(const_iterator __first, const_iterator __last);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void clear() _NOEXCEPT
    {
        size_type __old_size = size();
        __clear();
        __annotate_shrink(__old_size);
        std::__debug_db_invalidate_all(this);
    }

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void resize(size_type __sz);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void resize(size_type __sz, const_reference __x);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void swap(vector&)
#if _LIBCPP_STD_VER >= 14
        _NOEXCEPT;
#else
        _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value ||
                    __is_nothrow_swappable<allocator_type>::value);
#endif

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI bool __invariants() const;

#ifdef _LIBCPP_ENABLE_DEBUG_MODE

    bool __dereferenceable(const const_iterator* __i) const;
    bool __decrementable(const const_iterator* __i) const;
    bool __addable(const const_iterator* __i, ptrdiff_t __n) const;
    bool __subscriptable(const const_iterator* __i, ptrdiff_t __n) const;

#endif // _LIBCPP_ENABLE_DEBUG_MODE

private:
    pointer __begin_ = nullptr;
    pointer __end_ = nullptr;
    __compressed_pair<pointer, allocator_type> __end_cap_ =
        __compressed_pair<pointer, allocator_type>(nullptr, __default_init_tag());

    _LIBCPP_HIDE_FROM_ABI void __invalidate_iterators_past(pointer __new_last);

    //  Allocate space for __n objects
    //  throws length_error if __n > max_size()
    //  throws (probably bad_alloc) if memory run out
    //  Precondition:  __begin_ == __end_ == __end_cap() == 0
    //  Precondition:  __n > 0
    //  Postcondition:  capacity() >= __n
    //  Postcondition:  size() == 0
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __vallocate(size_type __n) {
        if (__n > max_size())
            __throw_length_error();
        auto __allocation = std::__allocate_at_least(__alloc(), __n);
        __begin_ = __allocation.ptr;
        __end_ = __allocation.ptr;
        __end_cap() = __begin_ + __allocation.count;
        __annotate_new(0);
    }

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __vdeallocate() _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI size_type __recommend(size_type __new_size) const;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __construct_at_end(size_type __n);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void __construct_at_end(size_type __n, const_reference __x);

  template <class _ForwardIterator, __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value, int> = 0>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void
  __construct_at_end(_ForwardIterator __first, _ForwardIterator __last, size_type __n);

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __append(size_type __n);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __append(size_type __n, const_reference __x);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    iterator       __make_iter(pointer __p) _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    const_iterator __make_iter(const_pointer __p) const _NOEXCEPT;
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI pointer __swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v, pointer __p);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __move_range(pointer __from_s, pointer __from_e, pointer __to);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __move_assign(vector& __c, true_type)
        _NOEXCEPT_(is_nothrow_move_assignable<allocator_type>::value);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI void __move_assign(vector& __c, false_type)
        _NOEXCEPT_(__alloc_traits::is_always_equal::value);
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void __destruct_at_end(pointer __new_last) _NOEXCEPT
    {
        if (!__libcpp_is_constant_evaluated())
            __invalidate_iterators_past(__new_last);
        size_type __old_size = size();
        __base_destruct_at_end(__new_last);
        __annotate_shrink(__old_size);
    }

    template <class _Up>
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    inline void __push_back_slow_path(_Up&& __x);

    template <class... _Args>
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    inline void __emplace_back_slow_path(_Args&&... __args);

    // The following functions are no-ops outside of AddressSanitizer mode.
    // We call annotatations only for the default Allocator because other allocators
    // may not meet the AddressSanitizer alignment constraints.
    // See the documentation for __sanitizer_annotate_contiguous_container for more details.
#ifndef _LIBCPP_HAS_NO_ASAN
    _LIBCPP_CONSTEXPR_SINCE_CXX20
    void __annotate_contiguous_container(const void *__beg, const void *__end,
                                         const void *__old_mid,
                                         const void *__new_mid) const
    {

      if (!__libcpp_is_constant_evaluated() && __beg && is_same<allocator_type, __default_allocator_type>::value)
        __sanitizer_annotate_contiguous_container(__beg, __end, __old_mid, __new_mid);
    }
#else
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void __annotate_contiguous_container(const void*, const void*, const void*,
                                         const void*) const _NOEXCEPT {}
#endif
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void __annotate_new(size_type __current_size) const _NOEXCEPT {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + capacity(), data() + __current_size);
    }

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void __annotate_delete() const _NOEXCEPT {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + size(), data() + capacity());
    }

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void __annotate_increase(size_type __n) const _NOEXCEPT
    {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + size(), data() + size() + __n);
    }

    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    void __annotate_shrink(size_type __old_size) const _NOEXCEPT
    {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + __old_size, data() + size());
    }

  struct _ConstructTransaction {
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
    explicit _ConstructTransaction(vector &__v, size_type __n)
      : __v_(__v), __pos_(__v.__end_), __new_end_(__v.__end_ + __n) {
#ifndef _LIBCPP_HAS_NO_ASAN
      __v_.__annotate_increase(__n);
#endif
    }
    _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI ~_ConstructTransaction() {
      __v_.__end_ = __pos_;
#ifndef _LIBCPP_HAS_NO_ASAN
      if (__pos_ != __new_end_) {
        __v_.__annotate_shrink(__new_end_ - __v_.__begin_);
      }
#endif
    }

    vector &__v_;
    pointer __pos_;
    const_pointer const __new_end_;

  private:
    _ConstructTransaction(_ConstructTransaction const&) = delete;
    _ConstructTransaction& operator=(_ConstructTransaction const&) = delete;
  };

  template <class ..._Args>
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __construct_one_at_end(_Args&& ...__args) {
    _ConstructTransaction __tx(*this, 1);
    __alloc_traits::construct(this->__alloc(), std::__to_address(__tx.__pos_),
        std::forward<_Args>(__args)...);
    ++__tx.__pos_;
  }

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  allocator_type& __alloc() _NOEXCEPT
      {return this->__end_cap_.second();}
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  const allocator_type& __alloc() const _NOEXCEPT
      {return this->__end_cap_.second();}
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  pointer& __end_cap() _NOEXCEPT
      {return this->__end_cap_.first();}
  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  const pointer& __end_cap() const _NOEXCEPT
      {return this->__end_cap_.first();}

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __clear() _NOEXCEPT {__base_destruct_at_end(this->__begin_);}

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __base_destruct_at_end(pointer __new_last) _NOEXCEPT {
    pointer __soon_to_be_end = this->__end_;
    while (__new_last != __soon_to_be_end)
        __alloc_traits::destroy(__alloc(), std::__to_address(--__soon_to_be_end));
    this->__end_ = __new_last;
  }

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __copy_assign_alloc(const vector& __c)
      {__copy_assign_alloc(__c, integral_constant<bool,
                    __alloc_traits::propagate_on_container_copy_assignment::value>());}

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __move_assign_alloc(vector& __c)
      _NOEXCEPT_(
          !__alloc_traits::propagate_on_container_move_assignment::value ||
          is_nothrow_move_assignable<allocator_type>::value)
      {__move_assign_alloc(__c, integral_constant<bool,
                    __alloc_traits::propagate_on_container_move_assignment::value>());}

  _LIBCPP_NORETURN _LIBCPP_HIDE_FROM_ABI
  void __throw_length_error() const {
      std::__throw_length_error("vector");
  }

  _LIBCPP_NORETURN _LIBCPP_HIDE_FROM_ABI
  void __throw_out_of_range() const {
      std::__throw_out_of_range("vector");
  }

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __copy_assign_alloc(const vector& __c, true_type)
  {
    if (__alloc() != __c.__alloc())
    {
      __clear();
      __alloc_traits::deallocate(__alloc(), this->__begin_, capacity());
      this->__begin_ = this->__end_ = __end_cap() = nullptr;
    }
    __alloc() = __c.__alloc();
  }

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __copy_assign_alloc(const vector&, false_type)
  {}

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __move_assign_alloc(vector& __c, true_type)
      _NOEXCEPT_(is_nothrow_move_assignable<allocator_type>::value)
  {
    __alloc() = std::move(__c.__alloc());
  }

  _LIBCPP_CONSTEXPR_SINCE_CXX20 _LIBCPP_HIDE_FROM_ABI
  void __move_assign_alloc(vector&, false_type)
      _NOEXCEPT
  {}
};

#if _LIBCPP_STD_VER >= 17
template<class _InputIterator,
         class _Alloc = allocator<__iter_value_type<_InputIterator>>,
         class = enable_if_t<__is_cpp17_input_iterator<_InputIterator>::value>,
         class = enable_if_t<__is_allocator<_Alloc>::value>
         >
vector(_InputIterator, _InputIterator)
  -> vector<__iter_value_type<_InputIterator>, _Alloc>;

template<class _InputIterator,
         class _Alloc,
         class = enable_if_t<__is_cpp17_input_iterator<_InputIterator>::value>,
         class = enable_if_t<__is_allocator<_Alloc>::value>
         >
vector(_InputIterator, _InputIterator, _Alloc)
  -> vector<__iter_value_type<_InputIterator>, _Alloc>;
#endif

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v)
{
    __annotate_delete();
    using _RevIter = std::reverse_iterator<pointer>;
    __v.__begin_   = std::__uninitialized_allocator_move_if_noexcept(
                       __alloc(), _RevIter(__end_), _RevIter(__begin_), _RevIter(__v.__begin_))
                       .base();
    std::swap(this->__begin_, __v.__begin_);
    std::swap(this->__end_, __v.__end_);
    std::swap(this->__end_cap(), __v.__end_cap());
    __v.__first_ = __v.__begin_;
    __annotate_new(size());
    std::__debug_db_invalidate_all(this);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::pointer
vector<_Tp, _Allocator>::__swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v, pointer __p)
{
    __annotate_delete();
    pointer __r = __v.__begin_;
    using _RevIter = std::reverse_iterator<pointer>;
    __v.__begin_   = std::__uninitialized_allocator_move_if_noexcept(
                       __alloc(), _RevIter(__p), _RevIter(__begin_), _RevIter(__v.__begin_))
                       .base();
    __v.__end_ = std::__uninitialized_allocator_move_if_noexcept(__alloc(), __p, __end_, __v.__end_);
    std::swap(this->__begin_, __v.__begin_);
    std::swap(this->__end_, __v.__end_);
    std::swap(this->__end_cap(), __v.__end_cap());
    __v.__first_ = __v.__begin_;
    __annotate_new(size());
    std::__debug_db_invalidate_all(this);
    return __r;
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__vdeallocate() _NOEXCEPT
{
    if (this->__begin_ != nullptr)
    {
        clear();
        __alloc_traits::deallocate(this->__alloc(), this->__begin_, capacity());
        this->__begin_ = this->__end_ = this->__end_cap() = nullptr;
    }
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::size_type
vector<_Tp, _Allocator>::max_size() const _NOEXCEPT
{
    return std::min<size_type>(__alloc_traits::max_size(this->__alloc()),
                                 numeric_limits<difference_type>::max());
}

//  Precondition:  __new_size > capacity()
template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::size_type
vector<_Tp, _Allocator>::__recommend(size_type __new_size) const
{
    const size_type __ms = max_size();
    if (__new_size > __ms)
        this->__throw_length_error();
    const size_type __cap = capacity();
    if (__cap >= __ms / 2)
        return __ms;
    return std::max<size_type>(2 * __cap, __new_size);
}

//  Default constructs __n objects starting at __end_
//  throws if construction throws
//  Precondition:  __n > 0
//  Precondition:  size() + __n <= capacity()
//  Postcondition:  size() == size() + __n
template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__construct_at_end(size_type __n)
{
    _ConstructTransaction __tx(*this, __n);
    const_pointer __new_end = __tx.__new_end_;
    for (pointer __pos = __tx.__pos_; __pos != __new_end; __tx.__pos_ = ++__pos) {
        __alloc_traits::construct(this->__alloc(), std::__to_address(__pos));
    }
}

//  Copy constructs __n objects starting at __end_ from __x
//  throws if construction throws
//  Precondition:  __n > 0
//  Precondition:  size() + __n <= capacity()
//  Postcondition:  size() == old size() + __n
//  Postcondition:  [i] == __x for all i in [size() - __n, __n)
template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline
void
vector<_Tp, _Allocator>::__construct_at_end(size_type __n, const_reference __x)
{
    _ConstructTransaction __tx(*this, __n);
    const_pointer __new_end = __tx.__new_end_;
    for (pointer __pos = __tx.__pos_; __pos != __new_end; __tx.__pos_ = ++__pos) {
        __alloc_traits::construct(this->__alloc(), std::__to_address(__pos), __x);
    }
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator, __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value, int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<_Tp, _Allocator>::__construct_at_end(_ForwardIterator __first, _ForwardIterator __last, size_type __n)
{
  _ConstructTransaction __tx(*this, __n);
  __tx.__pos_ = std::__uninitialized_allocator_copy(__alloc(), __first, __last, __tx.__pos_);
}

//  Default constructs __n objects starting at __end_
//  throws if construction throws
//  Postcondition:  size() == size() + __n
//  Exception safety: strong.
template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__append(size_type __n)
{
    if (static_cast<size_type>(this->__end_cap() - this->__end_) >= __n)
        this->__construct_at_end(__n);
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), size(), __a);
        __v.__construct_at_end(__n);
        __swap_out_circular_buffer(__v);
    }
}

//  Default constructs __n objects starting at __end_
//  throws if construction throws
//  Postcondition:  size() == size() + __n
//  Exception safety: strong.
template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__append(size_type __n, const_reference __x)
{
    if (static_cast<size_type>(this->__end_cap() - this->__end_) >= __n)
        this->__construct_at_end(__n, __x);
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), size(), __a);
        __v.__construct_at_end(__n, __x);
        __swap_out_circular_buffer(__v);
    }
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(size_type __n)
{
    std::__debug_db_insert_c(this);
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n);
    }
}

#if _LIBCPP_STD_VER > 11
template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(size_type __n, const allocator_type& __a)
    : __end_cap_(nullptr, __a)
{
    std::__debug_db_insert_c(this);
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n);
    }
}
#endif

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(size_type __n, const value_type& __x)
{
    std::__debug_db_insert_c(this);
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, __x);
    }
}

template <class _Tp, class _Allocator>
template <class _InputIterator, __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible<_Tp, typename iterator_traits<_InputIterator>::reference>::value,
                          int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(_InputIterator __first, _InputIterator __last)
{
    std::__debug_db_insert_c(this);
    for (; __first != __last; ++__first)
        emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _InputIterator, __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible<_Tp, typename iterator_traits<_InputIterator>::reference>::value,
                          int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a)
    : __end_cap_(nullptr, __a)
{
    std::__debug_db_insert_c(this);
    for (; __first != __last; ++__first)
        emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator, __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible<_Tp, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(_ForwardIterator __first, _ForwardIterator __last)
{
    std::__debug_db_insert_c(this);
    size_type __n = static_cast<size_type>(std::distance(__first, __last));
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last, __n);
    }
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator, __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible<_Tp, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a)
    : __end_cap_(nullptr, __a)
{
    std::__debug_db_insert_c(this);
    size_type __n = static_cast<size_type>(std::distance(__first, __last));
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last, __n);
    }
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(const vector& __x)
    : __end_cap_(nullptr, __alloc_traits::select_on_container_copy_construction(__x.__alloc()))
{
    std::__debug_db_insert_c(this);
    size_type __n = __x.size();
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__x.__begin_, __x.__end_, __n);
    }
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<_Tp, _Allocator>::vector(const vector& __x, const __type_identity_t<allocator_type>& __a)
    : __end_cap_(nullptr, __a)
{
    std::__debug_db_insert_c(this);
    size_type __n = __x.size();
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__x.__begin_, __x.__end_, __n);
    }
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
vector<_Tp, _Allocator>::vector(vector&& __x)
#if _LIBCPP_STD_VER > 14
        noexcept
#else
        _NOEXCEPT_(is_nothrow_move_constructible<allocator_type>::value)
#endif
    : __end_cap_(nullptr, std::move(__x.__alloc()))
{
    std::__debug_db_insert_c(this);
    std::__debug_db_swap(this, std::addressof(__x));
    this->__begin_ = __x.__begin_;
    this->__end_ = __x.__end_;
    this->__end_cap() = __x.__end_cap();
    __x.__begin_ = __x.__end_ = __x.__end_cap() = nullptr;
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
vector<_Tp, _Allocator>::vector(vector&& __x, const __type_identity_t<allocator_type>& __a)
    : __end_cap_(nullptr, __a)
{
    std::__debug_db_insert_c(this);
    if (__a == __x.__alloc())
    {
        this->__begin_ = __x.__begin_;
        this->__end_ = __x.__end_;
        this->__end_cap() = __x.__end_cap();
        __x.__begin_ = __x.__end_ = __x.__end_cap() = nullptr;
        std::__debug_db_swap(this, std::addressof(__x));
    }
    else
    {
        typedef move_iterator<iterator> _Ip;
        assign(_Ip(__x.begin()), _Ip(__x.end()));
    }
}

#ifndef _LIBCPP_CXX03_LANG

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
vector<_Tp, _Allocator>::vector(initializer_list<value_type> __il)
{
    std::__debug_db_insert_c(this);
    if (__il.size() > 0)
    {
        __vallocate(__il.size());
        __construct_at_end(__il.begin(), __il.end(), __il.size());
    }
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
vector<_Tp, _Allocator>::vector(initializer_list<value_type> __il, const allocator_type& __a)
    : __end_cap_(nullptr, __a)
{
    std::__debug_db_insert_c(this);
    if (__il.size() > 0)
    {
        __vallocate(__il.size());
        __construct_at_end(__il.begin(), __il.end(), __il.size());
    }
}

#endif // _LIBCPP_CXX03_LANG

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
vector<_Tp, _Allocator>&
vector<_Tp, _Allocator>::operator=(vector&& __x)
    _NOEXCEPT_((__noexcept_move_assign_container<_Allocator, __alloc_traits>::value))
{
    __move_assign(__x, integral_constant<bool,
          __alloc_traits::propagate_on_container_move_assignment::value>());
    return *this;
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__move_assign(vector& __c, false_type)
    _NOEXCEPT_(__alloc_traits::is_always_equal::value)
{
    if (__alloc() != __c.__alloc())
    {
        typedef move_iterator<iterator> _Ip;
        assign(_Ip(__c.begin()), _Ip(__c.end()));
    }
    else
        __move_assign(__c, true_type());
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__move_assign(vector& __c, true_type)
    _NOEXCEPT_(is_nothrow_move_assignable<allocator_type>::value)
{
    __vdeallocate();
    __move_assign_alloc(__c); // this can throw
    this->__begin_ = __c.__begin_;
    this->__end_ = __c.__end_;
    this->__end_cap() = __c.__end_cap();
    __c.__begin_ = __c.__end_ = __c.__end_cap() = nullptr;
    std::__debug_db_swap(this, std::addressof(__c));
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
vector<_Tp, _Allocator>&
vector<_Tp, _Allocator>::operator=(const vector& __x)
{
    if (this != std::addressof(__x))
    {
        __copy_assign_alloc(__x);
        assign(__x.__begin_, __x.__end_);
    }
    return *this;
}

template <class _Tp, class _Allocator>
template <class _InputIterator, __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible<_Tp, typename iterator_traits<_InputIterator>::reference>::value,
                          int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<_Tp, _Allocator>::assign(_InputIterator __first, _InputIterator __last)
{
    clear();
    for (; __first != __last; ++__first)
        emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator, __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible<_Tp, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<_Tp, _Allocator>::assign(_ForwardIterator __first, _ForwardIterator __last)
{
    size_type __new_size = static_cast<size_type>(std::distance(__first, __last));
    if (__new_size <= capacity())
    {
        _ForwardIterator __mid = __last;
        bool __growing = false;
        if (__new_size > size())
        {
            __growing = true;
            __mid =  __first;
            std::advance(__mid, size());
        }
        pointer __m = std::copy(__first, __mid, this->__begin_);
        if (__growing)
            __construct_at_end(__mid, __last, __new_size - size());
        else
            this->__destruct_at_end(__m);
    }
    else
    {
        __vdeallocate();
        __vallocate(__recommend(__new_size));
        __construct_at_end(__first, __last, __new_size);
    }
    std::__debug_db_invalidate_all(this);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::assign(size_type __n, const_reference __u)
{
    if (__n <= capacity())
    {
        size_type __s = size();
        std::fill_n(this->__begin_, std::min(__n, __s), __u);
        if (__n > __s)
            __construct_at_end(__n - __s, __u);
        else
            this->__destruct_at_end(this->__begin_ + __n);
    }
    else
    {
        __vdeallocate();
        __vallocate(__recommend(static_cast<size_type>(__n)));
        __construct_at_end(__n, __u);
    }
    std::__debug_db_invalidate_all(this);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::begin() _NOEXCEPT
{
    return iterator(this, this->__begin_);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::const_iterator
vector<_Tp, _Allocator>::begin() const _NOEXCEPT
{
    return const_iterator(this, this->__begin_);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::end() _NOEXCEPT
{
    return iterator(this, this->__end_);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::const_iterator
vector<_Tp, _Allocator>::end() const _NOEXCEPT
{
    return const_iterator(this, this->__end_);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::reference
vector<_Tp, _Allocator>::operator[](size_type __n) _NOEXCEPT
{
    _LIBCPP_ASSERT(__n < size(), "vector[] index out of bounds");
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::const_reference
vector<_Tp, _Allocator>::operator[](size_type __n) const _NOEXCEPT
{
    _LIBCPP_ASSERT(__n < size(), "vector[] index out of bounds");
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::reference
vector<_Tp, _Allocator>::at(size_type __n)
{
    if (__n >= size())
        this->__throw_out_of_range();
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::const_reference
vector<_Tp, _Allocator>::at(size_type __n) const
{
    if (__n >= size())
        this->__throw_out_of_range();
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::reserve(size_type __n)
{
    if (__n > capacity())
    {
        if (__n > max_size())
            this->__throw_length_error();
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__n, size(), __a);
        __swap_out_circular_buffer(__v);
    }
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::shrink_to_fit() _NOEXCEPT
{
    if (capacity() > size())
    {
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif // _LIBCPP_NO_EXCEPTIONS
            allocator_type& __a = this->__alloc();
            __split_buffer<value_type, allocator_type&> __v(size(), size(), __a);
            __swap_out_circular_buffer(__v);
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
        }
#endif // _LIBCPP_NO_EXCEPTIONS
    }
}

template <class _Tp, class _Allocator>
template <class _Up>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__push_back_slow_path(_Up&& __x)
{
    allocator_type& __a = this->__alloc();
    __split_buffer<value_type, allocator_type&> __v(__recommend(size() + 1), size(), __a);
    // __v.push_back(std::forward<_Up>(__x));
    __alloc_traits::construct(__a, std::__to_address(__v.__end_), std::forward<_Up>(__x));
    __v.__end_++;
    __swap_out_circular_buffer(__v);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
void
vector<_Tp, _Allocator>::push_back(const_reference __x)
{
    if (this->__end_ != this->__end_cap())
    {
        __construct_one_at_end(__x);
    }
    else
        __push_back_slow_path(__x);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
void
vector<_Tp, _Allocator>::push_back(value_type&& __x)
{
    if (this->__end_ < this->__end_cap())
    {
        __construct_one_at_end(std::move(__x));
    }
    else
        __push_back_slow_path(std::move(__x));
}

template <class _Tp, class _Allocator>
template <class... _Args>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__emplace_back_slow_path(_Args&&... __args)
{
    allocator_type& __a = this->__alloc();
    __split_buffer<value_type, allocator_type&> __v(__recommend(size() + 1), size(), __a);
//    __v.emplace_back(std::forward<_Args>(__args)...);
    __alloc_traits::construct(__a, std::__to_address(__v.__end_), std::forward<_Args>(__args)...);
    __v.__end_++;
    __swap_out_circular_buffer(__v);
}

template <class _Tp, class _Allocator>
template <class... _Args>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline
#if _LIBCPP_STD_VER > 14
typename vector<_Tp, _Allocator>::reference
#else
void
#endif
vector<_Tp, _Allocator>::emplace_back(_Args&&... __args)
{
    if (this->__end_ < this->__end_cap())
    {
        __construct_one_at_end(std::forward<_Args>(__args)...);
    }
    else
        __emplace_back_slow_path(std::forward<_Args>(__args)...);
#if _LIBCPP_STD_VER > 14
    return this->back();
#endif
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline
void
vector<_Tp, _Allocator>::pop_back()
{
    _LIBCPP_ASSERT(!empty(), "vector::pop_back called on an empty vector");
    this->__destruct_at_end(this->__end_ - 1);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::erase(const_iterator __position)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__position)) == this,
                         "vector::erase(iterator) called with an iterator not referring to this vector");
    _LIBCPP_ASSERT(__position != end(),
        "vector::erase(iterator) called with a non-dereferenceable iterator");
    difference_type __ps = __position - cbegin();
    pointer __p = this->__begin_ + __ps;
    this->__destruct_at_end(std::move(__p + 1, this->__end_, __p));
    if (!__libcpp_is_constant_evaluated())
        this->__invalidate_iterators_past(__p - 1);
    iterator __r = iterator(this, __p);
    return __r;
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::erase(const_iterator __first, const_iterator __last)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__first)) == this,
                         "vector::erase(iterator, iterator) called with an iterator not referring to this vector");
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__last)) == this,
                         "vector::erase(iterator, iterator) called with an iterator not referring to this vector");

    _LIBCPP_ASSERT(__first <= __last, "vector::erase(first, last) called with invalid range");
    pointer __p = this->__begin_ + (__first - begin());
    if (__first != __last) {
        this->__destruct_at_end(std::move(__p + (__last - __first), this->__end_, __p));
        if (!__libcpp_is_constant_evaluated())
            this->__invalidate_iterators_past(__p - 1);
    }
    iterator __r = iterator(this, __p);
    return __r;
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::__move_range(pointer __from_s, pointer __from_e, pointer __to)
{
    pointer __old_last = this->__end_;
    difference_type __n = __old_last - __to;
    {
      pointer __i = __from_s + __n;
      _ConstructTransaction __tx(*this, __from_e - __i);
      for (pointer __pos = __tx.__pos_; __i < __from_e;
           ++__i, (void) ++__pos, __tx.__pos_ = __pos) {
          __alloc_traits::construct(this->__alloc(),
                                    std::__to_address(__pos),
                                    std::move(*__i));
      }
    }
    std::move_backward(__from_s, __from_s + __n, __old_last);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::insert(const_iterator __position, const_reference __x)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__position)) == this,
                         "vector::insert(iterator, x) called with an iterator not referring to this vector");
    pointer __p = this->__begin_ + (__position - begin());
    // We can't compare unrelated pointers inside constant expressions
    if (!__libcpp_is_constant_evaluated() && this->__end_ < this->__end_cap())
    {
        if (__p == this->__end_)
        {
            __construct_one_at_end(__x);
        }
        else
        {
            __move_range(__p, this->__end_, __p + 1);
            const_pointer __xr = pointer_traits<const_pointer>::pointer_to(__x);
            if (__p <= __xr && __xr < this->__end_)
                ++__xr;
            *__p = *__xr;
        }
    }
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + 1), __p - this->__begin_, __a);
        __v.push_back(__x);
        __p = __swap_out_circular_buffer(__v, __p);
    }
    return iterator(this, __p);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::insert(const_iterator __position, value_type&& __x)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__position)) == this,
                         "vector::insert(iterator, x) called with an iterator not referring to this vector");
    pointer __p = this->__begin_ + (__position - begin());
    if (this->__end_ < this->__end_cap())
    {
        if (__p == this->__end_)
        {
            __construct_one_at_end(std::move(__x));
        }
        else
        {
            __move_range(__p, this->__end_, __p + 1);
            *__p = std::move(__x);
        }
    }
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + 1), __p - this->__begin_, __a);
        __v.push_back(std::move(__x));
        __p = __swap_out_circular_buffer(__v, __p);
    }
    return iterator(this, __p);
}

template <class _Tp, class _Allocator>
template <class... _Args>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::emplace(const_iterator __position, _Args&&... __args)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__position)) == this,
                         "vector::emplace(iterator, x) called with an iterator not referring to this vector");
    pointer __p = this->__begin_ + (__position - begin());
    if (this->__end_ < this->__end_cap())
    {
        if (__p == this->__end_)
        {
            __construct_one_at_end(std::forward<_Args>(__args)...);
        }
        else
        {
            __temp_value<value_type, _Allocator> __tmp(this->__alloc(), std::forward<_Args>(__args)...);
            __move_range(__p, this->__end_, __p + 1);
            *__p = std::move(__tmp.get());
        }
    }
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + 1), __p - this->__begin_, __a);
        __v.emplace_back(std::forward<_Args>(__args)...);
        __p = __swap_out_circular_buffer(__v, __p);
    }
    return iterator(this, __p);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::insert(const_iterator __position, size_type __n, const_reference __x)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__position)) == this,
                         "vector::insert(iterator, n, x) called with an iterator not referring to this vector");
    pointer __p = this->__begin_ + (__position - begin());
    if (__n > 0)
    {
        // We can't compare unrelated pointers inside constant expressions
        if (!__libcpp_is_constant_evaluated() && __n <= static_cast<size_type>(this->__end_cap() - this->__end_))
        {
            size_type __old_n = __n;
            pointer __old_last = this->__end_;
            if (__n > static_cast<size_type>(this->__end_ - __p))
            {
                size_type __cx = __n - (this->__end_ - __p);
                __construct_at_end(__cx, __x);
                __n -= __cx;
            }
            if (__n > 0)
            {
                __move_range(__p, __old_last, __p + __old_n);
                const_pointer __xr = pointer_traits<const_pointer>::pointer_to(__x);
                if (__p <= __xr && __xr < this->__end_)
                    __xr += __old_n;
                std::fill_n(__p, __n, *__xr);
            }
        }
        else
        {
            allocator_type& __a = this->__alloc();
            __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), __p - this->__begin_, __a);
            __v.__construct_at_end(__n, __x);
            __p = __swap_out_circular_buffer(__v, __p);
        }
    }
    return iterator(this, __p);
}

template <class _Tp, class _Allocator>
template <class _InputIterator, __enable_if_t<__is_exactly_cpp17_input_iterator<_InputIterator>::value &&
                              is_constructible<_Tp, typename iterator_traits<_InputIterator>::reference>::value,
                          int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20 typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::insert(const_iterator __position, _InputIterator __first, _InputIterator __last)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__position)) == this,
                         "vector::insert(iterator, range) called with an iterator not referring to this vector");
    difference_type __off = __position - begin();
    pointer __p = this->__begin_ + __off;
    allocator_type& __a = this->__alloc();
    pointer __old_last = this->__end_;
    for (; this->__end_ != this->__end_cap() && __first != __last; ++__first)
    {
        __construct_one_at_end(*__first);
    }
    __split_buffer<value_type, allocator_type&> __v(__a);
    if (__first != __last)
    {
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif // _LIBCPP_NO_EXCEPTIONS
            __v.__construct_at_end(__first, __last);
            difference_type __old_size = __old_last - this->__begin_;
            difference_type __old_p = __p - this->__begin_;
            reserve(__recommend(size() + __v.size()));
            __p = this->__begin_ + __old_p;
            __old_last = this->__begin_ + __old_size;
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            erase(iterator(this, __old_last), end());
            throw;
        }
#endif // _LIBCPP_NO_EXCEPTIONS
    }
    __p = std::rotate(__p, __old_last, this->__end_);
    insert(iterator(this, __p), std::make_move_iterator(__v.begin()),
                                std::make_move_iterator(__v.end()));
    return begin() + __off;
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator, __enable_if_t<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                        is_constructible<_Tp, typename iterator_traits<_ForwardIterator>::reference>::value,
                    int> >
_LIBCPP_CONSTEXPR_SINCE_CXX20 typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::insert(const_iterator __position, _ForwardIterator __first, _ForwardIterator __last)
{
    _LIBCPP_DEBUG_ASSERT(__get_const_db()->__find_c_from_i(std::addressof(__position)) == this,
                         "vector::insert(iterator, range) called with an iterator not referring to this vector");
    pointer __p = this->__begin_ + (__position - begin());
    difference_type __n = std::distance(__first, __last);
    if (__n > 0)
    {
        if (__n <= this->__end_cap() - this->__end_)
        {
            size_type __old_n = __n;
            pointer __old_last = this->__end_;
            _ForwardIterator __m = __last;
            difference_type __dx = this->__end_ - __p;
            if (__n > __dx)
            {
                __m = __first;
                difference_type __diff = this->__end_ - __p;
                std::advance(__m, __diff);
                __construct_at_end(__m, __last, __n - __diff);
                __n = __dx;
            }
            if (__n > 0)
            {
                __move_range(__p, __old_last, __p + __old_n);
                std::copy(__first, __m, __p);
            }
        }
        else
        {
            allocator_type& __a = this->__alloc();
            __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), __p - this->__begin_, __a);
            __v.__construct_at_end(__first, __last);
            __p = __swap_out_circular_buffer(__v, __p);
        }
    }
    return iterator(this, __p);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::resize(size_type __sz)
{
    size_type __cs = size();
    if (__cs < __sz)
        this->__append(__sz - __cs);
    else if (__cs > __sz)
        this->__destruct_at_end(this->__begin_ + __sz);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::resize(size_type __sz, const_reference __x)
{
    size_type __cs = size();
    if (__cs < __sz)
        this->__append(__sz - __cs, __x);
    else if (__cs > __sz)
        this->__destruct_at_end(this->__begin_ + __sz);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<_Tp, _Allocator>::swap(vector& __x)
#if _LIBCPP_STD_VER >= 14
    _NOEXCEPT
#else
    _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value ||
                __is_nothrow_swappable<allocator_type>::value)
#endif
{
    _LIBCPP_ASSERT(__alloc_traits::propagate_on_container_swap::value ||
                   this->__alloc() == __x.__alloc(),
                   "vector::swap: Either propagate_on_container_swap must be true"
                   " or the allocators must compare equal");
    std::swap(this->__begin_, __x.__begin_);
    std::swap(this->__end_, __x.__end_);
    std::swap(this->__end_cap(), __x.__end_cap());
    std::__swap_allocator(this->__alloc(), __x.__alloc(),
        integral_constant<bool,__alloc_traits::propagate_on_container_swap::value>());
    std::__debug_db_swap(this, std::addressof(__x));
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
bool
vector<_Tp, _Allocator>::__invariants() const
{
    if (this->__begin_ == nullptr)
    {
        if (this->__end_ != nullptr || this->__end_cap() != nullptr)
            return false;
    }
    else
    {
        if (this->__begin_ > this->__end_)
            return false;
        if (this->__begin_ == this->__end_cap())
            return false;
        if (this->__end_ > this->__end_cap())
            return false;
    }
    return true;
}

#ifdef _LIBCPP_ENABLE_DEBUG_MODE

template <class _Tp, class _Allocator>
bool
vector<_Tp, _Allocator>::__dereferenceable(const const_iterator* __i) const
{
    return this->__begin_ <= __i->base() && __i->base() < this->__end_;
}

template <class _Tp, class _Allocator>
bool
vector<_Tp, _Allocator>::__decrementable(const const_iterator* __i) const
{
    return this->__begin_ < __i->base() && __i->base() <= this->__end_;
}

template <class _Tp, class _Allocator>
bool
vector<_Tp, _Allocator>::__addable(const const_iterator* __i, ptrdiff_t __n) const
{
    const_pointer __p = __i->base() + __n;
    return this->__begin_ <= __p && __p <= this->__end_;
}

template <class _Tp, class _Allocator>
bool
vector<_Tp, _Allocator>::__subscriptable(const const_iterator* __i, ptrdiff_t __n) const
{
    const_pointer __p = __i->base() + __n;
    return this->__begin_ <= __p && __p < this->__end_;
}

#endif // _LIBCPP_ENABLE_DEBUG_MODE

template <class _Tp, class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI
void
vector<_Tp, _Allocator>::__invalidate_iterators_past(pointer __new_last) {
#ifdef _LIBCPP_ENABLE_DEBUG_MODE
  __c_node* __c = __get_db()->__find_c_and_lock(this);
  for (__i_node** __p = __c->end_; __p != __c->beg_; ) {
    --__p;
    const_iterator* __i = static_cast<const_iterator*>((*__p)->__i_);
    if (__i->base() > __new_last) {
      (*__p)->__c_ = nullptr;
      if (--__c->end_ != __p)
        std::memmove(__p, __p+1, (__c->end_ - __p)*sizeof(__i_node*));
    }
  }
  __get_db()->unlock();
#else
  ((void)__new_last);
#endif
}

// vector<bool>

template <class _Allocator> class vector<bool, _Allocator>;

template <class _Allocator> struct hash<vector<bool, _Allocator> >;

template <class _Allocator>
struct __has_storage_type<vector<bool, _Allocator> >
{
    static const bool value = true;
};

template <class _Allocator>
class _LIBCPP_TEMPLATE_VIS vector<bool, _Allocator>
{
public:
    typedef vector                                   __self;
    typedef bool                                     value_type;
    typedef _Allocator                               allocator_type;
    typedef allocator_traits<allocator_type>         __alloc_traits;
    typedef typename __alloc_traits::size_type       size_type;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef size_type __storage_type;
    typedef __bit_iterator<vector, false>            pointer;
    typedef __bit_iterator<vector, true>             const_pointer;
    typedef pointer                                  iterator;
    typedef const_pointer                            const_iterator;
    typedef std::reverse_iterator<iterator>         reverse_iterator;
    typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

private:
    typedef __rebind_alloc<__alloc_traits, __storage_type> __storage_allocator;
    typedef allocator_traits<__storage_allocator>    __storage_traits;
    typedef typename __storage_traits::pointer       __storage_pointer;
    typedef typename __storage_traits::const_pointer __const_storage_pointer;

    __storage_pointer                                      __begin_;
    size_type                                              __size_;
    __compressed_pair<size_type, __storage_allocator> __cap_alloc_;
public:
    typedef __bit_reference<vector>                  reference;
#ifdef _LIBCPP_ABI_BITSET_VECTOR_BOOL_CONST_SUBSCRIPT_RETURN_BOOL
    using const_reference = bool;
#else
    typedef __bit_const_reference<vector>            const_reference;
#endif
private:
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    size_type& __cap() _NOEXCEPT
        {return __cap_alloc_.first();}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const size_type& __cap() const _NOEXCEPT
        {return __cap_alloc_.first();}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    __storage_allocator& __alloc() _NOEXCEPT
        {return __cap_alloc_.second();}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const __storage_allocator& __alloc() const _NOEXCEPT
        {return __cap_alloc_.second();}

    static const unsigned __bits_per_word = static_cast<unsigned>(sizeof(__storage_type) * CHAR_BIT);

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    static size_type __internal_cap_to_external(size_type __n) _NOEXCEPT
        {return __n * __bits_per_word;}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    static size_type __external_cap_to_internal(size_type __n) _NOEXCEPT
        {return (__n - 1) / __bits_per_word + 1;}

public:
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    vector() _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value);

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 explicit vector(const allocator_type& __a)
#if _LIBCPP_STD_VER <= 14
        _NOEXCEPT_(is_nothrow_copy_constructible<allocator_type>::value);
#else
        _NOEXCEPT;
#endif
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 ~vector();
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 explicit vector(size_type __n);
#if _LIBCPP_STD_VER > 11
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 explicit vector(size_type __n, const allocator_type& __a);
#endif
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(size_type __n, const value_type& __v);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(size_type __n, const value_type& __v, const allocator_type& __a);
    template <class _InputIterator>
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(_InputIterator __first, _InputIterator __last,
               typename enable_if<__is_exactly_cpp17_input_iterator<_InputIterator>::value>::type* = 0);
    template <class _InputIterator>
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a,
               typename enable_if<__is_exactly_cpp17_input_iterator<_InputIterator>::value>::type* = 0);
    template <class _ForwardIterator>
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(_ForwardIterator __first, _ForwardIterator __last,
               typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value>::type* = 0);
    template <class _ForwardIterator>
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a,
               typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value>::type* = 0);

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(const vector& __v);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(const vector& __v, const allocator_type& __a);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector& operator=(const vector& __v);

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(initializer_list<value_type> __il);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(initializer_list<value_type> __il, const allocator_type& __a);

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    vector& operator=(initializer_list<value_type> __il)
        {assign(__il.begin(), __il.end()); return *this;}

#endif // !_LIBCPP_CXX03_LANG

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    vector(vector&& __v)
#if _LIBCPP_STD_VER > 14
        noexcept;
#else
        _NOEXCEPT_(is_nothrow_move_constructible<allocator_type>::value);
#endif
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector(vector&& __v, const __type_identity_t<allocator_type>& __a);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    vector& operator=(vector&& __v)
        _NOEXCEPT_((__noexcept_move_assign_container<_Allocator, __alloc_traits>::value));

    template <class _InputIterator>
        typename enable_if <__is_exactly_cpp17_input_iterator<_InputIterator>::value,
           void
        >::type
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 assign(_InputIterator __first, _InputIterator __last);
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value,
           void
        >::type
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 assign(_ForwardIterator __first, _ForwardIterator __last);

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void assign(size_type __n, const value_type& __x);

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void assign(initializer_list<value_type> __il)
        {assign(__il.begin(), __il.end());}
#endif

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 allocator_type get_allocator() const _NOEXCEPT
        {return allocator_type(this->__alloc());}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 size_type max_size() const _NOEXCEPT;
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    size_type capacity() const _NOEXCEPT
        {return __internal_cap_to_external(__cap());}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    size_type size() const _NOEXCEPT
        {return __size_;}
    _LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    bool empty() const _NOEXCEPT
        {return __size_ == 0;}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void reserve(size_type __n);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void shrink_to_fit() _NOEXCEPT;

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    iterator begin() _NOEXCEPT
        {return __make_iter(0);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_iterator begin() const _NOEXCEPT
        {return __make_iter(0);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    iterator end() _NOEXCEPT
        {return __make_iter(__size_);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_iterator end()   const _NOEXCEPT
        {return __make_iter(__size_);}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    reverse_iterator rbegin() _NOEXCEPT
        {return       reverse_iterator(end());}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_reverse_iterator rbegin() const _NOEXCEPT
        {return const_reverse_iterator(end());}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    reverse_iterator rend() _NOEXCEPT
        {return       reverse_iterator(begin());}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_reverse_iterator rend()   const _NOEXCEPT
        {return const_reverse_iterator(begin());}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_iterator         cbegin()  const _NOEXCEPT
        {return __make_iter(0);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_iterator         cend()    const _NOEXCEPT
        {return __make_iter(__size_);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_reverse_iterator crbegin() const _NOEXCEPT
        {return rbegin();}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_reverse_iterator crend()   const _NOEXCEPT
        {return rend();}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 reference       operator[](size_type __n)       {return __make_ref(__n);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 const_reference operator[](size_type __n) const {return __make_ref(__n);}
    _LIBCPP_HIDE_FROM_ABI reference       at(size_type __n);
    _LIBCPP_HIDE_FROM_ABI const_reference at(size_type __n) const;

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 reference       front()       {return __make_ref(0);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 const_reference front() const {return __make_ref(0);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 reference       back()        {return __make_ref(__size_ - 1);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 const_reference back()  const {return __make_ref(__size_ - 1);}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void push_back(const value_type& __x);
#if _LIBCPP_STD_VER > 11
    template <class... _Args>
#if _LIBCPP_STD_VER > 14
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 reference emplace_back(_Args&&... __args)
#else
    _LIBCPP_HIDE_FROM_ABI void      emplace_back(_Args&&... __args)
#endif
    {
        push_back ( value_type ( std::forward<_Args>(__args)... ));
#if _LIBCPP_STD_VER > 14
        return this->back();
#endif
    }
#endif

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void pop_back() {--__size_;}

#if _LIBCPP_STD_VER > 11
    template <class... _Args>
   _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 iterator emplace(const_iterator __position, _Args&&... __args)
        { return insert ( __position, value_type ( std::forward<_Args>(__args)... )); }
#endif

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 iterator insert(const_iterator __position, const value_type& __x);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 iterator insert(const_iterator __position, size_type __n, const value_type& __x);
    template <class _InputIterator>
        typename enable_if <__is_exactly_cpp17_input_iterator<_InputIterator>::value,
            iterator
        >::type
        _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 insert(const_iterator __position, _InputIterator __first, _InputIterator __last);
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value,
            iterator
        >::type
        _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 insert(const_iterator __position, _ForwardIterator __first, _ForwardIterator __last);

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    iterator insert(const_iterator __position, initializer_list<value_type> __il)
        {return insert(__position, __il.begin(), __il.end());}
#endif

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 iterator erase(const_iterator __position);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 iterator erase(const_iterator __first, const_iterator __last);

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void clear() _NOEXCEPT {__size_ = 0;}

    _LIBCPP_CONSTEXPR_SINCE_CXX20 void swap(vector&)
#if _LIBCPP_STD_VER >= 14
        _NOEXCEPT;
#else
        _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value ||
                    __is_nothrow_swappable<allocator_type>::value);
#endif
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 static void swap(reference __x, reference __y) _NOEXCEPT { std::swap(__x, __y); }

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void resize(size_type __sz, value_type __x = false);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void flip() _NOEXCEPT;

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 bool __invariants() const;

private:
    _LIBCPP_NORETURN _LIBCPP_HIDE_FROM_ABI
    void __throw_length_error() const {
        std::__throw_length_error("vector");
    }

    _LIBCPP_NORETURN _LIBCPP_HIDE_FROM_ABI
    void __throw_out_of_range() const {
        std::__throw_out_of_range("vector");
    }

    //  Allocate space for __n objects
    //  throws length_error if __n > max_size()
    //  throws (probably bad_alloc) if memory run out
    //  Precondition:  __begin_ == __end_ == __cap() == 0
    //  Precondition:  __n > 0
    //  Postcondition:  capacity() >= __n
    //  Postcondition:  size() == 0
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void __vallocate(size_type __n) {
        if (__n > max_size())
            __throw_length_error();
        auto __allocation = std::__allocate_at_least(__alloc(), __external_cap_to_internal(__n));
        __begin_ = __allocation.ptr;
        __size_ = 0;
        __cap() = __allocation.count;
        if (__libcpp_is_constant_evaluated()) {
            for (size_type __i = 0; __i != __cap(); ++__i)
                std::__construct_at(std::__to_address(__begin_) + __i);
        }
    }

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void __vdeallocate() _NOEXCEPT;
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    static size_type __align_it(size_type __new_size) _NOEXCEPT
        {return (__new_size + (__bits_per_word-1)) & ~((size_type)__bits_per_word-1);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20  size_type __recommend(size_type __new_size) const;
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void __construct_at_end(size_type __n, bool __x);
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value,
            void
        >::type
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 __construct_at_end(_ForwardIterator __first, _ForwardIterator __last);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void __append(size_type __n, const_reference __x);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    reference __make_ref(size_type __pos) _NOEXCEPT
        {return reference(__begin_ + __pos / __bits_per_word, __storage_type(1) << __pos % __bits_per_word);}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_reference __make_ref(size_type __pos) const _NOEXCEPT {
        return __bit_const_reference<vector>(__begin_ + __pos / __bits_per_word,
                                             __storage_type(1) << __pos % __bits_per_word);
    }
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    iterator __make_iter(size_type __pos) _NOEXCEPT
        {return iterator(__begin_ + __pos / __bits_per_word, static_cast<unsigned>(__pos % __bits_per_word));}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    const_iterator __make_iter(size_type __pos) const _NOEXCEPT
        {return const_iterator(__begin_ + __pos / __bits_per_word, static_cast<unsigned>(__pos % __bits_per_word));}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    iterator __const_iterator_cast(const_iterator __p) _NOEXCEPT
        {return begin() + (__p - cbegin());}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void __copy_assign_alloc(const vector& __v)
        {__copy_assign_alloc(__v, integral_constant<bool,
                      __storage_traits::propagate_on_container_copy_assignment::value>());}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void __copy_assign_alloc(const vector& __c, true_type)
        {
            if (__alloc() != __c.__alloc())
                __vdeallocate();
            __alloc() = __c.__alloc();
        }

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void __copy_assign_alloc(const vector&, false_type)
        {}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void __move_assign(vector& __c, false_type);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void __move_assign(vector& __c, true_type)
        _NOEXCEPT_(is_nothrow_move_assignable<allocator_type>::value);
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void __move_assign_alloc(vector& __c)
        _NOEXCEPT_(
            !__storage_traits::propagate_on_container_move_assignment::value ||
            is_nothrow_move_assignable<allocator_type>::value)
        {__move_assign_alloc(__c, integral_constant<bool,
                      __storage_traits::propagate_on_container_move_assignment::value>());}
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void __move_assign_alloc(vector& __c, true_type)
        _NOEXCEPT_(is_nothrow_move_assignable<allocator_type>::value)
        {
            __alloc() = std::move(__c.__alloc());
        }

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    void __move_assign_alloc(vector&, false_type)
        _NOEXCEPT
        {}

    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 size_t __hash_code() const _NOEXCEPT;

    friend class __bit_reference<vector>;
    friend class __bit_const_reference<vector>;
    friend class __bit_iterator<vector, false>;
    friend class __bit_iterator<vector, true>;
    friend struct __bit_array<vector>;
    friend struct _LIBCPP_TEMPLATE_VIS hash<vector>;
};

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::__vdeallocate() _NOEXCEPT
{
    if (this->__begin_ != nullptr)
    {
        __storage_traits::deallocate(this->__alloc(), this->__begin_, __cap());
        std::__debug_db_invalidate_all(this);
        this->__begin_ = nullptr;
        this->__size_ = this->__cap() = 0;
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<bool, _Allocator>::size_type
vector<bool, _Allocator>::max_size() const _NOEXCEPT
{
    size_type __amax = __storage_traits::max_size(__alloc());
    size_type __nmax = numeric_limits<size_type>::max() / 2;  // end() >= begin(), always
    if (__nmax / __bits_per_word <= __amax)
        return __nmax;
    return __internal_cap_to_external(__amax);
}

//  Precondition:  __new_size > capacity()
template <class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<bool, _Allocator>::size_type
vector<bool, _Allocator>::__recommend(size_type __new_size) const
{
    const size_type __ms = max_size();
    if (__new_size > __ms)
        this->__throw_length_error();
    const size_type __cap = capacity();
    if (__cap >= __ms / 2)
        return __ms;
    return std::max(2 * __cap, __align_it(__new_size));
}

//  Default constructs __n objects starting at __end_
//  Precondition:  __n > 0
//  Precondition:  size() + __n <= capacity()
//  Postcondition:  size() == size() + __n
template <class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
void
vector<bool, _Allocator>::__construct_at_end(size_type __n, bool __x)
{
    size_type __old_size = this->__size_;
    this->__size_ += __n;
    if (__old_size == 0 || ((__old_size - 1) / __bits_per_word) != ((this->__size_ - 1) / __bits_per_word))
    {
        if (this->__size_ <= __bits_per_word)
            this->__begin_[0] = __storage_type(0);
        else
            this->__begin_[(this->__size_ - 1) / __bits_per_word] = __storage_type(0);
    }
    std::fill_n(__make_iter(__old_size), __n, __x);
}

template <class _Allocator>
template <class _ForwardIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value,
    void
>::type
vector<bool, _Allocator>::__construct_at_end(_ForwardIterator __first, _ForwardIterator __last)
{
    size_type __old_size = this->__size_;
    this->__size_ += std::distance(__first, __last);
    if (__old_size == 0 || ((__old_size - 1) / __bits_per_word) != ((this->__size_ - 1) / __bits_per_word))
    {
        if (this->__size_ <= __bits_per_word)
            this->__begin_[0] = __storage_type(0);
        else
            this->__begin_[(this->__size_ - 1) / __bits_per_word] = __storage_type(0);
    }
    std::copy(__first, __last, __make_iter(__old_size));
}

template <class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector()
    _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __default_init_tag())
{
}

template <class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(const allocator_type& __a)
#if _LIBCPP_STD_VER <= 14
        _NOEXCEPT_(is_nothrow_copy_constructible<allocator_type>::value)
#else
        _NOEXCEPT
#endif
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, static_cast<__storage_allocator>(__a))
{
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(size_type __n)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __default_init_tag())
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, false);
    }
}

#if _LIBCPP_STD_VER > 11
template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(size_type __n, const allocator_type& __a)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, static_cast<__storage_allocator>(__a))
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, false);
    }
}
#endif

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(size_type __n, const value_type& __x)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __default_init_tag())
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, __x);
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(size_type __n, const value_type& __x, const allocator_type& __a)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, static_cast<__storage_allocator>(__a))
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, __x);
    }
}

template <class _Allocator>
template <class _InputIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(_InputIterator __first, _InputIterator __last,
       typename enable_if<__is_exactly_cpp17_input_iterator<_InputIterator>::value>::type*)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __default_init_tag())
{
#ifndef _LIBCPP_NO_EXCEPTIONS
    try
    {
#endif // _LIBCPP_NO_EXCEPTIONS
        for (; __first != __last; ++__first)
            push_back(*__first);
#ifndef _LIBCPP_NO_EXCEPTIONS
    }
    catch (...)
    {
        if (__begin_ != nullptr)
            __storage_traits::deallocate(__alloc(), __begin_, __cap());
        std::__debug_db_invalidate_all(this);
        throw;
    }
#endif // _LIBCPP_NO_EXCEPTIONS
}

template <class _Allocator>
template <class _InputIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a,
       typename enable_if<__is_exactly_cpp17_input_iterator<_InputIterator>::value>::type*)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, static_cast<__storage_allocator>(__a))
{
#ifndef _LIBCPP_NO_EXCEPTIONS
    try
    {
#endif // _LIBCPP_NO_EXCEPTIONS
        for (; __first != __last; ++__first)
            push_back(*__first);
#ifndef _LIBCPP_NO_EXCEPTIONS
    }
    catch (...)
    {
        if (__begin_ != nullptr)
            __storage_traits::deallocate(__alloc(), __begin_, __cap());
        std::__debug_db_invalidate_all(this);
        throw;
    }
#endif // _LIBCPP_NO_EXCEPTIONS
}

template <class _Allocator>
template <class _ForwardIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(_ForwardIterator __first, _ForwardIterator __last,
                                typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value>::type*)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __default_init_tag())
{
    size_type __n = static_cast<size_type>(std::distance(__first, __last));
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last);
    }
}

template <class _Allocator>
template <class _ForwardIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a,
                                typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value>::type*)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, static_cast<__storage_allocator>(__a))
{
    size_type __n = static_cast<size_type>(std::distance(__first, __last));
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last);
    }
}

#ifndef _LIBCPP_CXX03_LANG

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(initializer_list<value_type> __il)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __default_init_tag())
{
    size_type __n = static_cast<size_type>(__il.size());
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__il.begin(), __il.end());
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(initializer_list<value_type> __il, const allocator_type& __a)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, static_cast<__storage_allocator>(__a))
{
    size_type __n = static_cast<size_type>(__il.size());
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__il.begin(), __il.end());
    }
}

#endif // _LIBCPP_CXX03_LANG

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::~vector()
{
    if (__begin_ != nullptr)
        __storage_traits::deallocate(__alloc(), __begin_, __cap());
    std::__debug_db_invalidate_all(this);
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(const vector& __v)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __storage_traits::select_on_container_copy_construction(__v.__alloc()))
{
    if (__v.size() > 0)
    {
        __vallocate(__v.size());
        __construct_at_end(__v.begin(), __v.end());
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(const vector& __v, const allocator_type& __a)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __a)
{
    if (__v.size() > 0)
    {
        __vallocate(__v.size());
        __construct_at_end(__v.begin(), __v.end());
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>&
vector<bool, _Allocator>::operator=(const vector& __v)
{
    if (this != std::addressof(__v))
    {
        __copy_assign_alloc(__v);
        if (__v.__size_)
        {
            if (__v.__size_ > capacity())
            {
                __vdeallocate();
                __vallocate(__v.__size_);
            }
            std::copy(__v.__begin_, __v.__begin_ + __external_cap_to_internal(__v.__size_), __begin_);
        }
        __size_ = __v.__size_;
    }
    return *this;
}

template <class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 vector<bool, _Allocator>::vector(vector&& __v)
#if _LIBCPP_STD_VER > 14
    _NOEXCEPT
#else
    _NOEXCEPT_(is_nothrow_move_constructible<allocator_type>::value)
#endif
    : __begin_(__v.__begin_),
      __size_(__v.__size_),
      __cap_alloc_(std::move(__v.__cap_alloc_)) {
    __v.__begin_ = nullptr;
    __v.__size_ = 0;
    __v.__cap() = 0;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>::vector(vector&& __v, const __type_identity_t<allocator_type>& __a)
    : __begin_(nullptr),
      __size_(0),
      __cap_alloc_(0, __a)
{
    if (__a == allocator_type(__v.__alloc()))
    {
        this->__begin_ = __v.__begin_;
        this->__size_ = __v.__size_;
        this->__cap() = __v.__cap();
        __v.__begin_ = nullptr;
        __v.__cap() = __v.__size_ = 0;
    }
    else if (__v.size() > 0)
    {
        __vallocate(__v.size());
        __construct_at_end(__v.begin(), __v.end());
    }
}

template <class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
vector<bool, _Allocator>&
vector<bool, _Allocator>::operator=(vector&& __v)
    _NOEXCEPT_((__noexcept_move_assign_container<_Allocator, __alloc_traits>::value))
{
    __move_assign(__v, integral_constant<bool,
          __storage_traits::propagate_on_container_move_assignment::value>());
    return *this;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::__move_assign(vector& __c, false_type)
{
    if (__alloc() != __c.__alloc())
        assign(__c.begin(), __c.end());
    else
        __move_assign(__c, true_type());
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::__move_assign(vector& __c, true_type)
    _NOEXCEPT_(is_nothrow_move_assignable<allocator_type>::value)
{
    __vdeallocate();
    __move_assign_alloc(__c);
    this->__begin_ = __c.__begin_;
    this->__size_ = __c.__size_;
    this->__cap() = __c.__cap();
    __c.__begin_ = nullptr;
    __c.__cap() = __c.__size_ = 0;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::assign(size_type __n, const value_type& __x)
{
    __size_ = 0;
    if (__n > 0)
    {
        size_type __c = capacity();
        if (__n <= __c)
            __size_ = __n;
        else
        {
            vector __v(get_allocator());
            __v.reserve(__recommend(__n));
            __v.__size_ = __n;
            swap(__v);
        }
        std::fill_n(begin(), __n, __x);
    }
    std::__debug_db_invalidate_all(this);
}

template <class _Allocator>
template <class _InputIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 typename enable_if <__is_exactly_cpp17_input_iterator<_InputIterator>::value,
   void
>::type
vector<bool, _Allocator>::assign(_InputIterator __first, _InputIterator __last)
{
    clear();
    for (; __first != __last; ++__first)
        push_back(*__first);
}

template <class _Allocator>
template <class _ForwardIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value,
   void
>::type
vector<bool, _Allocator>::assign(_ForwardIterator __first, _ForwardIterator __last)
{
    clear();
    difference_type __ns = std::distance(__first, __last);
    _LIBCPP_ASSERT(__ns >= 0, "invalid range specified");
    const size_t __n = static_cast<size_type>(__ns);
    if (__n)
    {
        if (__n > capacity())
        {
            __vdeallocate();
            __vallocate(__n);
        }
        __construct_at_end(__first, __last);
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::reserve(size_type __n)
{
    if (__n > capacity())
    {
        if (__n > max_size())
            this->__throw_length_error();
        vector __v(this->get_allocator());
        __v.__vallocate(__n);
        __v.__construct_at_end(this->begin(), this->end());
        swap(__v);
        std::__debug_db_invalidate_all(this);
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::shrink_to_fit() _NOEXCEPT
{
    if (__external_cap_to_internal(size()) > __cap())
    {
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif // _LIBCPP_NO_EXCEPTIONS
            vector(*this, allocator_type(__alloc())).swap(*this);
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
        }
#endif // _LIBCPP_NO_EXCEPTIONS
    }
}

template <class _Allocator>
typename vector<bool, _Allocator>::reference
vector<bool, _Allocator>::at(size_type __n)
{
    if (__n >= size())
        this->__throw_out_of_range();
    return (*this)[__n];
}

template <class _Allocator>
typename vector<bool, _Allocator>::const_reference
vector<bool, _Allocator>::at(size_type __n) const
{
    if (__n >= size())
        this->__throw_out_of_range();
    return (*this)[__n];
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::push_back(const value_type& __x)
{
    if (this->__size_ == this->capacity())
        reserve(__recommend(this->__size_ + 1));
    ++this->__size_;
    back() = __x;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 typename vector<bool, _Allocator>::iterator
vector<bool, _Allocator>::insert(const_iterator __position, const value_type& __x)
{
    iterator __r;
    if (size() < capacity())
    {
        const_iterator __old_end = end();
        ++__size_;
        std::copy_backward(__position, __old_end, end());
        __r = __const_iterator_cast(__position);
    }
    else
    {
        vector __v(get_allocator());
        __v.reserve(__recommend(__size_ + 1));
        __v.__size_ = __size_ + 1;
        __r = std::copy(cbegin(), __position, __v.begin());
        std::copy_backward(__position, cend(), __v.end());
        swap(__v);
    }
    *__r = __x;
    return __r;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 typename vector<bool, _Allocator>::iterator
vector<bool, _Allocator>::insert(const_iterator __position, size_type __n, const value_type& __x)
{
    iterator __r;
    size_type __c = capacity();
    if (__n <= __c && size() <= __c - __n)
    {
        const_iterator __old_end = end();
        __size_ += __n;
        std::copy_backward(__position, __old_end, end());
        __r = __const_iterator_cast(__position);
    }
    else
    {
        vector __v(get_allocator());
        __v.reserve(__recommend(__size_ + __n));
        __v.__size_ = __size_ + __n;
        __r = std::copy(cbegin(), __position, __v.begin());
        std::copy_backward(__position, cend(), __v.end());
        swap(__v);
    }
    std::fill_n(__r, __n, __x);
    return __r;
}

template <class _Allocator>
template <class _InputIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 typename enable_if <__is_exactly_cpp17_input_iterator<_InputIterator>::value,
    typename vector<bool, _Allocator>::iterator
>::type
vector<bool, _Allocator>::insert(const_iterator __position, _InputIterator __first, _InputIterator __last)
{
    difference_type __off = __position - begin();
    iterator __p = __const_iterator_cast(__position);
    iterator __old_end = end();
    for (; size() != capacity() && __first != __last; ++__first)
    {
        ++this->__size_;
        back() = *__first;
    }
    vector __v(get_allocator());
    if (__first != __last)
    {
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif // _LIBCPP_NO_EXCEPTIONS
            __v.assign(__first, __last);
            difference_type __old_size = static_cast<difference_type>(__old_end - begin());
            difference_type __old_p = __p - begin();
            reserve(__recommend(size() + __v.size()));
            __p = begin() + __old_p;
            __old_end = begin() + __old_size;
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            erase(__old_end, end());
            throw;
        }
#endif // _LIBCPP_NO_EXCEPTIONS
    }
    __p = std::rotate(__p, __old_end, end());
    insert(__p, __v.begin(), __v.end());
    return begin() + __off;
}

template <class _Allocator>
template <class _ForwardIterator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value,
    typename vector<bool, _Allocator>::iterator
>::type
vector<bool, _Allocator>::insert(const_iterator __position, _ForwardIterator __first, _ForwardIterator __last)
{
    const difference_type __n_signed = std::distance(__first, __last);
    _LIBCPP_ASSERT(__n_signed >= 0, "invalid range specified");
    const size_type __n = static_cast<size_type>(__n_signed);
    iterator __r;
    size_type __c = capacity();
    if (__n <= __c && size() <= __c - __n)
    {
        const_iterator __old_end = end();
        __size_ += __n;
        std::copy_backward(__position, __old_end, end());
        __r = __const_iterator_cast(__position);
    }
    else
    {
        vector __v(get_allocator());
        __v.reserve(__recommend(__size_ + __n));
        __v.__size_ = __size_ + __n;
        __r = std::copy(cbegin(), __position, __v.begin());
        std::copy_backward(__position, cend(), __v.end());
        swap(__v);
    }
    std::copy(__first, __last, __r);
    return __r;
}

template <class _Allocator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<bool, _Allocator>::iterator
vector<bool, _Allocator>::erase(const_iterator __position)
{
    iterator __r = __const_iterator_cast(__position);
    std::copy(__position + 1, this->cend(), __r);
    --__size_;
    return __r;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
typename vector<bool, _Allocator>::iterator
vector<bool, _Allocator>::erase(const_iterator __first, const_iterator __last)
{
    iterator __r = __const_iterator_cast(__first);
    difference_type __d = __last - __first;
    std::copy(__last, this->cend(), __r);
    __size_ -= __d;
    return __r;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::swap(vector& __x)
#if _LIBCPP_STD_VER >= 14
    _NOEXCEPT
#else
    _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value ||
                __is_nothrow_swappable<allocator_type>::value)
#endif
{
    std::swap(this->__begin_, __x.__begin_);
    std::swap(this->__size_, __x.__size_);
    std::swap(this->__cap(), __x.__cap());
    std::__swap_allocator(this->__alloc(), __x.__alloc(),
        integral_constant<bool, __alloc_traits::propagate_on_container_swap::value>());
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::resize(size_type __sz, value_type __x)
{
    size_type __cs = size();
    if (__cs < __sz)
    {
        iterator __r;
        size_type __c = capacity();
        size_type __n = __sz - __cs;
        if (__n <= __c && __cs <= __c - __n)
        {
            __r = end();
            __size_ += __n;
        }
        else
        {
            vector __v(get_allocator());
            __v.reserve(__recommend(__size_ + __n));
            __v.__size_ = __size_ + __n;
            __r = std::copy(cbegin(), cend(), __v.begin());
            swap(__v);
        }
        std::fill_n(__r, __n, __x);
    }
    else
        __size_ = __sz;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 void
vector<bool, _Allocator>::flip() _NOEXCEPT
{
    // do middle whole words
    size_type __n = __size_;
    __storage_pointer __p = __begin_;
    for (; __n >= __bits_per_word; ++__p, __n -= __bits_per_word)
        *__p = ~*__p;
    // do last partial word
    if (__n > 0)
    {
        __storage_type __m = ~__storage_type(0) >> (__bits_per_word - __n);
        __storage_type __b = *__p & __m;
        *__p &= ~__m;
        *__p |= ~__b & __m;
    }
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 bool
vector<bool, _Allocator>::__invariants() const
{
    if (this->__begin_ == nullptr)
    {
        if (this->__size_ != 0 || this->__cap() != 0)
            return false;
    }
    else
    {
        if (this->__cap() == 0)
            return false;
        if (this->__size_ > this->capacity())
            return false;
    }
    return true;
}

template <class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20 size_t
vector<bool, _Allocator>::__hash_code() const _NOEXCEPT
{
    size_t __h = 0;
    // do middle whole words
    size_type __n = __size_;
    __storage_pointer __p = __begin_;
    for (; __n >= __bits_per_word; ++__p, __n -= __bits_per_word)
        __h ^= *__p;
    // do last partial word
    if (__n > 0)
    {
        const __storage_type __m = ~__storage_type(0) >> (__bits_per_word - __n);
        __h ^= *__p & __m;
    }
    return __h;
}

template <class _Allocator>
struct _LIBCPP_TEMPLATE_VIS hash<vector<bool, _Allocator> >
    : public __unary_function<vector<bool, _Allocator>, size_t>
{
    _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
    size_t operator()(const vector<bool, _Allocator>& __vec) const _NOEXCEPT
        {return __vec.__hash_code();}
};

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
bool
operator==(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    const typename vector<_Tp, _Allocator>::size_type __sz = __x.size();
    return __sz == __y.size() && std::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
bool
operator!=(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return !(__x == __y);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
bool
operator< (const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return std::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
bool
operator> (const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return __y < __x;
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
bool
operator>=(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return !(__x < __y);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
bool
operator<=(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return !(__y < __x);
}

template <class _Tp, class _Allocator>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI
void
swap(vector<_Tp, _Allocator>& __x, vector<_Tp, _Allocator>& __y)
    _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y)))
{
    __x.swap(__y);
}

#if _LIBCPP_STD_VER > 17
template <class _Tp, class _Allocator, class _Up>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI typename vector<_Tp, _Allocator>::size_type
erase(vector<_Tp, _Allocator>& __c, const _Up& __v) {
  auto __old_size = __c.size();
  __c.erase(std::remove(__c.begin(), __c.end(), __v), __c.end());
  return __old_size - __c.size();
}

template <class _Tp, class _Allocator, class _Predicate>
_LIBCPP_CONSTEXPR_SINCE_CXX20
inline _LIBCPP_HIDE_FROM_ABI typename vector<_Tp, _Allocator>::size_type
erase_if(vector<_Tp, _Allocator>& __c, _Predicate __pred) {
  auto __old_size = __c.size();
  __c.erase(std::remove_if(__c.begin(), __c.end(), __pred), __c.end());
  return __old_size - __c.size();
}

template <>
inline constexpr bool __format::__enable_insertable<std::vector<char>> = true;
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
template <>
inline constexpr bool __format::__enable_insertable<std::vector<wchar_t>> = true;
#endif

#endif // _LIBCPP_STD_VER > 17

_LIBCPP_END_NAMESPACE_STD

#if _LIBCPP_STD_VER > 14
_LIBCPP_BEGIN_NAMESPACE_STD
namespace pmr {
template <class _ValueT>
using vector = std::vector<_ValueT, polymorphic_allocator<_ValueT>>;
} // namespace pmr
_LIBCPP_END_NAMESPACE_STD
#endif

_LIBCPP_POP_MACROS

#if !defined(_LIBCPP_REMOVE_TRANSITIVE_INCLUDES) && _LIBCPP_STD_VER <= 20
#  include <algorithm>
#  include <atomic>
#  include <concepts>
#  include <typeinfo>
#  include <utility>
#endif

#endif // _LIBCPP_VECTOR
