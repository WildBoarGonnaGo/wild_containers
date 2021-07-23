#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>

int main(void)
{
	ft::vector<int>				first;
	ft::vector<float>			second(7, 42.21);
	ft::vector<std::string>		strVector;
	std::vector<int>			diffVal;
	std::vector<std::string>	secDiffVal;
	
	std::cout << "\033[32;1mFILL CONSTRUCTOR AND OPERATOR[]:\033[0m" << "\033[36;1m" <<std::endl;
	for (size_type i = 0; i < second.size(); ++i)
		std::cout << second[i] << ' ';
	std::cout << std::endl;
	second.push_back(3.55);
	second.push_back(7.5);
	ft::vector<float>::iterator	it = second.begin();	

	std::cout << "\033[32;1mITERATOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for ( ; it != second.end(); ++it)
		std::cout << *it << ' ';
	std::cout << "\033[0m" << std::endl;
	first.push_back(5);
	first.push_back(10);
	first.push_back(8);
	first.push_back(42);
	first.push_back(21);

	std::cout << "\033[32;1mPUSH BACK AND REVERSE ITERATOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for (ft::vector<int>::reverse_iterator itr = first.rbegin(); itr != first.rend(); ++itr)
		std::cout << *itr << ' ';
	std::cout << "\033[0m" << std::endl;
	ft::vector<int>	third(first.begin(), first.end());
	std::cout << "\033[32;1mRANGE CONSTRUCTOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for (ft::vector<int>::iterator it2 = third.begin(); it2 != third.end(); ++it2)
		std::cout << *it2 << ' ';
	std::cout << "\033[0m" << std::endl;
	second.push_back(6.66);
	second.push_back(3.147264);
	ft::vector<float>	forth(second);
	std::cout << "\033[32;1mCOPY CONTSTRUCTOR TEST WITH PUSH_BACK:\033[0m" << "\033[36;1m" <<std::endl;
	for (size_type i = 0; i < forth.size(); ++i)
		std::cout << forth[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[32;1mMAX_SIZE FUNCTION TEST (FIRST VECTOR):\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << forth.max_size() << "\033[0m" << std::endl;
	std::cout << "\033[35;1mMAX_SIZE FUNCTION FOR STANDART CONTAINER (INTEGER TYPE):\033[0m" << "\033[32;1m" <<std::endl;
	std::cout << diffVal.max_size() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mVECTOR RESIZE TEST:\033[0m" << "\033[36;1m" <<std::endl;
	//resizing vector
	ft::vector<int>	resizeVector;
	//set some initial content:

	for (std::size_t i = 0; i < 10; i++) 
		resizeVector.push_back(i);
	resizeVector.resize(5);
	resizeVector.resize(8, 100);
	resizeVector.resize(12);
	for (std::size_t i = 0; i < resizeVector.size(); ++i)
		std::cout << resizeVector[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	diffVal.push_back(5);
	diffVal.push_back(10);
	diffVal.push_back(8);
	diffVal.push_back(42);
	diffVal.push_back(21);
	std::cout << "\033[35;1mSTANDARD CONTAINER CAPACITY (INTEGER TYPE):\033[0m" << "\033[32;1m" <<std::endl;
	std::cout << diffVal.capacity() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mVECTOR CAPACITY (FIRST VECTOR):\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << first.capacity() << "\033[0m" << std::endl;
	std::cout << "\033[35;1mIS STANDARD CONTAINER EMPTY (diffVal):\033[0m" << "\033[32;1m" <<std::endl;
	std::cout << std::boolalpha << diffVal.empty() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mIS VECTOR EMPTY (first):\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << std::boolalpha << first.empty() << "\033[0m" << std::endl;
	std::cout << "\033[35;1mIS STANDARD CONTAINER EMPTY (secDiffVal):\033[0m" << "\033[32;1m" <<std::endl;
	std::cout << std::boolalpha << secDiffVal.empty() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mIS VECTOR EMPTY (strVector):\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << std::boolalpha << strVector.empty() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mCONSTANT ITERATOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for (ft::vector<int>::const_iterator it2 = third.begin(); it2 != third.end(); ++it2)
		std::cout << *it2 << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[32;1mREVERSE CONSTANT ITERATOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for (ft::vector<int>::const_reverse_iterator it2 = third.rbegin(); it2 != third.rend(); ++it2)
		std::cout << *it2 << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[32;1mFRONT FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << third.front() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mBACK FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << third.back() << "\033[0m" << std::endl;
    return (0);
}