#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# ifdef __amd64__
	typedef unsigned long	size_type;
# else
	typedef unsigned int	size_type;
# endif

namespace ft
{
	template<class T, class Alloc = std::allocator<T> > class vector
	{
	public:	
		explicit vector<T>( ) : _size(0), _capacity(0) { }	
		explicit vector<T>(size_type n, const T &val) : _size(n),
		_capacity(n) {
			_vector = _alloc.allocate(n);
			for (int i = 0; i < n; ++i)
				_alloc.contruct(val);
		};
		
		vector(const_iterator first, const_iterator last) {
			size_type	tmp;

			tmp = last - first;
			if (_size < tmp)
			{
				for (int i = _size - 1; i >= 0 ; --i)
					_alloc.destroy(_vector + i);
				_size = last - first;
			}
			if (_capacity < tmp)
			{
				alloc.deallocate(_capacity);
				_capacity = _size;
				_vector = _alloc.allocate(_size);
			}
			for (first; first != last; ++first) {
				alloc.contructor(_vector + i, *(first));
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
		
		class iterator {
			protected:
				T*	_ptr;
			public:
				T	&operator*() { return (*_ptr); }
				T	*operator->() { return (_ptr); }
				iterator( ) { }
				iterator(const iterator &rhs) {
					if (this != &rhs)
						*this = rhs;
				}
				virtual iterator	&operator++() { ++_ptr; return (*this); }
				iterator	&operator=(const iterator &rhs) {
					_ptr = rhs._ptr;
					return (*this);
				}
				virtual iterator	operator++(int) {
					iterator	tmp = *this;
					++(*this);
					return (tmp);
				}
				bool		operator==(const iterator &rhs) const {
					return (_ptr == rhs._ptr);
				}
				bool		operator!=(const iterator &rhs) const {
					return (_ptr != rhs._ptr);
				}
				virtual ~iterator( ) { }
		};

		class reverse_iterator : public iterator {
				reverse_iterator();
				reverse_iterator(const reverse_iterator &rhs) {
					if (this != &rhs)
						*this = rhs;
				}

				reverse_iterator	&operator=(const reverse_iterator &rhs) {
					this->_ptr = rhs._ptr;
					return (*this);
				}
				virtual	iterator	&operator++() {
					--this->_ptr;
					return (*this);
				}
				virtual iterator	operator++(int) {
					iterator	tmp = *this;
					--(*this);
					return (tmp);
				}
				virtual ~reverse_iterator( ) { }
		};

		typedef const iterator			const_iterator;
		typedef const reverse_iterator	const_reverse_iterator;

		iterator						begin() { return (_vector); }
		const_iterator					begin() const { return (_vector); }	
		iterator						end() { return (_vector + _size); }
		const_iterator					end() const { return (_vector + _size); }
		reverse_iterator				rbegin() { return (_vector + _size - 1); }
		const_reverse_iterator			rbegin() const {return (_vector + _size - 1); }
		reverse_iterator				rend() { return (_vector); }
		const_reverse_iterator			rend() const { return (_vector); }

		size_type						size() const { return (_size); }
		size_type						max_size() const { return (_alloc.max_size()); }
		void							resize(size_type n, T val = T()) {
			if (n < _size) {
				
			}
		}


		~vector( ) {
			for (int i = _size - 1; i >= 0 ; --i) {
				_alloc.destroy(_vector + i);
			}
			_alloc.deallocate(_size);
		};
	private:
		uint32_t			_capacity;
		size_type			_size;
		Alloc				_alloc;
		T					*_vector;
	};
}

#endif