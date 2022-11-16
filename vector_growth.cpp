#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;

	for (int i = 0; i<50; i++)
	{
		std::cout << "Before: " << v.capacity(); 
		v.push_back(i);
		std::cout << "    After: " << v.capacity() << std::endl; 
	}
	v.assign( 32, 2 );
	v.push_back(1564135);
	std::cout << " assign: " << v.capacity() << std::endl; 
	std::cout << v[10] << std::endl;
	std::cout << v.at(40) << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	return (0);
}