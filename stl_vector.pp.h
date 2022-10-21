# 0 "stl_vector.h"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "stl_vector.h"
# 59 "stl_vector.h"
# 1 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 1 3
# 62 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 3
       
# 63 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 3

# 1 "/usr/include/c++/11/bits/concept_check.h" 1 3
# 33 "/usr/include/c++/11/bits/concept_check.h" 3
       
# 34 "/usr/include/c++/11/bits/concept_check.h" 3

# 1 "/usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h" 1 3
# 278 "/usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h" 3

# 278 "/usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h" 3
namespace std
{
  typedef long unsigned int size_t;
  typedef long int ptrdiff_t;




}
# 300 "/usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h" 3
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
# 586 "/usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h" 3
# 1 "/usr/include/x86_64-linux-gnu/c++/11/bits/os_defines.h" 1 3
# 39 "/usr/include/x86_64-linux-gnu/c++/11/bits/os_defines.h" 3
# 1 "/usr/include/features.h" 1 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 486 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 559 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 487 "/usr/include/features.h" 2 3 4
# 510 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 511 "/usr/include/features.h" 2 3 4
# 40 "/usr/include/x86_64-linux-gnu/c++/11/bits/os_defines.h" 2 3
# 587 "/usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h" 2 3


# 1 "/usr/include/x86_64-linux-gnu/c++/11/bits/cpu_defines.h" 1 3
# 590 "/usr/include/x86_64-linux-gnu/c++/11/bits/c++config.h" 2 3
# 36 "/usr/include/c++/11/bits/concept_check.h" 2 3
# 65 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 2 3
# 1 "/usr/include/c++/11/debug/assertions.h" 1 3
# 66 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{




  template <typename> struct _List_iterator;
  template <typename> struct _List_const_iterator;


  template<typename _InputIterator>
    inline
    typename iterator_traits<_InputIterator>::difference_type
    __distance(_InputIterator __first, _InputIterator __last,
               input_iterator_tag)
    {

     

      typename iterator_traits<_InputIterator>::difference_type __n = 0;
      while (__first != __last)
 {
   ++__first;
   ++__n;
 }
      return __n;
    }

  template<typename _RandomAccessIterator>
    inline
    typename iterator_traits<_RandomAccessIterator>::difference_type
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
               random_access_iterator_tag)
    {

     

      return __last - __first;
    }



  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_iterator<_Tp>,
        std::_List_iterator<_Tp>,
        input_iterator_tag);

  template<typename _Tp>
    ptrdiff_t
    __distance(std::_List_const_iterator<_Tp>,
        std::_List_const_iterator<_Tp>,
        input_iterator_tag);
# 135 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator>
    inline
    typename iterator_traits<_InputIterator>::difference_type
    distance(_InputIterator __first, _InputIterator __last)
    {

      return std::__distance(__first, __last,
        std::__iterator_category(__first));
    }

  template<typename _InputIterator, typename _Distance>
    inline void
    __advance(_InputIterator& __i, _Distance __n, input_iterator_tag)
    {

     
      do { if (__builtin_is_constant_evaluated() && !bool(__n >= 0)) __builtin_unreachable(); } while (false);
      while (__n--)
 ++__i;
    }

  template<typename _BidirectionalIterator, typename _Distance>
    inline void
    __advance(_BidirectionalIterator& __i, _Distance __n,
       bidirectional_iterator_tag)
    {

     

      if (__n > 0)
        while (__n--)
   ++__i;
      else
        while (__n++)
   --__i;
    }

  template<typename _RandomAccessIterator, typename _Distance>
    inline void
    __advance(_RandomAccessIterator& __i, _Distance __n,
              random_access_iterator_tag)
    {

     

      if (__builtin_constant_p(__n) && __n == 1)
 ++__i;
      else if (__builtin_constant_p(__n) && __n == -1)
 --__i;
      else
 __i += __n;
    }
# 200 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator, typename _Distance>
    inline void
    advance(_InputIterator& __i, _Distance __n)
    {

      typename iterator_traits<_InputIterator>::difference_type __d = __n;
      std::__advance(__i, __d, std::__iterator_category(__i));
    }
# 236 "/usr/include/c++/11/bits/stl_iterator_base_funcs.h" 3

}
# 60 "stl_vector.h" 2
# 1 "/usr/include/c++/11/bits/functexcept.h" 1 3
# 40 "/usr/include/c++/11/bits/functexcept.h" 3
# 1 "/usr/include/c++/11/bits/exception_defines.h" 1 3
# 41 "/usr/include/c++/11/bits/functexcept.h" 2 3

namespace std __attribute__ ((__visibility__ ("default")))
{



  void
  __throw_bad_exception(void) __attribute__((__noreturn__));


  void
  __throw_bad_alloc(void) __attribute__((__noreturn__));

  void
  __throw_bad_array_new_length(void) __attribute__((__noreturn__));


  void
  __throw_bad_cast(void) __attribute__((__noreturn__));

  void
  __throw_bad_typeid(void) __attribute__((__noreturn__));


  void
  __throw_logic_error(const char*) __attribute__((__noreturn__));

  void
  __throw_domain_error(const char*) __attribute__((__noreturn__));

  void
  __throw_invalid_argument(const char*) __attribute__((__noreturn__));

  void
  __throw_length_error(const char*) __attribute__((__noreturn__));

  void
  __throw_out_of_range(const char*) __attribute__((__noreturn__));

  void
  __throw_out_of_range_fmt(const char*, ...) __attribute__((__noreturn__))
    __attribute__((__format__(__gnu_printf__, 1, 2)));

  void
  __throw_runtime_error(const char*) __attribute__((__noreturn__));

  void
  __throw_range_error(const char*) __attribute__((__noreturn__));

  void
  __throw_overflow_error(const char*) __attribute__((__noreturn__));

  void
  __throw_underflow_error(const char*) __attribute__((__noreturn__));


  void
  __throw_ios_failure(const char*) __attribute__((__noreturn__));

  void
  __throw_ios_failure(const char*, int) __attribute__((__noreturn__));


  void
  __throw_system_error(int) __attribute__((__noreturn__));


  void
  __throw_future_error(int) __attribute__((__noreturn__));


  void
  __throw_bad_function_call() __attribute__((__noreturn__));


}
# 61 "stl_vector.h" 2
# 77 "stl_vector.h"

# 77 "stl_vector.h"
namespace std 
# 77 "stl_vector.h" 3
             __attribute__ ((__visibility__ (
# 77 "stl_vector.h"
             "default"
# 77 "stl_vector.h" 3
             )))

# 78 "stl_vector.h"
{




  template<typename _Tp, typename _Alloc>
    struct _Vector_base
    {
      typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
 rebind<_Tp>::other _Tp_alloc_type;
      typedef typename __gnu_cxx::__alloc_traits<_Tp_alloc_type>::pointer
        pointer;

      struct _Vector_impl_data
      {
 pointer _M_start;
 pointer _M_finish;
 pointer _M_end_of_storage;

 _Vector_impl_data()
 : _M_start(), _M_finish(), _M_end_of_storage()
 { }
# 108 "stl_vector.h"
 void
 _M_copy_data(_Vector_impl_data const& __x)
 {
   _M_start = __x._M_start;
   _M_finish = __x._M_finish;
   _M_end_of_storage = __x._M_end_of_storage;
 }

 void
 _M_swap_data(_Vector_impl_data& __x)
 {


   _Vector_impl_data __tmp;
   __tmp._M_copy_data(*this);
   _M_copy_data(__x);
   __x._M_copy_data(__tmp);
 }
      };

      struct _Vector_impl
 : public _Tp_alloc_type, public _Vector_impl_data
      {
 _Vector_impl()

 : _Tp_alloc_type()
 { }

 _Vector_impl(_Tp_alloc_type const& __a)
 : _Tp_alloc_type(__a)
 { }
# 270 "stl_vector.h"
      };

    public:
      typedef _Alloc allocator_type;

      _Tp_alloc_type&
      _M_get_Tp_allocator()
      { return this->_M_impl; }

      const _Tp_alloc_type&
      _M_get_Tp_allocator() const
      { return this->_M_impl; }

      allocator_type
      get_allocator() const
      { return allocator_type(_M_get_Tp_allocator()); }




      _Vector_base() { }


      _Vector_base(const allocator_type& __a)
      : _M_impl(__a) { }



      _Vector_base(size_t __n)
      : _M_impl()
      { _M_create_storage(__n); }


      _Vector_base(size_t __n, const allocator_type& __a)
      : _M_impl(__a)
      { _M_create_storage(__n); }
# 333 "stl_vector.h"
      ~_Vector_base()
      {
 _M_deallocate(_M_impl._M_start,
        _M_impl._M_end_of_storage - _M_impl._M_start);
      }

    public:
      _Vector_impl _M_impl;

      pointer
      _M_allocate(size_t __n)
      {
 typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
 return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
      }

      void
      _M_deallocate(pointer __p, size_t __n)
      {
 typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
 if (__p)
   _Tr::deallocate(_M_impl, __p, __n);
      }

    protected:
      void
      _M_create_storage(size_t __n)
      {
 this->_M_impl._M_start = this->_M_allocate(__n);
 this->_M_impl._M_finish = this->_M_impl._M_start;
 this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
      }
    };
# 388 "stl_vector.h"
  template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
    class vector : protected _Vector_base<_Tp, _Alloc>
    {
# 409 "stl_vector.h"
      typedef _Vector_base<_Tp, _Alloc> _Base;
      typedef typename _Base::_Tp_alloc_type _Tp_alloc_type;
      typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Alloc_traits;

    public:
      typedef _Tp value_type;
      typedef typename _Base::pointer pointer;
      typedef typename _Alloc_traits::const_pointer const_pointer;
      typedef typename _Alloc_traits::reference reference;
      typedef typename _Alloc_traits::const_reference const_reference;
      typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;
      typedef __gnu_cxx::__normal_iterator<const_pointer, vector>
      const_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Alloc allocator_type;

    private:
# 473 "stl_vector.h"
    protected:
      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_M_impl;
      using _Base::_M_get_Tp_allocator;

    public:
# 489 "stl_vector.h"
      vector() { }






      explicit
      vector(const allocator_type& __a)
      : _Base(__a) { }
# 535 "stl_vector.h"
      explicit
      vector(size_type __n, const value_type& __value = value_type(),
      const allocator_type& __a = allocator_type())
      : _Base(_S_check_init_len(__n, __a), __a)
      { _M_fill_initialize(__n, __value); }
# 553 "stl_vector.h"
      vector(const vector& __x)
      : _Base(__x.size(),
 _Alloc_traits::_S_select_on_copy(__x._M_get_Tp_allocator()))
      {
 this->_M_impl._M_finish =
   std::__uninitialized_copy_a(__x.begin(), __x.end(),
          this->_M_impl._M_start,
          _M_get_Tp_allocator());
      }
# 661 "stl_vector.h"
      template<typename _InputIterator>
 vector(_InputIterator __first, _InputIterator __last,
        const allocator_type& __a = allocator_type())
 : _Base(__a)
 {

   typedef typename std::__is_integer<_InputIterator>::__type _Integral;
   _M_initialize_dispatch(__first, __last, _Integral());
 }
# 678 "stl_vector.h"
      ~vector()
      {
 std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
        _M_get_Tp_allocator());
 ;
      }
# 694 "stl_vector.h"
      vector&
      operator=(const vector& __x);
# 748 "stl_vector.h"
      void
      assign(size_type __n, const value_type& __val)
      { _M_fill_assign(__n, __val); }
# 771 "stl_vector.h"
      template<typename _InputIterator>
 void
 assign(_InputIterator __first, _InputIterator __last)
 {

   typedef typename std::__is_integer<_InputIterator>::__type _Integral;
   _M_assign_dispatch(__first, __last, _Integral());
 }
# 802 "stl_vector.h"
      using _Base::get_allocator;







      iterator
      begin()
      { return iterator(this->_M_impl._M_start); }






      const_iterator
      begin() const
      { return const_iterator(this->_M_impl._M_start); }






      iterator
      end()
      { return iterator(this->_M_impl._M_finish); }






      const_iterator
      end() const
      { return const_iterator(this->_M_impl._M_finish); }






      reverse_iterator
      rbegin()
      { return reverse_iterator(end()); }






      const_reverse_iterator
      rbegin() const
      { return const_reverse_iterator(end()); }






      reverse_iterator
      rend()
      { return reverse_iterator(begin()); }






      const_reverse_iterator
      rend() const
      { return const_reverse_iterator(begin()); }
# 917 "stl_vector.h"
      size_type
      size() const
      { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }


      size_type
      max_size() const
      { return _S_max_size(_M_get_Tp_allocator()); }
# 976 "stl_vector.h"
      void
      resize(size_type __new_size, value_type __x = value_type())
      {
 if (__new_size > size())
   _M_fill_insert(end(), __new_size - size(), __x);
 else if (__new_size < size())
   _M_erase_at_end(this->_M_impl._M_start + __new_size);
      }
# 997 "stl_vector.h"
      size_type
      capacity() const
      { return size_type(this->_M_impl._M_end_of_storage
    - this->_M_impl._M_start); }





      bool
      empty() const
      { return begin() == end(); }
# 1027 "stl_vector.h"
      void
      reserve(size_type __n);
# 1042 "stl_vector.h"
      reference
      operator[](size_type __n)
      {
 ;
 return *(this->_M_impl._M_start + __n);
      }
# 1060 "stl_vector.h"
      const_reference
      operator[](size_type __n) const
      {
 ;
 return *(this->_M_impl._M_start + __n);
      }

    protected:

      void
      _M_range_check(size_type __n) const
      {
 if (__n >= this->size())
   __throw_out_of_range_fmt(
# 1073 "stl_vector.h" 3
                           (
# 1073 "stl_vector.h"
                           "vector::_M_range_check: __n " "(which is %zu) >= this->size() " "(which is %zu)"
# 1073 "stl_vector.h" 3
                           )

                            
# 1075 "stl_vector.h"
                           ,
       __n, this->size());
      }

    public:
# 1091 "stl_vector.h"
      reference
      at(size_type __n)
      {
 _M_range_check(__n);
 return (*this)[__n];
      }
# 1109 "stl_vector.h"
      const_reference
      at(size_type __n) const
      {
 _M_range_check(__n);
 return (*this)[__n];
      }





      reference
      front()
      {
 ;
 return *begin();
      }





      const_reference
      front() const
      {
 ;
 return *begin();
      }





      reference
      back()
      {
 ;
 return *(end() - 1);
      }





      const_reference
      back() const
      {
 ;
 return *(end() - 1);
      }
# 1167 "stl_vector.h"
      _Tp*
      data()
      { return _M_data_ptr(this->_M_impl._M_start); }

      const _Tp*
      data() const
      { return _M_data_ptr(this->_M_impl._M_start); }
# 1186 "stl_vector.h"
      void
      push_back(const value_type& __x)
      {
 if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
   {
     ;
     _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
         __x);
     ++this->_M_impl._M_finish;
     ;
   }
 else
   _M_realloc_insert(end(), __x);
      }
# 1224 "stl_vector.h"
      void
      pop_back()
      {
 ;
 --this->_M_impl._M_finish;
 _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
 ;
      }
# 1276 "stl_vector.h"
      iterator
      insert(iterator __position, const value_type& __x);
# 1355 "stl_vector.h"
      void
      insert(iterator __position, size_type __n, const value_type& __x)
      { _M_fill_insert(__position, __n, __x); }
# 1402 "stl_vector.h"
      template<typename _InputIterator>
 void
 insert(iterator __position, _InputIterator __first,
        _InputIterator __last)
 {

   typedef typename std::__is_integer<_InputIterator>::__type _Integral;
   _M_insert_dispatch(__position, __first, __last, _Integral());
 }
# 1428 "stl_vector.h"
      iterator




      erase(iterator __position)
      { return _M_erase(__position); }
# 1455 "stl_vector.h"
      iterator
# 1464 "stl_vector.h"
      erase(iterator __first, iterator __last)
      { return _M_erase(__first, __last); }
# 1479 "stl_vector.h"
      void
      swap(vector& __x)
      {




 this->_M_impl._M_swap_data(__x._M_impl);
 _Alloc_traits::_S_on_swap(_M_get_Tp_allocator(),
      __x._M_get_Tp_allocator());
      }







      void
      clear()
      { _M_erase_at_end(this->_M_impl._M_start); }

    protected:




      template<typename _ForwardIterator>
 pointer
 _M_allocate_and_copy(size_type __n,
        _ForwardIterator __first, _ForwardIterator __last)
 {
   pointer __result = this->_M_allocate(__n);
   
# 1512 "stl_vector.h" 3
  try
     
# 1513 "stl_vector.h"
    {
       std::__uninitialized_copy_a(__first, __last, __result,
       _M_get_Tp_allocator());
       return __result;
     }
   
# 1518 "stl_vector.h" 3
  catch(
# 1518 "stl_vector.h"
  ...
# 1518 "stl_vector.h" 3
  )
     
# 1519 "stl_vector.h"
    {
       _M_deallocate(__result, __n);
       
# 1521 "stl_vector.h" 3
      throw
# 1521 "stl_vector.h"
                             ;
     }
 }
# 1533 "stl_vector.h"
      template<typename _Integer>
 void
 _M_initialize_dispatch(_Integer __n, _Integer __value, __true_type)
 {
   this->_M_impl._M_start = _M_allocate(_S_check_init_len(
  static_cast<size_type>(__n), _M_get_Tp_allocator()));
   this->_M_impl._M_end_of_storage =
     this->_M_impl._M_start + static_cast<size_type>(__n);
   _M_fill_initialize(static_cast<size_type>(__n), __value);
 }


      template<typename _InputIterator>
 void
 _M_initialize_dispatch(_InputIterator __first, _InputIterator __last,
          __false_type)
 {
   _M_range_initialize(__first, __last,
         std::__iterator_category(__first));
 }



      template<typename _InputIterator>
 void
 _M_range_initialize(_InputIterator __first, _InputIterator __last,
       std::input_iterator_tag)
 {
   
# 1561 "stl_vector.h" 3
  try 
# 1561 "stl_vector.h"
        {
     for (; __first != __last; ++__first)



       push_back(*__first);

   } 
# 1568 "stl_vector.h" 3
    catch(
# 1568 "stl_vector.h"
    ...
# 1568 "stl_vector.h" 3
    ) 
# 1568 "stl_vector.h"
                 {
     clear();
     
# 1570 "stl_vector.h" 3
    throw
# 1570 "stl_vector.h"
                           ;
   }
 }


      template<typename _ForwardIterator>
 void
 _M_range_initialize(_ForwardIterator __first, _ForwardIterator __last,
       std::forward_iterator_tag)
 {
   const size_type __n = std::distance(__first, __last);
   this->_M_impl._M_start
     = this->_M_allocate(_S_check_init_len(__n, _M_get_Tp_allocator()));
   this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
   this->_M_impl._M_finish =
     std::__uninitialized_copy_a(__first, __last,
     this->_M_impl._M_start,
     _M_get_Tp_allocator());
 }



      void
      _M_fill_initialize(size_type __n, const value_type& __value)
      {
 this->_M_impl._M_finish =
   std::__uninitialized_fill_n_a(this->_M_impl._M_start, __n, __value,
     _M_get_Tp_allocator());
      }
# 1618 "stl_vector.h"
      template<typename _Integer>
 void
 _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
 { _M_fill_assign(__n, __val); }


      template<typename _InputIterator>
 void
 _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
      __false_type)
 { _M_assign_aux(__first, __last, std::__iterator_category(__first)); }


      template<typename _InputIterator>
 void
 _M_assign_aux(_InputIterator __first, _InputIterator __last,
        std::input_iterator_tag);


      template<typename _ForwardIterator>
 void
 _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
        std::forward_iterator_tag);



      void
      _M_fill_assign(size_type __n, const value_type& __val);







      template<typename _Integer>
 void
 _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val,
      __true_type)
 { _M_fill_insert(__pos, __n, __val); }


      template<typename _InputIterator>
 void
 _M_insert_dispatch(iterator __pos, _InputIterator __first,
      _InputIterator __last, __false_type)
 {
   _M_range_insert(__pos, __first, __last,
     std::__iterator_category(__first));
 }


      template<typename _InputIterator>
 void
 _M_range_insert(iterator __pos, _InputIterator __first,
   _InputIterator __last, std::input_iterator_tag);


      template<typename _ForwardIterator>
 void
 _M_range_insert(iterator __pos, _ForwardIterator __first,
   _ForwardIterator __last, std::forward_iterator_tag);



      void
      _M_fill_insert(iterator __pos, size_type __n, const value_type& __x);
# 1697 "stl_vector.h"
      void
      _M_insert_aux(iterator __position, const value_type& __x);

      void
      _M_realloc_insert(iterator __position, const value_type& __x);
# 1755 "stl_vector.h"
      size_type
      _M_check_len(size_type __n, const char* __s) const
      {
 if (max_size() - size() < __n)
   __throw_length_error(
# 1759 "stl_vector.h" 3
                       (
# 1759 "stl_vector.h"
                       __s
# 1759 "stl_vector.h" 3
                       )
# 1759 "stl_vector.h"
                               );

 const size_type __len = size() + (std::max)(size(), __n);
 return (__len < size() || __len > max_size()) ? max_size() : __len;
      }


      static size_type
      _S_check_init_len(size_type __n, const allocator_type& __a)
      {
 if (__n > _S_max_size(_Tp_alloc_type(__a)))
   __throw_length_error(
       
# 1771 "stl_vector.h" 3
      (
# 1771 "stl_vector.h"
      "cannot create std::vector larger than max_size()"
# 1771 "stl_vector.h" 3
      )
# 1771 "stl_vector.h"
                                                             );
 return __n;
      }

      static size_type
      _S_max_size(const _Tp_alloc_type& __a)
      {



 const size_t __diffmax
   = __gnu_cxx::__numeric_traits<ptrdiff_t>::__max / sizeof(_Tp);
 const size_t __allocmax = _Alloc_traits::max_size(__a);
 return (std::min)(__diffmax, __allocmax);
      }





      void
      _M_erase_at_end(pointer __pos)
      {
 if (size_type __n = this->_M_impl._M_finish - __pos)
   {
     std::_Destroy(__pos, this->_M_impl._M_finish,
     _M_get_Tp_allocator());
     this->_M_impl._M_finish = __pos;
     ;
   }
      }

      iterator
      _M_erase(iterator __position);

      iterator
      _M_erase(iterator __first, iterator __last);
# 1842 "stl_vector.h"
      template<typename _Up>
 _Up*
 _M_data_ptr(_Up* __ptr) const
 { return __ptr; }







      template<typename _Up>
 _Up*
 _M_data_ptr(_Up* __ptr)
 { return __ptr; }

      template<typename _Ptr>
 value_type*
 _M_data_ptr(_Ptr __ptr)
 { return empty() ? (value_type*)0 : __ptr.operator->(); }

      template<typename _Ptr>
 const value_type*
 _M_data_ptr(_Ptr __ptr) const
 { return empty() ? (const value_type*)0 : __ptr.operator->(); }

    };
# 1890 "stl_vector.h"
  template<typename _Tp, typename _Alloc>
    inline bool
    operator==(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return (__x.size() == __y.size()
       && std::equal(__x.begin(), __x.end(), __y.begin())); }
# 1928 "stl_vector.h"
  template<typename _Tp, typename _Alloc>
    inline bool
    operator<(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return std::lexicographical_compare(__x.begin(), __x.end(),
       __y.begin(), __y.end()); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator!=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__x == __y); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator>(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return __y < __x; }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator<=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__y < __x); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator>=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
    { return !(__x < __y); }



  template<typename _Tp, typename _Alloc>
    inline void
    swap(vector<_Tp, _Alloc>& __x, vector<_Tp, _Alloc>& __y)
   
    { __x.swap(__y); }


# 1982 "stl_vector.h"

}
