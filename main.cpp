#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "map.hpp"

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
	std::cout << "\033[32;1mRESERVE FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;

	ft::vector<int> foo;

	size_type sz;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::cout << "\033[0m";
	std::cout << "\033[32;1mASSIGN FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
	ft::vector<int> vec1;
	ft::vector<int> vec2;
	ft::vector<int> vec3;

	vec1.assign(7, 100);
	ft::vector<int>::iterator   it3;
	it3 = vec1.begin() + 1;
	vec2.assign(it3, vec1.end() - 2);
	vec3.push_back(1776);
	vec3.push_back(7);
	vec3.push_back(4);
	vec2.assign(vec3.begin(), vec3.end());
	for (size_type i = 0; i < vec2.size(); ++i)
		std::cout << vec2[i] << ' ';
	std::cout << std::endl << "vec2 size: " << vec2.size() << std::endl;
	std::cout << "vec3 size: " << vec3.size() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mPOP_BACK FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
	vec2.pop_back();
	vec3.pop_back();
	std::cout << "vec2 vector: ";
	for (size_type i = 0; i < vec2.size(); ++i)
		std::cout << vec2[i] << ' ';
	std::cout << std::endl << "vec3 vector: ";
	for (size_type i = 0; i < vec3.size(); ++i)
		std::cout << vec3[i] << ' ';
	std::cout << std::endl << "vec2 size: " << vec2.size() << std::endl;
	std::cout << "vec3 size: " << vec3.size() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mINSERT FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
	ft::vector<int> myvector(3, 100);
	ft::vector<int>::iterator   it4;

	it4 = myvector.begin();
	it4 = myvector.insert(it4, 200);
	myvector.insert(it4, 2, 300);
	//"it" is no longer valid, get a new one
	it4 = myvector.begin();
	ft::vector<int> ft_anothervector(2, 400);
	myvector.insert(it4 + 2, ft_anothervector.begin(), ft_anothervector.end());
	ft::vector<int> ft_myarray;
	ft_myarray.push_back(501);
	ft_myarray.push_back(502);
	ft_myarray.push_back(503);
	myvector.insert(myvector.begin(), ft_myarray.begin(), ft_myarray.end());
	std::cout << "myvector contains: ";
	for (size_type i = 0; i < myvector.size(); ++i)
		std::cout << myvector[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[35;1mIS STANDARD INSERT FUNCTION TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::vector<int> my_stdvector(3, 100);
	std::vector<int>::iterator   it5;

	it5 = my_stdvector.begin();
	it5 = my_stdvector.insert(it5, 200);
	my_stdvector.insert(it5, 2, 300);
	it5 = my_stdvector.begin();
	std::vector<int> std_anothervector(2, 400);
	myvector.insert(it4 + 2, ft_anothervector.begin(), ft_anothervector.end());
	std::vector<int> std_myarray;
	std_myarray.push_back(501);
	std_myarray.push_back(502);
	std_myarray.push_back(503);
	my_stdvector.insert(it5 + 2, std_anothervector.begin(), std_anothervector.end());
	my_stdvector.insert(my_stdvector.begin(), std_myarray.begin(), std_myarray.end());
	std::cout << "my_stdvector contains: ";
	for (size_type i = 0; i < my_stdvector.size(); ++i)
		std::cout << my_stdvector[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[32;1mERASE CLEAR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	myvector.clear();
	std::cout << std::boolalpha << "is myvector empty: " << myvector.empty() << "\033[0m" << std::endl;
	std::cout << "\033[35;1mIS STANDARD CLEAR FUNCTION TEST:\033[0m" << "\033[32;1m" <<std::endl;
	my_stdvector.clear();
	std::cout << std::boolalpha << "is my_stdvector empty: " << my_stdvector.empty() << "\033[0m" << std::endl;
	std::cout << "\033[32;1mERASE FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for (int i = 0; i <= 10; ++i)
		myvector.push_back(i);
	//erase the 6th element
	myvector.erase(myvector.begin() + 5);
	//erase the first 3 elements
	myvector.erase(myvector.begin(), myvector.begin() + 3);
	for (size_type i = 0; i < myvector.size(); ++i)
		std::cout << myvector[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[35;1mSTANDARD ERASE FUNCTION TEST:\033[0m" << "\033[32;1m" <<std::endl;
	for (int i = 0; i <= 10; ++i)
		my_stdvector.push_back(i);
	//erase the 6th element
	my_stdvector.erase(my_stdvector.begin() + 5);
	//erase the first 3 elements
	my_stdvector.erase(my_stdvector.begin(), my_stdvector.begin() + 3);
	for (size_type i = 0; i < my_stdvector.size(); ++i)
		std::cout << my_stdvector[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[32;1mSWAP FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
	ft::vector<int> ft_foo(3, 100);
	ft::vector<int> ft_bar(5, 200);
	ft_foo.swap(ft_bar);
	std::cout << "ft_foo contains: ";
	for (size_type i = 0; i < ft_foo.size(); ++i)
		std::cout << ft_foo[i] << ' ';
	std::cout << std::endl;
	std::cout << "ft_bar contains: ";
	for (size_type i = 0; i < ft_bar.size(); ++i)
		std::cout << ft_bar[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[35;1mSTANDARD SWAP FUNCTION TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::vector<int> std_foo(3, 100);
	std::vector<int> std_bar(5, 200);
	std_foo.swap(std_bar);
	std::cout << "std_foo contains: ";
	for (size_type i = 0; i < std_foo.size(); ++i)
		std::cout << std_foo[i] << ' ';
	std::cout << std::endl;
	std::cout << "std_bar contains: ";
	for (size_type i = 0; i < std_bar.size(); ++i)
		std::cout << std_bar[i] << ' ';
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[32;1mRELATIONAL OPERATORS TEST:\033[0m" << "\033[36;1m" <<std::endl;
	ft::vector<double>  ft_foo2(3, 3.14);
	ft::vector<double>  ft_bar2(2, 1.57);
	if (ft_foo == ft_bar) std::cout << "ft_foo and ft_bar are equal\n";
	if (ft_foo != ft_bar) std::cout << "ft_foo and ft_bar are not equal\n";
	if (ft_foo < ft_bar) std::cout << "ft_foo is less than ft_bar\n";
	if (ft_foo > ft_bar) std::cout << "ft_foo is greater than ft_bar\n";
	if (ft_foo <= ft_bar) std::cout << "ft_foo is less than or equal to ft_bar\n";
	if (ft_foo >= ft_bar) std::cout << "ft_foo is greater than or equal to ft_bar\n";
	if (ft_foo2 == ft_bar2) std::cout << "ft_foo2 and ft_bar2 are equal\n";
	if (ft_foo2 != ft_bar2) std::cout << "ft_foo2 and ft_bar2 are not equal\n";
	if (ft_foo2 < ft_bar2) std::cout << "ft_foo2 is less than ft_bar2\n";
	if (ft_foo2 > ft_bar2) std::cout << "ft_foo2 is greater than ft_bar2\n";
	if (ft_foo2 <= ft_bar2) std::cout << "ft_foo2 is less than or equal to ft_bar2\n";
	if (ft_foo2 >= ft_bar2) std::cout << "ft_foo2 is greater than or equal to ft_bar2";
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[35;1mSTANDARD RELATIONAL OPERATORS TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::vector<double>  std_foo2(3, 3.14);
	std::vector<double>  std_bar2(2, 1.57);
	if (std_foo == std_bar) std::cout << "std_foo and std_bar are equal\n";
	if (std_foo != std_bar) std::cout << "std_foo and std_bar are not equal\n";
	if (std_foo < std_bar) std::cout << "std_foo is less than std_bar\n";
	if (std_foo > std_bar) std::cout << "std_foo is greater than std_bar\n";
	if (std_foo <= std_bar) std::cout << "std_foo is less than or equal to std_bar\n";
	if (std_foo >= std_bar) std::cout << "std_foo is greater than or equal to std_bar\n";
	if (std_foo2 == std_bar2) std::cout << "std_foo2 and std_bar2 are equal\n";
	if (std_foo2 != std_bar2) std::cout << "std_foo2 and std_bar2 are not equal\n";
	if (std_foo2 < std_bar2) std::cout << "std_foo2 is less than std_bar2\n";
	if (std_foo2 > std_bar2) std::cout << "std_foo2 is greater than std_bar2\n";
	if (std_foo2 <= std_bar2) std::cout << "std_foo2 is less than or equal to std_bar2\n";
	if (std_foo2 >= std_bar2) std::cout << "std_foo2 is greater than or equal to std_bar2";
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[32;1mPAIR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	ft::pair<std::string, double>	product1;
	ft::pair<std::string, double>	product2("tomatoes", 2.30);
	ft::pair<std::string, double>	product3(product2);

	product1 = ft::make_pair(std::string("lightbulbs"), 0.99);
	product2.first = "shoes";
	product2.second = 39.90;

	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is $" << product3.second << "\033[0m" << std::endl;
	std::cout << "\033[32;1mMAP CONSTRUCTOR:\033[0m" << "\033[36;1m" <<std::endl;
	ft::map<char, int>	firstMap;

	firstMap['b'] = 20;
	firstMap['a'] = 10;
	firstMap['d'] = 70;
	firstMap['c'] = 30;

	for (ft::map<char, int>::iterator itMap = firstMap.begin(); itMap != firstMap.end(); ++itMap)
		std::cout << itMap->first << " => " << itMap->second << std::endl;
    return (0);
}