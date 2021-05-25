#include <iostream>
#include <vector>

// Exceptions in destructors
// NEVER THROW EXCEPTIONS IN DESTRUCTOR
// since c++11 all destructors have 'noexcept' keyword
// IF you want except destructor be workable just
// write 'noexcept(false)' after Destructor name

struct Dangerous
{
	Dangerous(int x) : _x(x) { }
	int	getX() const {return (_x);}
	~Dangerous() noexcept(false) {
		if (_x == 8)
			throw 1;
	}
private:
	int _x = 0;
};

struct S {
	int _x = 0;
	S(int x) : _x(x) { }
	S(const S& s) : _x(s.x) {
		if (!x)
			throw 1;
	}
};

void	f() {
	Dangerous s(0);
	std::cout << s.getX();
}

void	g() {
	Dangerous s(0);
	std::cout << s.getX();
	f();
	
}

int main(void)
{
	std::vector<S>	v;
	try {
		g();
	} catch (...) {
		std::cout << "caught\n";
	}
}