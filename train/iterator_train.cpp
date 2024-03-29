#include <iostream>
#include <iterator>

class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
	int	*p;
public:
	MyIterator(int *x) : p(x) { }
	MyIterator(const MyIterator &mit) : p(mit.p) {}
	MyIterator	&operator++() {++p; return (*this); }
	MyIterator	operator++(int) {MyIterator tmp(*this); operator++(); return tmp; }
	MyIterator	&operator=(const MyIterator &rhs) { p = rhs.p; return (*this); }
	bool operator==(const MyIterator &rhs) const { return ( p == rhs.p ); }
	bool operator!=(const MyIterator &rhs) const { return ( p != rhs.p ); }
	int	&operator*() { return (*p); }
};

int main(void)
{
	int	numbers[] = {10, 20, 30, 40, 50};
	MyIterator from(numbers);
	MyIterator until(numbers + 5);
	for (MyIterator it = from;  it != until ; ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	return (0);
}