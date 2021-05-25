#include <iostream>

// Exceptions in destructors

struct Dungerous
{
	Dungerous(int x) : _x(x) { }
	int	getX() const {return (_x);}
	~Dungerous() {
		if (!_x)
			throw 1;
	}
private:
	int _x = 0;
};


void	f() {
	Dungerous s(0);
	std::cout << s.getX();
}

void	g() {
	Dungerous s(0);
	std::cout << s.getX();
	f();
	
}
