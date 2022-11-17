#include <iostream>
#include <vector>

template <typename T>
void	vinfo(std::vector<T>& v)
{
	std::cout	<< "Vector size     = " << v.size() << std::endl;
	std::cout	<< "Vector capacity = " << v.capacity() << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v1(100, 2);
	std::vector<int> v2(150, 2);


	vinfo(v1);
	vinfo(v2);

	v1 = v2;
	// v2.reserve(200);

	vinfo(v1);
	vinfo(v2);

	return (0);
}