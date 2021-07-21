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
	second.push_back(3.55);
	second.push_back(7.5);
	ft::vector<float>::iterator	it = second.begin();
	

	for ( ; it != second.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	first.push_back(5);
	first.push_back(10);
	first.push_back(8);
	first.push_back(42);
	first.push_back(21);

	for (ft::vector<int>::reverse_iterator itr = first.rbegin(); itr != first.rend(); ++itr)
		std::cout << *itr << std::endl;
    return (0);
}