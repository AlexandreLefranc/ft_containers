<style>
red { color: red }
yellow { color: yellow }
</style>

# Effective C++ Third Edition

Scott Meyers

55 Specific Ways to Improve your Programs and Design

## Chapter 1: Accustoming Yourself to C++

### Item 1: View C++ as a federation of languages

C++ = C + C with Classes + Template + STL

### Item 2: Prefer `const`, `enum` and `inline` to `#define`

Because `#define` are not seen by compilers, it can lead to difficult debug.

`const` create only one copy of the variable whereas `#define` create rvalue wherever it is called.

`inline` are similar to `#define` macros but much safer !

<red>Summary</red>

- For simple constants, prefer `const` or `enum` to `#define`.
- For function-like macros, prefer `inline` functions to `#define`.

### Item 3: Use `const` whenever possible.

It allows you to communicate to both compilers and other programmers that value should remain invariant.

`const` on pointers:

```cpp
char greeting[] = "Hello";
char *p = greeting; // non-const pointer,
                    // non-const data
const char *p = greeting; // non-const pointer,
                          // const data
char * const p = greeting; // const pointer,
                           // non-const data
const char * const p = greeting; // const pointer,
                                 // const data
```

`const` on iterators:

```cpp
std::vector<int> vec;
...
const std::vector<int>::iterator iter = vec.begin(); 
// iter acts like a T* const
*iter = 10; // OK, changes what iter points to
++iter; // error! iter is const

std::vector<int>::const_iterator cIter = vec.begin();
// cIter acts like a const T*
*cIter = 10; // error! *cIter is const
++cIter; // fine, changes cIter
```

`const` on member functions:

The purpose of const on member functions is to identify which member functions may be invoked on const objects.

```cpp
class TextBlock {
public:
...
    const char& operator[](std::size_t position) const // operator[] for
    { return text[position]; }                         // const objects

    char& operator[](std::size_t position) // operator[] for
    { return text[position]; }             // non-const objects
private:
    std::string text;
};
```

### Item 4: Make sure that objects are initialized before they are used

- Always initialized built-in types
- For classes, all constructors should initialized everything it the object
- For classes, prefer initialization list. Because initalization list copy-construct, where constructor body assignment default-construct + assignment operation. It is more efficient. Also more consistent.
- For classes, even for default constructor, use initialization list with empty arguments. It explicits the call of default constructor for attributes. And ensure no built-in types attributes have been forgotten.

## Chapter 2: Constructors, Destructors and Assignment Operators

### Item 5: Know what functions C++ silently writes dans calls

- For classes, if not given, compilers will declare their own versions of copy constructor, copy assignment operator and destructor. If there is no constructor declared by the programmer at all, compilers declare default constructor.

### Item 6: Explicitly disallow the use of compiler-generated functions you don't want

- To disable compiler-generated functions, declare them private. Typically copy-constructor and copy assignment operator.
- To prevent member and friend functions to calling them, only declare them without defining them.
- By convention, in such case, parameter names are not specified

```cpp
class HomeForSale {
public:
    ...
private:
    ...
    HomeForSale(const HomeForSale&); // declarations only
    HomeForSale& operator=(const HomeForSale&);
};
```

### Item 7: Declare destructors virtual in polymorphic base classes

- Polymorphic base classes should declare virtual destructors. If a
class has any virtual functions, it should have a virtual destructor.
- Classes not designed to be base classes or not designed to be used
polymorphically should not declare virtual destructors.
- Never inherit from `std::string` nor STL container !

### Item 8: Prevent exceptions from leaving destructors

- If an exception can be thrown in the destructor, you must not let the exception going out of the destructor -> catch it inside destructor.
- Option 1: Catch and terminate the program
- Option 2: Catch and swallow the exception, i.e. ignore it
- Option 3: Provide a way to explicitly delete/close things outside of destructor through a member function. This gives the user the opportunity to catch the exception themself and deal with it.

A bit foggy, read the full item if need to understand more.

### Item 9: Never call virtual functions during construction or destruction

- Don't because calling them that way will never go to a more derived class

### Item 10: Have assignment operators return a reference to `*this`

- Enable chain of assignments
- This convention applies to `+=`, `-=`, `*=`, etc

### Item 11: Handle assignment to self in `operator=`

Two problem to deal with:

- Need to be self-assignment safe: `delete obj; obj = new Object(*rhs.obj)` is unsafe in case of self-assignment because `rhs.obj` has been deleted.
- Need to be exception safe: `delete obj; obj = new Object(*rhs.obj)` is unsafe because if `new` throws, `obj` hold a pointer to deleted object, which will probably lead to a double free somewhere.

How ?

- Option 1: Check identity `if (this == &rhs) return *this`. It is self-assignment safe but not exception safe.
- Option 2: Delete after the `new`:

```cpp
Object *tmp = obj;
obj = new Object(*rhs.obj);
delete tmp;
```

Option 2 is both self-assignment and exception safe !

### Item 12: Copy all parts of an object

- When adding an attribute to an existing class, remind to update copy-constructor and copy assignment operator + all the constructors
- Be aware, when calling copy-constructor or copy assignment operator on derived object, to also copy the base class !

```cpp
class Customer {
public:
    ...
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
    ...
private:
    std::string name;
};

class PriorityCustomer: public Customer { // a derived class
public:
    ...
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);
    ...
private:
    int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
    : Customer(rhs), // invoke base class copy ctor
    , priority(rhs.priority)
{}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
    Customer::operator=(rhs); // assign base class parts
    priority = rhs.priority;
    return *this;
}
```

## Chapter 3: Resource Management

### Item 13: Use objects to manage resources

Use smart pointer. It deletes the object it points to when it is destroyed.

- To prevent resource leaks, use RAII objects that acquire resources in their constructors and release them in their destructors.
- Two commonly useful RAII classes are `shared_ptr` and `auto_ptr`. `shared_ptr` is usually the better choice, because its behavior when copied is intuitive. Copying an `auto_ptr` sets it to null.

### Item 14: Think carefully about copying behavior in resource-managing classes

- Option 1: Disable copying
- Option 2: Reference-count the underlying resource. Allow several `shared_ptr` and count the number of `shared_ptr` pointing to the resource. When the count goes to 0, release the resource.
- Option 3: Copy the underlying resource. Perform a deep copy
- Option 4: Transfer ownership of the underlying resource, such as in `auto_ptr`

### Item 15: Provide access to raw resources in resource-managing classes

- APIs often require access to raw resources, so each RAII class should offer a way to get at the resource it manages.
- Access may be via explicit conversion (`get()` method) or implicit conversion. In general, explicit conversion is safer, but implicit conversion is more convenient for clients.

### Item 16: Use the same form in corresponding uses of `new` and `delete`

- If you use `[]` in a new expression, you must use `[]` in the corresponding delete expression.
- If you don’t use `[]` in a new expression, you mustn’t use `[]` in the corresponding delete expression.

### Item 17: Store `new`ed objects in smart pointers in standalone statements

Don't do this

```cpp
processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());
```

Do this

```cpp
std::tr1::shared_ptr<Widget> pw(new Widget); // store newed object
                                             // in a smart pointer in a
                                             // standalone statement
processWidget(pw, priority()); 
```

## Chapter 4: Designs and Declarations

### Item 18: Make interfaces easy to use correctly and hard to use incorrectly

- Consider the kinds of mistakes a client might make
- Introduce new type when you expect specific arguments
- New types should behave consistently, aka like `int`
- Use of smart pointer to not rely on client for deleting objects

### Item 19: Treat class design as type design

C++ is about creating classes and classes are types. So C++ is about creating types.

- Think how to create and destroy the class
- Think the assignment operator
- When creating conversion behavior, beaware of cases where the object is passed by value
- Think of valid values for your class and how to handle incorrect values
- Think if you want to be inheritable or not
- Implicit type conversion (`operator T2`) vs explicit type conversion (constructor `T2(T1)`) ?
- Implement meaningful behaviors
- What behavior you want to disable, make private
- Think the scope (public, protected, private) for each member
- Think of exception safety
- If your class is a whole family of class, consider make it a template
- Is few non-member function not better than creating a new class ?

### Item 20: Prefer pass-by-ref-to-const to pass-by-value

- pass-by-value calls the copy constructor, then the destructor. So it is computing expensive. And memory expensive because you have to use stack and heap memory to create the new temporary object

```cpp
bool validateStudent(Student s);        // Expensive
bool validateStudent(const Student& s); // better
```

- Avoid slicing problem: If function takes Base class arguments by value, using the function with Derived class argument will sliced off. The actual object will be the Base object even though you passed the Derived one.

```cpp
class Window;                         // base
class WindowImproved: public Window;  // derived
displayWindow(Window w);              // incorrect! may be sliced

WindowImproved wi;
displayWindow(wi);                    // wi is sliced into its Window part only
```

Instead:

```cpp
displayWindow(const Window& w);        // fine! won't be sliced
```

- The exception is built-in types and iterators that are meant to be passed by value.

### Item 21: Don't try to return a reference when you must return an object

- Sometimes, the only good choice is to return by value
- Never return a pointer or reference to local stack object
- Never return a reference to heap-based object
- Avoir return a pointer or reference to local static object

```cpp
// BAD ! Reference to destroyed object !
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
    Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
    return result;
}

// BAD ! Undeletable heap-based object
const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
    Rational *result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
    return *result;
}

// OK ! 
const Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}
```

### Item 22: Declare data member `private`

- Control to give getter/setter, only getter or nothing to the client
- Hide implementation behind interface function. Gives flexibility if you want to change the implementation. It also doesn't break any code using the data member if you want to remove it.
- `protected` is no more encapsulated than `public`

### Item 23: Prefer non-member non-friend functions to member functions

- All functions that don't really need to access data of a class should be non-member non-friend functions

### Item 24: Declare non-member functions when type conversions should apply to all parameters

- Errrm unclear but it doesn't look not very important. Read it if you want to know about it

### Item 25: Consider support for a non-throwing `swap`

Unclear

- Provide a swap member function when std::swap would be inefficient for your type. Make sure your swap doesn’t throw exceptions.
- If you offer a member swap, also offer a non-member swap that calls the member. For classes (not templates), specialize std::swap, too.
- When calling swap, employ a using declaration for std::swap, then call swap without namespace qualification.
- It’s fine to totally specialize std templates for user-defined types, but never try to add something completely new to std.

## Implementations

### Item 26: Postpone variable definitions as long as possible

- Postpone definition until you use it
- Postpone definition until you get everything to intialize it
- Define and intialize in the same line => Avoid default-construct +  copy assignation

```cpp
// Approach A: define outside loop
Widget w;
for (int i = 0; i < n; ++i) {
    w = some value dependent on i;
}

// Approach B: define inside loop
for (int i = 0; i < n; ++i) {
    Widget w(some value dependent on i);
}
```

- In loops, prefer approach B unless:
    - You know that assignment is less expensive then constructor-destructor
    - AND your are dealing with performance sensitive part of the code

### Item 27: Minimize casting

- In C++, casting is dangerous. So to avoid
- Avoid casts whenever practical, especially dynamic_casts in performance-sensitive code. If a design requires casting, try to develop a cast-free alternative.
- When casting is necessary, try to hide it inside a function. Clients can then call the function instead of putting casts in their own code.
- Prefer C++-style casts to old-style casts. They are easier to see, and they are more specific about what they do.

### Item 28: Avoid returning 'handles' to object internals

- References, pointers and iterators are all 'handles'
- Handles can break encapsulation: A data member is only as encapsulated as the most accessible function returning a handle to it
- Avoir returning handles
- If you have to return an handle, consider make it `const`
- Be careful of handles that outlive it object. If the object is destroyed before the handle, the handle will be left dangling

### Item 29: Strive for exception-safe code


### Item
### Item
### Item











