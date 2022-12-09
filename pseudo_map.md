# Node

```yml
Attributes:
	- value (pair)
	- parent (malloced pointer to Node)
	- left (malloced pointer to Node)
	- right (malloced pointer to Node)

Constructors:
	- Construct with value given.

Note:
	- Each node instance should be malloced
```

# MapIterator

```yml
Attributes:
	- _ptr (pointer to Node)
	- _root (pointer to Node)

Constructors/Destructors:
	- default constructor
	- copy constructor
	- param constructor: pointer to Node
	- destructor

Private Methods:
	- _maximum
	- _predecessor
	- _successor

Public Methods:
	- operator* => dereference _ptr
	- operator-> => ??
	- operator++ (prefix and postfix) => give the next element
	- operator-- (prefix and postfix) => give the prev element

Note:
	- If _ptr is NULL => past-the-end element
	- A MapIterator should not be malloced
```

DETAILS

```yml
_maximum:
	- takes: a pointer to Node
	- returns: a pointer to Node
	- what: a pointer to Node with the maximum key
	- how: go to the right-most node from the given pointer and return it
	- note:

_predecessor:
	- takes: nothing (except current instance pointer)
	- returns: a pointer to Node
	- what: a pointer to Node with the closest lower key according to the current node
	- how: If _ptr is NULL => return _maximum. Otherwise, classic algo
	- note: 

_successor:
	- takes: nothing (except current instance pointer)
	- returns: a pointer to Node
	- what: a pointer to Node with the closest higher key according to the current node
	- how: classic algo
	- note: 

operator*:
	- takes: nothing (except current instance pointer)
	- returns: A reference to the value_type from the container (=pair)
	- what: Access the value of interest
	- how: Accessing the value attribute of Node
	- note:

operator->:
	- takes: nothing (except current instance pointer)
	- returns: an address to the value_type from the container (=pair)
	- what: Access the value of interest and give an address to it
	- how: Accessing the value attribute of Node and reference it
	- note:

operator++ (prefix):
	- takes: nothing (except current instance pointer)
	- returns: a reference to the current instance 
	- what: increment the iterator
	- how: set its _ptr to the return value of _successor()
	- note:

operator-- (prefix):
	- takes: nothing (except current instance pointer)
	- returns: a reference to the current instance 
	- what: decrement the iterator
	- how: set its _ptr to the return value of _predecessor()
	- note:
```

# Map

```yml
Attributes:
	- _root (pointer to Node)
	- _size (size_type)
	- _comp (key_compare)
	- _alloc (alloc_type)
	- _alloc_node (std::allocator<Node>)

Constructors/Destructors:
	- Default constructor
	- Range constructor
	- Copy constructor
	- operator=
	- Destructor

Public methods:
	- at
	- operator[]

	- begin
	- end
	- rbegin
	- rend

	- empty
	- size
	- max_size

	- clear
	- insert
	- erase
	- swap

	- count
	- find
	- equal_range
	- lower_bound
	- upper_bound

	- key_comp
	- value_comp

Non-member functions:
	- swap
	- operator==
	- operator!=
	- operator<
	- operator>
	- operator<=
	- operator>=
```

DETAILS

```yml

```

