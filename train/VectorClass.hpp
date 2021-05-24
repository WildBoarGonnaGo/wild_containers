#pragma once
# include <iostream>
# include <initializer_list>
# include <stdexcept>

class Vector
{
public:
	Vector();
	Vector(const Vector &rhs);
	Vector(int elements, int value = 0);
	Vector(const std::initializer_list<int> &list);
	~Vector();
	
	void	push_back(int value);
	void	pop_back();
	bool	empty() const;
	int		size() const;
	int		capacity() const;
	
	bool	operator==(const Vector &rhs) const;
	bool	operator!=(const Vector &rhs) const;
	int		&operator[](int idx) const;
private:
	int	_size;
	int	_capacity;
	int	*_array;
};

std::ostream	&operator<<(std::ostream &o, Vector const &rhs);