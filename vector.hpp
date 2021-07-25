#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <stdexcept>
# include "iterator.hpp"
# ifdef __amd64__
	typedef unsigned long	size_type;
# else
	typedef unsigned int	size_type;
# endif

namespace ft
{
	template<class T, class Alloc = std::allocator<T> > class vector {
	public:
		class iterator : public forward_iterator<T> {
		private:
			iterator	&operator--() { --this->_ptr; return (*this); }
			iterator	operator--(int) {
				iterator tmp = *this;
				operator--();
				return (tmp);
			}
		public:
			typedef	typename base_iterator<T>::reference	reference;
			typedef typename base_iterator<T>::distance		distance;
			typedef typename base_iterator<T>::pointer		pointer;

			iterator() { }
			iterator(const iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			iterator		&operator=(const iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			iterator		&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			reference		operator*() { return (*this->_ptr); }
			//const reference	operator*() const { return (*this->_ptr); }
			iterator		&operator+=(distance n) {
				distance m = n;
				if (m >= 0) {
					while (m--)
						++*this;
				}
				else {
					while (++m)
						--*this;
				}
				return (*this);
			}
			//iterator        operator+(const pointer rhs) { return ()}
			pointer        &operator+=(const pointer &rhs) {
				while (this->_ptr != rhs)
					++this->_ptr;
				return (this->_ptr);
			}
			distance       operator+(const pointer &rhs) {
				size_type tmp = this->_ptr + rhs;
				return (tmp);
			}
			iterator		operator+(distance const &n) {
				iterator	tmp = *this;
				return (tmp += n);
			}
			pointer        &operator-=(pointer const &rhs) {
				while (this->_ptr != rhs)
					--this->_ptr;
				return (this->_ptr);
			}
			iterator		&operator-=(distance const &n) {
				return (*this += -n);
			}
			iterator		operator-(distance const &n) {
				iterator	tmp = *this;
				return (tmp -= n);
			}
			distance        operator-(const pointer rhs) {
				size_type tmp = this->_ptr - rhs;
				return (tmp);
			}
			bool			operator<(iterator const &rhs) { return (this->_ptr < rhs._ptr); }
			bool	        operator<=(iterator const &rhs) {
				return (*this == rhs || *this < rhs);
			}
			bool			operator>(iterator const &rhs) { return (this->_ptr > rhs._ptr); }
			bool			operator>=(iterator const &rhs) {
				return (*this == rhs || *this > rhs);
			}
			bool            operator==(pointer const rhs) { return this->_ptr == rhs; }
			virtual ~iterator( ) { }
		//protected:
			pointer const 			&getPtr() const { return (this->_ptr); }
		};
		class reverse_iterator : public forward_iterator<T> {
		private:
			reverse_iterator	&operator--() { ++this->_ptr; return (*this); }
			reverse_iterator	operator--(int) {
				reverse_iterator tmp = *this;
				operator--();
				return (tmp);
			}
		public:
			reverse_iterator( ) { }
			typedef	typename base_iterator<T>::reference	reference;
			typedef typename base_iterator<T>::pointer		pointer;
			typedef typename base_iterator<T>::distance		distance;

			reverse_iterator(const reverse_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			reverse_iterator			&operator=(const reverse_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			reverse_iterator			&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			pointer        &operator+=(const pointer &rhs) {
				while (this->_ptr != rhs)
					--this->_ptr;
				return (this->_ptr);
			}
			distance       operator+(const pointer &rhs) {
				size_type tmp = this->_ptr - rhs;
				return (tmp);
			}
			reference					operator*() { return (*this->_ptr); }
			//const reference				operator*() const { return (*this->_ptr); }
			reverse_iterator			operator+(distance n) {
				reverse_iterator	tmp = *this;
				return (tmp -= n);
			}
			reverse_iterator			&operator-=(distance n) {
				return (*this += -n);
			}
			pointer        &operator-=(pointer const &rhs) {
				while (this->_ptr != rhs)
					++this->_ptr;
				return (this->_ptr);
			}
			reverse_iterator			operator-(distance n) {
				reverse_iterator	tmp = *this;
				return (tmp -= n);
			}
			distance        operator-(const pointer rhs) {
				size_type tmp = this->_ptr + rhs;
				return (tmp);
			}
			bool						operator<(reverse_iterator const &rhs) { return (this->_ptr < rhs._ptr); }
			bool						operator<=(reverse_iterator const &rhs) {
				return (*this == rhs || *this < rhs);
			}
			bool						operator>(reverse_iterator const &rhs) { return (this->_ptr > rhs._ptr); }
			bool						operator>=(reverse_iterator const &rhs) {
				return (*this == rhs || *this > rhs);
			}
			virtual	base_iterator<T>	&operator++() {
				--this->_ptr;
				return (*this);
			}
			virtual base_iterator<T>	operator++(int) {
				reverse_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			virtual ~reverse_iterator( ) { }
		//protected:
			pointer const 			&getPtr() const { return (this->_ptr); }
		};
		class const_iterator : public iterator {
		public:
			typedef	typename base_iterator<T>::reference	reference;
			typedef typename base_iterator<T>::pointer		pointer;
			typedef typename base_iterator<T>::distance		distance;
			const_iterator() { }
			const_iterator(const const_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_iterator(const iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_iterator			&operator=(const const_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			const_iterator	&operator=(const iterator &rhs) {
				this->_ptr = rhs.getPtr() ;
				return (*this);
			}
		};
		class const_reverse_iterator : public reverse_iterator {
		public:
			typedef	typename base_iterator<T>::reference	reference;
			typedef typename base_iterator<T>::pointer		pointer;
			typedef typename base_iterator<T>::distance		distance;
			const_reverse_iterator() { }
			const_reverse_iterator(const const_reverse_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_reverse_iterator(const reverse_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_reverse_iterator		&operator=(const const_reverse_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			const_reverse_iterator		&operator=(const reverse_iterator &rhs) {
				this->_ptr = rhs.getPtr();
				return (*this);
			}
			const_reverse_iterator		&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			reference				operator*() { return (*this->_ptr); }
			const reference			operator*() const { return (*this->_ptr); }
		};
		explicit vector(const Alloc &alloc = Alloc()) : _capacity(0), _size(0),
			_alloc(alloc), _vector(0x0) { }
		explicit vector(size_type n, const T &val = T(),
					 const Alloc &alloc = Alloc()) : _capacity(n),
					 _size(n), _alloc(alloc), _vector(0x0) {
			_vector = _alloc.allocate(n);
			for (size_type i = 0; i < n; ++i)
				_alloc.construct(_vector + i, val);
		};
		vector(iterator first, iterator last,
		 	const Alloc &alloc = Alloc()) : _alloc(alloc), _vector(NULL),
		 	_capacity(0), _size(0) {
			size_type	tmp = 0;
			size_type	i = 0;
			
			iterator	iterBackup = first;
			for (iterator it = first; it != last; ++it)
				++tmp;
			_size = tmp;
			reserve(tmp);
			for ( ; iterBackup != last; ++iterBackup) {
				_alloc.construct(_vector + i++, *(iterBackup));
			}
		}
		vector(const vector &rhs, const Alloc &alloc = Alloc()) :
			_vector(0x0), _size(0), _alloc(alloc), _capacity(0) {
			if (this != &rhs)
				*this = rhs;
		}
		vector							&operator=(const vector &rhs) {
			if (_capacity) {
				for (int i = _capacity - 1; i >= 0 ; --i)
					_alloc.destroy(_vector + i);
			}
			if (_capacity < rhs._capacity && _capacity)
				_alloc.deallocate(_vector, _capacity);
			_capacity = rhs._capacity;
			_size = rhs._size;
			_vector = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; ++i) {
				_alloc.construct(_vector + i, rhs[i]);
			}
			return (*this);
		}
		iterator						begin() { iterator val; val = _vector; return (val); }
		const_iterator					begin() const { const_iterator val = _vector; return (val); }
		iterator						end() { iterator val; val = _vector + _size; return (val); }
		const_iterator					end() const { const_iterator val = _vector + _size; return (val); }
		reverse_iterator				rbegin() {
			reverse_iterator val;
			val = _vector + _size - 1; 
			return (val); 
			}
		const_reverse_iterator			rbegin() const {const_reverse_iterator val = _vector + _size - 1; return (val); }
		reverse_iterator				rend() { reverse_iterator val; val = _vector - 1; return (val); }
		const_reverse_iterator			rend() const { const_reverse_iterator val = _vector - 1; return (val); }

		size_type						size() const { return (_size); }
		size_type						max_size() const { return (_alloc.max_size()); }
		void							resize(size_type n, T val = T()) {
			if (n < _size) {
				for (size_type i = n; i < _size; ++i)
					_alloc.destroy(_vector + i);
				_size = n;
			}
			else if (n >= _size && n < _capacity)
			{
				for (size_type i = _size; i < n; ++i) {
					_alloc.construct(_vector + i, val);
					++_size;
				}
			}
			else {
				size_type	idx = 0;
				T			*allocTmp = _alloc.allocate(n);
				
				for (idx = 0; idx < _size; ++idx)
					_alloc.construct(allocTmp + idx, *(_vector + idx));
				for ( ; idx < n; ++idx)
					_alloc.construct(allocTmp + idx, val);
				for (idx = 0; idx < _size; ++idx)
					_alloc.destroy(_vector + idx);
				_alloc.deallocate(_vector, _capacity);
				_capacity = n;
				_vector = allocTmp;
			}
		}
		size_type						capacity() const { return (_capacity); }
		bool							empty() const { return (_size == 0); }
		void							reserve(size_type n) {
			size_type oldCapacity = _capacity;
			size_type upCapacity =  0;
			if (n > _capacity)
			{
				while (n > upCapacity)
					upCapacity =  upCapacity * 2 + (!upCapacity);
				_capacity = upCapacity;
				if (!_vector) {
					_vector = _alloc.allocate(_capacity);
				} else {
					T*	allocTmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(allocTmp + i, *(_vector + i));
						_alloc.destroy(_vector + i);
					}
					_alloc.deallocate(_vector, oldCapacity);
					_vector = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; ++i) {
						_alloc.construct(_vector + i, *(allocTmp + i));
						_alloc.destroy(allocTmp + i);
					}
					_alloc.deallocate(allocTmp, _capacity);
				}
			}
		}
		T								&operator[](size_type n) {
			return (*(_vector + n));
		}
		const T							&operator[](size_type n) const {
			return (*(_vector + n));
		}
		T								&at(size_type n) {
			if (n >= _size)
				throw std::out_of_range("vector::_M_range_check");
			return (_vector[n]);
		}
		T const							&at(size_type n) const {
			if (n >= _size)
				throw std::out_of_range("vector::_M_range_check");
			return (_vector[n]);
		}
		T								&front() {
			return (_vector[0]);
		}
		T const							&front() const {
			return (_vector[0]);
		}
		T								&back( ) {
			return (_vector[_size - 1]);
		}
		T const							&back( ) const {
			return (_vector[_size - 1]);
		}
		void							assign(iterator first, iterator last) {
			size_type	    tempSize = 0;
			T*			    allocTemp;
			iterator        frstIterator = first;

			for ( ; first != last; ++first)
				++tempSize;
			if (tempSize <= _capacity) {
				size_type i = 0;
				for ( ; frstIterator != last; ++frstIterator)
				{
					_alloc.destroy(_vector + i);
					_alloc.construct(_vector + i++, *frstIterator);
				}
				if (tempSize - 1 > _size)
					_size = tempSize - 1;
			} else {
				reserve(tempSize - 1);
				_size = tempSize - 1;
				size_type i = 0;
				for ( ; frstIterator != last && i < tempSize; ++frstIterator)
					_alloc.construct(_vector + i++, *frstIterator);
			}
		}
		void							assign(size_type n, const T &val) {
			T	*allocTemp;

			if (n < _capacity) {
				size_t  destroySize = (_size < n) ? _size : n;
				for (size_t i = 0; i < destroySize; i++)
					_alloc.destroy(_vector + i);
				for (size_t i = 0; i < n; i++)	
					_alloc.construct(_vector + i, val);
				if (_size < n)
					_size = n;
			}
			else {
				reserve(n);
				_size = n;
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(_vector + i, val);
			}
		}
		void							push_back(const T &val) {
			size_type	tmp = _capacity;
 
			if (_capacity && _size < _capacity)
				_alloc.construct(_vector + _size++, val);
			else {
				reserve(_size + 1);
				_alloc.construct(_vector + _size++, val);
			}
		}
		void							pop_back() {
			if (_size > 0) {
				_alloc.destroy(_vector + _size - 1);
				--_size;
			}
				 
		}
		iterator						insert(iterator position, const T &val) {
			T*	allocTmp;
			int	pos;
			
			if (_size < _capacity) {
				for (int i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						for (int j = position - _vector + 1; j < _size - 1; ++j)
							_vector[j] = _vector[j + 1];
						++_size;
						return (position);
					}
				}
			} else {
				for (int i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						pos = position - _vector;
						reserve(_size + 1);
						allocTmp = _alloc.allocate(_capacity);
						for (int j = 0; j < pos; ++j)
							_alloc.construct(allocTmp + j, _vector[j]);
						_alloc.construct(allocTmp + pos, val);
						++_size;
						for (int j = pos + 1; j < _size; ++j)
							_alloc.construct(allocTmp + j, _vector[j - 1]);
						for (int j = 0; j < _size - 1; ++j)
							_alloc.destroy(_vector + j);
						_alloc.deallocate(_vector, _capacity);
						_vector = allocTmp;
						position = _vector + pos;
						//return (position);
					}
				}
			}
			return (position);
		}
		iterator						insert(iterator position, size_type n, const T &val) {
			T*			allocTmp;
			size_type	pos;
			
			if (_size + n < _capacity) {
				for (size_type i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						for (size_type j = position - _vector + n; j < _size - 1; ++j)
							_vector[j] = _vector[j + 1];
						for (size_type j = position - _vector; j < position - _vector + n; ++j)
							_vector[j] = val;
						_size += n;
						return (position);
					}
				}
			} else {
				for (int i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						pos = position - _vector;
						reserve(_size + n);
						allocTmp = _alloc.allocate(_capacity);
						for (size_type j = 0; j < pos; ++j)
							_alloc.construct(allocTmp + j, _vector[j]);
						for (size_type j =  pos; j < pos + n; ++j)
							_alloc.construct(allocTmp + j, val);
						_size += n;
						for (size_type j = pos + n; j < _size; ++j)
							_alloc.construct(allocTmp + j, _vector[j - n]);
						for (size_type j = 0; j < _size - n; ++j)
							_alloc.destroy(_vector + j);
						_alloc.deallocate(_vector, _capacity);
						_vector = allocTmp;
						position = _vector + pos;
						return (position);
					}
				}
			}
			return (position);
		}
		iterator						insert(iterator position, iterator first,
					   						iterator last) {
			size_type		len = 0;
			size_type		pos;
			T				*allocTmp;
			iterator        tempFirst = first;

			for ( ; first != last; ++first)
				++len;
			if (_size + len < _capacity) {
				for (size_type i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						for (size_type j = position - _vector + len; j < _size - 1; ++j)
							_vector[j] = _vector[j + 1];
						for (size_type j = position - _vector; j < position - _vector + len; ++j) {
							_vector[j] = *tempFirst;
							++tempFirst;
						}
						_size += len;
						return (position);
					}
				}
			} else {
				for (int i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						pos = position - _vector;
						reserve(_size + len);
						allocTmp = _alloc.allocate(_capacity);
						for (size_type j = 0; j < pos; ++j)
							_alloc.construct(allocTmp + j, _vector[j]);
						for (size_type j =  pos; j < pos + len; ++j) {
							_alloc.construct(allocTmp + j, *tempFirst);
							++tempFirst;
						}
						_size += len;
						for (size_type j = pos + len; j < _size; ++j)
							_alloc.construct(allocTmp + j, _vector[j - len]);
						for (size_type j = 0; j < _size - len; ++j)
							_alloc.destroy(_vector + j);
						_alloc.deallocate(_vector, _capacity);
						_vector = allocTmp;
						position = _vector + pos;
						return (position);
					}
				}
			}
			return (position);
		}
		iterator						erase(iterator position) {
			for (int i = 0; i < _size; ++i) {
				if (position == _vector + i) {
					_alloc.destroy(_vector + i);
					for (int j = i; j < _size - 1; ++j)
						_vector[j] = _vector[j + 1];
					_vector[_size-- - 1] = T();
					return (position);
				}
			}
			return (this->end());
		}
		iterator						erase(iterator first, iterator last) {
			int 		state = 0;
			size_type   start;
			size_type   end;
			
			for (int i = 0; i < _size; ++i) {
				if (first == _vector + i) {
					size_type   diff;
					start = first - _vector;
					end = last - _vector;

					diff = end - start;
					for (int j = start; j < end && j + diff < _size; ++j) {
						_alloc.destroy(_vector + j);
						_vector[j] = _vector[j + diff];
					}
					for (int j = end; j + diff < _size; ++j)
						_vector[j] = _vector[j + diff];
					for (int j = _size - diff; j < _size; ++j)
						_alloc.destroy(_vector + j);
					_size -= diff;
				}
			}
			return (this->end());
		}
		void                            swap(vector<T> &prey) {
		    T*          tmp = _alloc.allocate(_size);
			size_type   tmpSize = _size;

		    if (this != &prey) {
			    for (int i = 0; i < _size; ++i)
				    _alloc.construct(tmp + i, *(_vector + i));
		        *this = prey;
		        prey.clear();
			    for (size_type i = 0; i < tmpSize; ++i) {
				    prey.push_back(*(tmp + i));
				    _alloc.destroy(tmp + i);
			    }
		    }
		    _alloc.deallocate(tmp, tmpSize);
		}
        void                            clear() {
            for (int i = 0; i < _size; ++i)
                _alloc.destroy(_vector + i);
            _size = 0;
		}
		Alloc                           &get_allocator() const { return (_alloc); }
        friend bool						operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			for (int i = 0; i < rhs.size(); ++i) {
				if (lhs._vector[i] != rhs._vector[i])
					return (false);
			}
			return (true);
		}
		friend bool						operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (!(lhs == rhs));
		}
		friend bool						operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			size_type 	tmpSize;
			
			tmpSize = (lhs._size < rhs._size) ? lhs._size : rhs._size;
			if (lhs == rhs)
				return (false);
			for (size_type i = 0; i < tmpSize; ++i) {
				if (lhs._vector[i] == rhs._vector[i])
					continue ;
				else if (lhs._vector[i] < rhs._vector[i])
					return (true);
				else
					return (false);
			}
			return (false);
		}
		friend bool 					operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return ((lhs == rhs) || (lhs < rhs));
		}
		friend bool						operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			size_type 	tmpSize;
			
			tmpSize = (lhs._size > rhs._size) ? lhs._size : rhs._size;
			if (lhs == rhs)
				return (false);
			for (size_type i = 0; i < tmpSize; ++i) {
				if (lhs._vector[i] == rhs._vector[i])
					continue ;
				else if (lhs._vector[i] > rhs._vector[i])
					return (true);
				else
					return (false);
			}
			return (true);
		}
		friend bool 					operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return ((lhs == rhs) || (lhs > rhs));
		}
		friend void						swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
			vector<T, Alloc> *xPtr = &x;
			vector<T, Alloc> *yPtr = &y;
			vector<T, Alloc> *buff = &x;
			
			xPtr = yPtr;
			yPtr = buff;
		}
		~vector( ) {
			for (size_type i = 0; i < _size; ++i)
				_alloc.destroy(_vector + i);
			if (_capacity)
				_alloc.deallocate(_vector, _capacity);
		};
	private:
		size_type			_capacity;
		size_type			_size;
		Alloc				_alloc;
		T					*_vector;
	};
	
}

#endif