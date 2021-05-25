// Iterator
#include <vector>
#include <iterator>
#include <iostream>
#include <list>

int main(void) {
	std::list<int>	v = {1, 2, 3, 4, 5};
	//since c++11
	
	//iterator - is a inner type
	for (std::list<int>::iterator it = v.begin(); it != v.end();
		++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}