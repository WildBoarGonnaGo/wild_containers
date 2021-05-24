#include <iostream>
#include "VectorClass.hpp"

int 	main(void)
{
	Vector	v;
	
	std::cout << v << std::endl;
	v.push_back(37);
	std::cout << v << std::endl;
	v.push_back(199);
	std::cout << v << std::endl;
	Vector w { 1, 2, 3, 4, 5, 49, 54, 29, 68};
	std::cout << w << std::endl;
	
	Vector h;
	for (int i = 0; i <= 22; ++i) {
		h.push_back(i);
		std::cout << h << std::endl;
	}
	while (true) {
		try
		{
			h.pop_back();
			std::cout << h << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cerr << e.what() << std::endl;
			break ;
		}
	}
	return (0);
}