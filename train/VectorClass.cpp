#include "VectorClass.hpp"

Vector::Vector() : _size(0),  _capacity(5),
	_array(new int[_capacity]) {
	// Nothing here...
}

Vector::Vector(const std::initializer_list<int> &list) :
	_size(0), _capacity(list.size() + 5),
	_array(new int[_capacity])
{
	for (int i : list) {
		push_back(i);
	}
}

Vector::~Vector() {
	delete [] _array;
}

void	Vector::push_back(int value)
{
	if (_size < _capacity)
		_array[_size++] = value;
	else
	{
		_capacity *= 2;
		int	*newArr = new int[_capacity];
		for (int i = 0; i < _size; ++i) {
			newArr[i] = _array[i];
		}
		newArr[_size++] = value;
		delete [] _array;
		_array = newArr;
	}
}

void	Vector::pop_back() {
	if (!_size) {
		const std::string	strErr("Pop back on empty vector");
		throw std::runtime_error(strErr.c_str());
	}
	--_size;
}

bool	Vector::empty() const
{
	return (!_size);
}
int		Vector::size() const
{
	return (_size);
}

int		Vector::capacity() const
{
	return (_capacity);
}

bool	Vector::operator==(const Vector &rhs) const {
	if (size() != rhs.size())
		return (false);
	for (int i = 0; i < size(); ++i) {
		if (_array[i] != rhs._array[i])
			return (false);
	}
	return (true);
}

bool	Vector::operator!=(const Vector &rhs) const {
	return (!(*this == rhs));
}

Vector::Vector(const Vector &rhs) : _size(rhs.size()),
	_capacity(rhs.capacity()), _array(new int(_capacity)) {
	for (int i = 0; i < size(); ++i) {
		_array[i] = rhs._array[i];
	}
}

Vector::Vector(int elements, int value) : _size(elements),
	_capacity(elements + 5), _array(new int[_capacity])
{
	for (int i = 0; i < _size; ++i) {
		_array[i] = value;
	}
}

int		&Vector::operator[](int idx) const {
	return (*(_array + idx));
}

std::ostream	&operator<<(std::ostream &o, Vector const &rhs) {
	for (int i = 0; i < rhs.size(); ++i)
		o << rhs[i] << ' ';
	o << "|| ";
	for (int i = rhs.size(); i < rhs.capacity(); ++i) {
		o << rhs[i] << ' ';
	}
	return (o);
}