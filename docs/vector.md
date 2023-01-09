```cpp
template <class T, class Allocator = std::allocator<T> >
class vector;
```

# Member

## Typedefs

- value_type = T
- allocator_type = Allocator
- size_type = std::size_t
- difference_type = std::ptrdiff_t
---
- reference = allocator_type::reference = value_type&
- const_reference = allocator_type::const_reference = const value_type&
- pointer = allocator_type::pointer = value_type*
- const_pointer = allocator_type::const_pointer = const value_type*
---
- iterator = random access iterator to value_type (must be convertible to const_iterator)
- const_iterator = random access iterator to const value_type
- reverse_iterator
- const_reverse_iterator

## Constructors

```cpp
explicit vector(const allocator_type& alloc = allocator_type());

explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

template <class InputIterator>
vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

vector(const vector& other);
```

Exception : Strong guarantee

Links : [cppreference]() [cplusplus]()

## Destructor

```cpp
~vector();
```

## operator=

```cpp
vector& operator= (const vector& rhs);
```

Iterator invalidity : All

Exception : Basic guarantee

## begin

```cpp
iterator begin();
const_iterator begin() const;
```

## end

```cpp
iterator end();
const_iterator end() const;
```

## rbegin

```cpp
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
```

## rend

```cpp
reverse_iterator rend();
const_reverse_iterator rend() const;
```

## size

```cpp
size_type   size() const;
```

## max_size

```cpp
size_type   max_size() const;
```

## resize

```cpp
void    resize(sizs_type n, value_type val = value_type());
```

Iterator invalidity : end() in case of expand. All in case of reallocation

Exception : No throw if n < size. Strong guarantee if a reallocation happens. Basic guarantee otherwise

## capacity

```cpp
size_type capacity() const;
```

## empty

```cpp
bool empty() const;
```

## reserve

```cpp
void    reserve(size_type n);
```

Iterator invalidity : If reallocation => all invalidated

Exception : Basic guarantee

Throw: length_error if n > max_size

## operator[]

```cpp
reference operator[] (size_type n);
const_reference operator[] (size_type n) const;
```

UB : if n > size

## at

```cpp
reference at(size_type n);
const_reference at(size_type n) const;
```

Exception : Strong guarantee

Throw : out_of_range if n is out of bounds

## front

```cpp
reference front();
const_reference front() const;
```

UB : if container is empty

## back

```cpp
reference back();
const_reference back() const;
```

UB : if container is empty

## data

```cpp
pointer data();
const_pointer data() const;
```

## assign

```cpp
template <class InputIterator>
void assign(InputIterator first, InputIterator last);

void assign(size_type n, const value_type& val);
```

Any previous element are destoyed

Iterator invalidity : all

Exception : Basic guarantee

## push_back

```cpp
void push_back(const value_type& val);
```

Iterator invalidity : all if realloc. Otherwise only end() invalidated

Exception : strong guarantee

## pop_back

```cpp
void pop_back();
```

Iterator invalidity : end() + removed element invalidated

UB : if container is empty

## insert

```cpp
iterator insert(iterator position, const value_type& val);

void insert(iterator position, size_type n, const value_type& val);

template <class InputIterator>
void insert(iterator position, InputIterator first, InputIterator last);
```

Iterator invalidity : all if realloc. Otherwise only position and beyond are invalidated

Exception : Basic guarantee

## erase

```cpp
iterator erase(iterator position);
iterator erase(iterator first, iterator last);
```

Iterator invalidity : position (or first) and beyond are invalidated. 

Exception : Basic

UB : if invalid position of range

## swap

```cpp
void swap(vector& other);
```

## clear

```cpp
void clear();
```

Invalidity : all

## get_allocator

```cpp
allocator_type get_allocator() const;
```

# Non-member

## swap

```cpp
template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y);
```

## Relation operators

```cpp
template <class T, class Alloc>
bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

template <class T, class Alloc>
bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
```

