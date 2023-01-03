```cpp
template <
	class Key,
	class T,
	class Compare = less<Key>,
	class Alloc = allocator<pair<const Key,T>
>
class map;
```

# Member

## Constructors

```cpp
explicit map(
	const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type()
);

template <class InputIterator>
map(
	InputIterator first,
	InputIterator last,
	const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type()
);

map(const map& other);
```

Exception: Strong guarantee

UB: if range [first, last) is invalid

## Destructor

```cpp
~map();
```

Invalid: all

## operator=

```cpp
map& operator=(const map& rhs);
```

Invalid: all from `this` map

Exception: Basic guarantee

---

## begin

```cpp
iterator		begin();
const_iterator	begin() const;
```

## end

```cpp
iterator		end();
const_iterator	end() const;
```

## rbegin

```cpp
reverse_iterator		rbegin();
const_reverse_iterator	rbegin() const;
```

## rend

```cpp
reverse_iterator		rend();
const_reverse_iterator	rend() const;
```

---

## empty

```cpp
bool empty() const;
```

## size

```cpp
size_type size() const;
```

## max_size

```cpp
size_type max_size() const;
```

---

## operator[]

```cpp
mapped_type& operator[](const key_type& k);
```

Exception: Strong guarantee

## at

```cpp
mapped_type&		at (const key_type& k);
const mapped_type&	at (const key_type& k) const;
```

Exception: Strong guarantee

Throw: out_of_range if `k` is not in map

---

## insert

```cpp
pair<iterator,bool> insert(const value_type& val);

iterator insert(iterator position, const value_type& val);

template <class InputIterator>
void insert(InputIterator first, InputIterator last);
```

Exception: Basic guarantee

## erase

```cpp
void		erase(iterator position);
size_type	erase(const key_type& k);
void		erase(iterator first, iterator last);
```

Invalid: only erased elements

## swap

```cpp
void swap(map& x);
```

## clear

```cpp
void clear();
```

Invalid: all

---

## key_comp

```cpp
key_compare key_comp() const;
```

Exception: Strong guarantee

## value_comp

```cpp
value_compare value_comp() const;
```

Exception: Strong guarantee

## get_allocator

```cpp
allocator_type get_allocator() const;
```

---

## find

```cpp
iterator		find(const key_type& k);
const_iterator	find(const key_type& k) const;
```

Exception: Strong guarantee

## count

```cpp
size_type count(const key_type& k) const;
```

Exception: Strong guarantee

## lower_bound

```cpp
iterator		lower_bound(const key_type& k);
const_iterator	lower_bound(const key_type& k) const;
```

Exception: Strong guarantee

## upper_bound

```cpp
iterator		upper_bound(const key_type& k);
const_iterator	upper_bound(const key_type& k) const;
```

Exception: Strong guarantee

## equal_range

```cpp
pair<iterator,iterator>				equal_range(const key_type& k);
pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
```

Exception: Strong guarantee

# Non-member

## swap

```cpp
template< class Key, class T, class Compare, class Alloc >
void swap( std::map<Key,T,Compare,Alloc>& lhs,
           std::map<Key,T,Compare,Alloc>& rhs );
```

## Relation operator

```cpp
template< class Key, class T, class Compare, class Alloc >
bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator< ( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator> ( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );
```