# ft_containers

## Exemple d'implementations

GNU
https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a00739.html#ac49dfb9f917a249a935a1d4d815d8e18

Google
https://github.com/google/libcxx/blob/master/include/vector

Microsoft
https://github.com/microsoft/STL/blob/main/stl/inc/vector#L494

LLVM
https://github.com/llvm/llvm-project/tree/main/libcxx/include

uSTL
https://github.com/msharov/ustl

smallSTL (not really)
https://github.com/alandefreitas/small

https://cplusplus.com/forum/general/219746/

https://www.stroustrup.com/except.pdf

TinySTL
https://github.com/mendsley/tinystl

DummyVector
https://leimao.github.io/blog/CPP-Const-Iterator/

## Vector

### Private attributes

- Pointer to first element
- Pointer to past the last element
- Pointer to past the last allocated space
- The allocator

```cpp
template <class T, class A = std::allocator<T> >
class vector {
public:
    // public member functions
private:
    T* data_;         // points to first element
    T* end_capacity_; // points to one past internal storage
    T* end_;          // points to one past last element
    A  allocator_;
};
```

## Liens utiles pour vector

Minimal vector
https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/

https://stackoverflow.com/questions/3064559/how-is-vector-implemented-in-c

SFINAE 
https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/

Allocator
https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed

Conteneur et iterateur
https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Intro--Conteneurs-Iterateurs.html

Exceptions
https://www.stroustrup.com/except.pdf