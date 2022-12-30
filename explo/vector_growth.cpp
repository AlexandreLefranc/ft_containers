#include <iostream>
#include <vector>

template <typename T>
void	vinfo(T& v)
{
	std::cout	<< "Vector size     = " << v.size() << std::endl;
	std::cout	<< "Vector capacity = " << v.capacity() << std::endl;
	std::cout << std::endl;
}

template <typename T>
void	print_vector(T& v)
{
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v(5, 1);

	vinfo(v);
	v.insert( v.end(), 4, 4 );
	print_vector(v);
	vinfo(v);
	v.insert( v.end(), 4, 4 );
	print_vector(v);
	vinfo(v);

	return (0);
}