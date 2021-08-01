#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "map.hpp"
#include "iterator.hpp"
#include <map>

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
	std::cout << "\033[32;1mFT MAP DEFAULT CONSTRUCTOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	ft::map<char, int>	ft_firstMap;

	ft_firstMap['b'] = 20;
	ft_firstMap['a'] = 10;
	ft_firstMap['d'] = 70;
	ft_firstMap['c'] = 30;

	for (ft::map<char, int>::iterator itMap = ft_firstMap.begin(); itMap != ft_firstMap.end(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	std::cout << "\033[32;1mFT MAP RANGE CONSTRUCTOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	ft::map<char, int> ft_secondMap(ft_firstMap.begin(), ft_firstMap.end());
	for (ft::map<char, int>::iterator itMap = ft_secondMap.begin(); itMap != ft_secondMap.end(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	ft_secondMap['A'] = 5;
	ft_secondMap['B'] = 7;
	ft_secondMap['e'] = 80;
	ft::map<char, int>  ft_thirdMap(ft_secondMap);
	std::cout << "\033[32;1mFT MAP COPY CONSTRUCTOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for (ft::map<char, int>::iterator itMap = ft_thirdMap.begin(); itMap != ft_thirdMap.end(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	std::cout << "\033[32;1mFT MAP REVERSE ITERATOR TEST:\033[0m" << "\033[36;1m" <<std::endl;
	for (ft::map<char, int>::reverse_iterator itMap = ft_thirdMap.rbegin(); itMap != ft_thirdMap.rend(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	std::cout << "\033[35;1mSTANDARD MAP DEFAULT CONSTRUCTOR TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::map<char, int>	std_firstMap;

	std_firstMap['b'] = 20;
	std_firstMap['a'] = 10;
	std_firstMap['d'] = 70;
	std_firstMap['c'] = 30;

	for (std::map<char, int>::iterator itMap = std_firstMap.begin(); itMap != std_firstMap.end(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	std::cout << "\033[35;1mSTANDARD MAP RANGE CONSTRUCTOR TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::map<char, int> std_secondMap(std_firstMap.begin(), std_firstMap.end());
	for (std::map<char, int>::iterator itMap = std_secondMap.begin(); itMap != std_secondMap.end(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	std_secondMap['A'] = 5;
	std_secondMap['B'] = 7;
	std_secondMap['e'] = 80;
	std::map<char, int>  std_thirdMap(std_secondMap);
	std::cout << "\033[35;1mSTANDARD MAP COPY CONSTRUCTOR TEST:\033[0m" << "\033[32;1m" <<std::endl;
	for (std::map<char, int>::iterator itMap = std_thirdMap.begin(); itMap != std_thirdMap.end(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	std::cout << "\033[35;1mSTANDARD MAP REVERSE ITERATOR TEST:\033[0m" << "\033[32;1m" <<std::endl;
	for (std::map<char, int>::reverse_iterator itMap = std_thirdMap.rbegin(); itMap != std_thirdMap.rend(); ++itMap)
	    std::cout << itMap->first << " => " << itMap->second << std::endl;
	std::cout << "\033[0m";
	std::cout << "\033[32;1mFT MAP SIZE TEST:\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << ft_thirdMap.size() <<"\033[0m" << std::endl;
	std::cout << "\033[35;1mSTD MAP SIZE TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::cout << std_thirdMap.size() <<"\033[0m" << std::endl;
	std::cout << "\033[32;1mFT MAP EMPTY TEST:\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << ft_thirdMap.empty() <<"\033[0m" << std::endl;
	std::cout << "\033[35;1mSTD MAP EMPTY TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::cout << std_thirdMap.empty() <<"\033[0m" << std::endl;
	std::cout << "\033[32;1mFT MAP MAX_SIZE TEST:\033[0m" << "\033[36;1m" <<std::endl;
	std::cout << ft_thirdMap.max_size() << "\033[0m" << std::endl;
	std::cout << "\033[35;1mSTD MAP MAX_SIZE TEST:\033[0m" << "\033[32;1m" <<std::endl;
	std::cout << std_thirdMap.max_size() <<"\033[0m" << std::endl;
	std::cout << "\033[32;1mFT MAP INSERT FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<std::string, double>   ft_Map4;

    ft_Map4.insert(ft::pair<std::string, double>("DoomGuy", 0));
    ft_Map4.insert(ft::pair<std::string, double>("lchantel", 6.02));
    ft::pair<ft::map<std::string, double>::iterator, bool>    retMap4;
    retMap4 = ft_Map4.insert(ft::pair<std::string, double>("lchantel", 7.53));
    if (retMap4.second==false) {
        std::cout << "element 'lchantel' already existed";
        std::cout << " with a value of " << retMap4.first->second << '\n';
    }
    // second insert function version (with hint position):
    ft::map<std::string, double>::iterator   itMap4_2 = ft_Map4.begin();
    ft_Map4.insert(itMap4_2, ft::pair<std::string, double>("sgertrud",9.26));  // max efficiency inserting
    ft_Map4.insert (itMap4_2, ft::pair<std::string, double>("klavada",6.27));
    ft_Map4.insert (itMap4_2, ft::pair<std::string, double>("Amalliar",5.07));
    ft_Map4.insert (itMap4_2, ft::pair<std::string, double>("Amalliar",5.07));
    ft::map<std::string, double>    ft_anothermap4;
    ft_anothermap4.insert(ft_Map4.begin(), ft_Map4.find("klavada"));

    // showing contents:
    std::cout << "ft_Map4 contains:\n";
    for (ft::map<std::string, double>::iterator itMap = ft_Map4.begin(); itMap != ft_Map4.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << std::endl;
    std::cout << "ft_anothermap4 contains:\n";
    for (ft::map<std::string, double>::iterator itMap = ft_anothermap4.begin(); itMap != ft_anothermap4.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << '\n';
    std::cout << "\033[0m";
    std::cout << "\033[35;1mSTD MAP INSERT FUNCTION TEST:\033[0m" << "\033[32;1m" <<std::endl;
    std::map<std::string, double>   std_Map4;

    std_Map4.insert(std::pair<std::string, double>("DoomGuy", 0));
    std_Map4.insert(std::pair<std::string, double>("lchantel", 6.02));
    std::pair<std::map<std::string, double>::iterator, bool>    retStdMap4;
    retStdMap4 = std_Map4.insert(std::pair<std::string, double>("lchantel", 7.53));
    if (retStdMap4.second==false) {
        std::cout << "element 'lchantel' already existed";
        std::cout << " with a value of " << retStdMap4.first->second << '\n';
    }
    // second insert function version (with hint position):
    std::map<std::string, double>::iterator   stdItMap4 = std_Map4.begin();
    std_Map4.insert(stdItMap4, std::pair<std::string, double>("sgertrud",9.26));  // max efficiency inserting
    std_Map4.insert (stdItMap4, std::pair<std::string, double>("klavada",6.27));
    std_Map4.insert (stdItMap4, std::pair<std::string, double>("Amalliar",5.07));
    std_Map4.insert (stdItMap4, std::pair<std::string, double>("Amalliar",5.07));
    std::map<std::string, double>    std_anothermap4;
    std_anothermap4.insert(std_Map4.begin(), std_Map4.find("klavada"));

    // showing contents:
    std::cout << "std_Map4 contains:\n";
    for (std::map<std::string, double>::iterator itMap = std_Map4.begin(); itMap != std_Map4.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << std::endl;
    std::cout << "std_anothermap4 contains:\n";
    for (std::map<std::string, double>::iterator itMap = std_anothermap4.begin(); itMap != std_anothermap4.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << '\n';
    std::cout << "\033[0m";
    std::cout << "\033[32;1mFT MAP ERASE FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<char, int>              ft_Map5;
    ft::map<char, int>::iterator    ftItMap5;

    ft_Map5['a']=10;
    ft_Map5['b']=20;
    ft_Map5['c']=30;
    ft_Map5['d']=40;
    ft_Map5['e']=50;
    ft_Map5['f']=60;

    ftItMap5 = ft_Map5.find('b');
    ft_Map5.erase(ftItMap5); // erase by iterator
    ft_Map5.erase('c'); //erase by key
    ftItMap5 = ft_Map5.find('e');
    ft_Map5.erase(ftItMap5, ft_Map5.end());
    for (ft::map<char, int>::iterator itMap = ft_Map5.begin(); itMap != ft_Map5.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << std::endl;
    std::cout << "\033[0m";
    std::cout << "\033[32;1mFT MAP SWAP FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<char, int> ft_MapFoo, ft_MapBar;

    ft_MapFoo['x']=100;
    ft_MapFoo['y']=200;

    ft_MapBar['a']=11;
    ft_MapBar['b']=22;
    ft_MapBar['c']=33;

    ft_MapFoo.swap(ft_MapBar);

    std::cout << "ft_MapFoo contains:\n";
    for (ft::map<char,int>::iterator itMap = ft_MapFoo.begin(); itMap != ft_MapFoo.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << '\n';

    std::cout << "ft_MapBar contains:\n";
    for (ft::map<char,int>::iterator itMap = ft_MapBar.begin(); itMap != ft_MapBar.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << '\n';
    std::cout << "\033[0m";
    std::cout << "\033[32;1mFT MAP CLEAR FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<char,int> ft_Map6;

    ft_Map6['x']=100;
    ft_Map6['y']=200;
    ft_Map6['z']=300;

    std::cout << "ft_Map6 contains:\n";
    for (ft::map<char,int>::iterator itMap=ft_Map6.begin(); itMap!=ft_Map6.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << '\n';

    ft_Map6.clear();
    ft_Map6['a']=1101;
    ft_Map6['b']=2202;

    std::cout << "ft_Map6 contains:\n";
    for (ft::map<char,int>::iterator itMap=ft_Map6.begin(); itMap!=ft_Map6.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << '\n';
    std::cout << "\033[0m";
    /*std::cout << "\033[32;1mFT MAP KEY_COMP FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<char,int> ft_Map7;

    ft::map<char,int>::key_compare ft_comp = ft_Map7.key_comp();

    ft_Map7['a']=100;
    ft_Map7['b']=200;
    ft_Map7['c']=300;

    std::cout << "ft_Map7 contains:\n";

    char highest = ft_Map7.rbegin()->first;     // key value of last element

    ft::map<char,int>::iterator itMap7 = ft_Map7.begin();
    do {
        std::cout << itMap7->first << " => " << itMap7->second << '\n';
    } while ( mycomp((*(itMap7++)).first, highest) );

    std::cout << '\n';
    std::cout << "\033[0m";*/
    std::cout << "\033[32;1mFT MAP COUNT FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<char,int> ft_Map9;
    char c;

    ft_Map9 ['a']=101;
    ft_Map9 ['c']=202;
    ft_Map9 ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (ft_Map9.count(c)>0)
            std::cout << " is an element of mymap.\n";
        else
            std::cout << " is not an element of mymap.\n";
    }
    std::cout << "\033[32;1mFT MAP LOWER_BOUND AND UPPER_BOUND FUNCTIONS TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<char,int> ft_Map10;
    ft::map<char,int>::iterator itlow,itup;

    ft_Map10['a']=20;
    ft_Map10['b']=40;
    ft_Map10['c']=60;
    ft_Map10['d']=80;
    ft_Map10['e']=100;

    itlow=ft_Map10.lower_bound ('b');  // itlow points to b
    itup=ft_Map10.upper_bound ('d');   // itup points to e (not d!)

    ft_Map10.erase(itlow,itup);        // erases [itlow,itup)


    for (ft::map<char,int>::iterator itMap = ft_Map10.begin(); itMap != ft_Map10.end(); ++itMap)
        std::cout << itMap->first << " => " << itMap->second << '\n';
    std::cout << "\033[0m";
    std::cout << "\033[32;1mFT MAP EQUAL_RANGE FUNCTION TEST:\033[0m" << "\033[36;1m" <<std::endl;
    ft::map<char,int> ft_Map11;

    ft_Map11['a'] = 10;
    ft_Map11['b'] = 20;
    ft_Map11['c'] = 30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = ft_Map11.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
    std::cout << "\033[0m";
    return (0);
}