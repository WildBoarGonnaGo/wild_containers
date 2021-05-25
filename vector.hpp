#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <iterator>

namespace ft
{
	template<class T>
	class vector
	{
	public:
		typedef T*			iterator;
		typedef T*			reverse_iterator;
		explicit vector<T>( ) { _vector = _alloc.allocate(0); }
		
		explicit vector<T>(uint32_t n, const T &val) : _size(n) {
			_vector = _alloc.allocate(n);
			for (int i = 0; i < n; ++i)
				_vector[i] = val;
		};
		
		vector(iterator first, iterator last) {
			for (int i = _size - 1; i >= 0 ; --i) {
				_alloc.destroy(_vector + i);
			}
			_alloc.deallocate(_size);
			_size = last - first + 1;
			_vector = _alloc.allocate(_size);
			for (int i = 0; i < _size; ++i) {
				*(_vector + i) = first++;
			}
		}
		vector(const vector &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		
		vector		&operator=(const vector &rhs) {
			for (int i = _size - 1; i >= 0 ; --i) {
				_alloc.destroy(_vector + i);
			}
			_alloc.deallocate(_size);
			_size = rhs._size;
			for (int i = 0; i < _size; ++i) {
				*(_vector + i) = *(rhs._vector + i);
			}
			return (*this);
		}
		
		/*iterator			begin() const { return (_vector); }
		iterator			end() const	{ return (_vector + _size - 1); }
		reverse_iterator 	rbegin() const { return (_vector + _size - 1); }
		reverse_iterator 	rend() const { return (_vector); }
		
		reverse_iterator 	&operator++() {
			--_vector;
			return (*this);
		}
		reverse_iterator 	operator++() {
		
		}
		iterator			operator++() { return (++_vector); }*/
		~vector( ) {
			for (int i = _size - 1; i >= 0 ; --i) {
				_alloc.destroy(_vector + i);
			}
			_alloc.deallocate(_size);
		};
	private:
		int					_size;
		std::allocator<T>	_alloc;
		T					*_vector;
	};
}

#endif