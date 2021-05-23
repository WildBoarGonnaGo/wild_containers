#include <memory>
#include <iostream>
#include <string>

int main(void)
{
    //default allocator for ints
	std::allocator<std::string>	alloc;
	
	std::string *str = alloc.allocate(2);
	str[0] = "foo";
	str[1] = "bar";
	for (int i = 0; i < 2; ++i) {
		std::cout << str[i] << std::endl;
	}
	
	std::cout << "size of str allocator: " << str + 1 - str << std::endl;
	alloc.deallocate(str, 2);
	alloc.destroy(str + 1);
	alloc.destroy(str);
	return (0);
}