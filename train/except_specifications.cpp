// Exceptin specifications and noexcept keyword


// noexcept since c++11
// noexcept tells us that some function doesn't
// throw any exception, noexcept is written after const keyword
// const after function declaration can be applied for only
// member functions, like classes or structures

#include <iostream>

struct S
{
	int f(int x, int y) {
		if (!y)
			throw 1;
		return (x / y);
	}
};

struct F
{
	int f(int x, int y) noexcept {
		return (x * y);
	}
};

// conditional noexception
/*
first noexcept is specificator, and can be conditional
The second noexcept is OPERATOR, that takes some 
condition (x.f(1, 0)) and returns "true" if condition
is "exception safe"

exception safe means that condition doesn't have anything
that can throw exceptions:
	throw
	new
	dynamic cast
	noexcept function
*/
template <typename T>
int		f(const T &x) noexcept(noexcept(x.f(1, 0))) {
	return (x.f(1, x));
}

int main(void)
{
	std::cout << noexcept(new int[5]) << std::endl;
}