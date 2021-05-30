#include "vector.hpp"
#include <iostream>

int main(void)
{
	ft::vector<int>		first;
	ft::vector<float>	second(7, 42.21);
	
	for (size_type i = 0; i < second.size(); ++i)
		std::cout << second[i] << ' ';
	std::cout << std::endl;
    return (0);
}