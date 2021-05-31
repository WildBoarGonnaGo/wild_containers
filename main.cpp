#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>

int main(void)
{
	ft::vector<int>		first;
	ft::vector<float>	second(7, 42.21);
	
	for (size_type i = 0; i < second.size(); ++i)
		std::cout << second[i] << ' ';
	std::cout << std::endl;
	
	ft::vector<float>::iterator	it = second.begin();
	
	for ( ; it != second.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
    return (0);
}