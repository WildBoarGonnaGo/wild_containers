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
			iterator	&operator=(const iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			iterator	&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			reference	operator*() { return (*this->_ptr); }
			iterator	&operator+=(distance n) {
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
			iterator	operator+(distance n) {
				iterator	tmp = *this;
				return (tmp += n);
			}
			iterator	&operator-=(distance n) {
				return (*this += -n);
			}
			iterator	operator-(distance n) {
				iterator	tmp = *this;
				return (tmp -= n);
			}
			bool	operator<(iterator const &rhs) { return (this->_ptr < rhs._ptr); }
			bool	operator<=(iterator const &rhs) {
				return (*this == rhs || *this < rhs);
			}
			bool	operator>(iterator const &rhs) { return (this->_ptr > rhs._ptr); }
			bool	operator>=(iterator const &rhs) {
				return (*this == rhs || *this > rhs);
			}
			virtual ~iterator( ) { }
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
			reference					operator*() { return (*this->_ptr); }
			reverse_iterator			operator+(distance n) {
				reverse_iterator	tmp = *this;
				return (tmp -= n);
			}
			reverse_iterator			&operator-=(distance n) {
				return (*this += -n);
			}
			reverse_iterator			operator-(distance n) {
				reverse_iterator	tmp = *this;
				return (tmp -= n);
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
		};
		typedef const iterator			const_iterator;
		typedef const reverse_iterator	const_reverse_iterator;
		explicit vector(const Alloc &alloc = Alloc()) : _capacity(0), _size(0),
			_alloc(alloc) { }
		explicit vector(size_type n, const T &val = T(),
					 const Alloc &alloc = Alloc()) : _capacity(n),
					 _size(n), _alloc(alloc) {
			_vector = _alloc.allocate(n);
			for (size_type i = 0; i < n; ++i)
				_alloc.construct(_vector + i, val);
		};
		vector(iterator first, iterator last,
		 	const Alloc &alloc = Alloc()) : _alloc(alloc) {
			size_type	tmp = 0;
			size_type	i = 0;
			
			iterator	iterBackup = first;
			for (iterator it = first; it != last; ++it)
				++tmp;
			if (_size < tmp && tmp < _capacity)
			{
				for (size_type i = _size - 1; i >= 0 ; --i)
				{
					_alloc.destroy(_vector + i);
					_alloc.construct(_vector + i, *(first + i));
				}
				_size = tmp;
			}
			if (_capacity < tmp)
			{
				_alloc.deallocate(_vector, _capacity);
				_capacity = tmp;
				_size = _capacity;
				_vector = _alloc.allocate(_capacity);
			}
			i = 0;
			for ( ; iterBackup != last; ++iterBackup) {
				_alloc.construct(_vector + i++, *(iterBackup));
			}
		}
		vector(const vector &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		vector							&operator=(const vector &rhs) {
			if (_capacity) {
				for (size_type i = _capacity - 1; i >= 0 ; --i)
					_alloc.destroy(_vector + i);
			}
			if (_capacity < rhs._capacity && _capacity)
				_alloc.deallocate(_vector, _capacity);
			_capacity = rhs._capacity;
			_size = rhs._size;
			_vector = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; ++i) {
				//*(_vector + i) = *(rhs._vector + i);
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
			if (n > _capacity)
			{
				T*	allocTmp = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(allocTmp + i, *(_vector + i)); 
					_alloc.destroy(allocTmp + i);
				}
				_alloc.deallocate(_vector, _capacity);
				_capacity = n;
				_vector = allocTmp;
			}
		}
		T								&operator[](size_type n) {
			return (*(_vector + n));
		}
		const T							&operator[](size_type n) const {
			return (*(_vector + n));
		}
		vector							&at(size_type n) {
			if (n >= _size)
				throw std::out_of_range("vector::_M_range_check");
			return (_vector[n]);
		}
		vector const					&at(size_type n) const {
			if (n >= _size)
				throw std::out_of_range("vector::_M_range_check");
			return (_vector[n]);
		}
		vector							&front() {
			return (_vector[0]);
		}
		vector const					&front() const {
			return (_vector[0]);
		}
		vector							&back( ) {
			return (_vector[_size - 1]);
		}
		vector const					&back( ) const {
			return (_vector[_size - 1]);
		}
		void							assign(const_iterator first, const_iterator last) {
			size_type	tempSize;
			T*			allocTemp;

			tempSize = (static_cast<int>(last - first) < 0) ?
				first - last : last - first;
			if (tempSize <= _capacity) {
				for (size_t i = 0; i < tempSize; i++)
				{
					_alloc.destroy(_vector + i);
					_alloc.construct(_vector + i, *(first++));
				}
				if (tempSize > _size)
					_size = tempSize;
			} else {
				allocTemp = _alloc.allocate(tempSize);
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				_alloc.deallocate(_vector, _capacity);
				for (size_t i = 0; i < tempSize; i++)
					_alloc.construct(_vector + i, *(first++));
				_vector = allocTemp;
			}
		}
		void							assign(size_type n, const T &val) {
			T	*allocTemp;

			if (n < _capacity) {
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				for (size_t i = 0; i < n; i++)	
					_alloc.construct(_vector + i, val);
				if (_size < n)
					_size = n;
			}
			else {
				allocTemp = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				_alloc.deallocate(_vector, _capacity);
				for (size_t i = 0; i < n; i++)
					_alloc.construct(_vector + i, val);
				_vector = allocTemp;
			}
		}
		void							push_back(const T &val) {
			T*			allocTemp;
			size_type	tmp = _capacity;
 
			if (_capacity && _size < _capacity)
				_alloc.construct(_vector + _size++, val);
			else {
				_capacity = (!_capacity) ? 1 : 2 * _size;
				allocTemp = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; i++) {
					_alloc.construct(allocTemp + i, _vector[i]);
					_alloc.destroy(_vector + i);
				}
				if (tmp)
					_alloc.deallocate(_vector, _capacity);
				_alloc.construct(allocTemp + _size++, val);
				_vector = allocTemp;
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
						allocTmp = _alloc.allocate(++_capacity);
						for (int j = 0; j < pos; ++j)
							_alloc.construct(allocTmp + j, _vector[j]);
						_alloc.construct(allocTmp + pos, val);
						for (int j = pos + 1; j < _size - 1; ++j)
							_alloc.construct(allocTmp + j, _vector[j + 1]);
						for (int j = 0; j < _size; ++j)
							_alloc.destroy(_vector + j);
						_alloc.deallocate(_vector, _capacity - 1);
						_vector = allocTmp;
						position = _vector + pos;
						++_size;
						return (position);
					}
				}
			}
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
						allocTmp = _alloc.allocate(_capacity + n);
						for (size_type j = 0; j < pos; ++j)
							_alloc.construct(allocTmp + j, _vector[j]);
						for (size_type j =  pos; j < pos + n; ++j)
							_alloc.construct(allocTmp + j, val);
						for (size_type j = pos + n; j < _size - 1; ++j)
							_alloc.construct(allocTmp + j, _vector[j + 1]);
						for (size_type j = 0; j < _size; ++j)
							_alloc.destroy(_vector + j);
						_alloc.deallocate(_vector, _capacity);
						_vector = allocTmp;
						position = _vector + pos;
						_size += n;
						_capacity += n;
						return (position);
					}
				}
			}
		}
		iterator						insert(iterator position, const_iterator first,
					   						const_iterator last) {
			int				len = (last > first) ? last - first : first - last;
			size_type		pos;
			const_iterator	roll = (last > first) ? first : last;
			T				*allocTmp;
			
			if (_size + len < _capacity) {
				for (size_type i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						for (size_type j = position - _vector + len; j < _size - 1; ++j)
							_vector[j] = _vector[j + 1];
						for (size_type j = position - _vector; j < position - _vector + len; ++j)
							_vector[j] = *(roll++);
						_size += len;
						return (position);
					}
				}
			} else {
				for (int i = 0; i < _size; ++i) {
					if (position == _vector + i) {
						pos = position - _vector;
						allocTmp = _alloc.allocate(_capacity + len);
						for (size_type j = 0; j < pos; ++j)
							_alloc.construct(allocTmp + j, _vector[j]);
						for (size_type j =  pos; j < pos + len; ++j)
							_alloc.construct(allocTmp + j, *(first++));
						for (size_type j = pos + len; j < _size - 1; ++j)
							_alloc.construct(allocTmp + j, _vector[j + 1]);
						for (size_type j = 0; j < _size; ++j)
							_alloc.destroy(_vector + j);
						_alloc.deallocate(_vector, _capacity);
						_vector = allocTmp;
						position = _vector + pos;
						_size += len;
						_capacity += len;
						return (position);
					}
				}
			}
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
			iterator	roll;
			iterator	end;
			
			for (int i = 0; i < _size; ++i) {
				if (first == _vector + i || last == _vector + i
					|| last > this->end() || first > this->end())
					++state;
				if (state == 2) {
					roll = (first < last) ? first : last;
					end = (first < last) ? last : first;
					if (end > this->end())
						end = this->end();
					for ( ; roll != end ; ++roll)
						_alloc.destroy(roll);
					_size -= end - roll;
					roll = (first < last) ? first : last;
					for (int j = 0; j < _size && end != this->end(); ++j)
						*(roll + j) = *(end + j);
					if (end == this->end())
						return (end);
					return (roll);
				}
			}
			return (this->end());
		}
		void                            swap(vector<T> &prey) {
		    vector  *tmp = &prey;
            vector  *tmp2 = this;

		    if (this != &prey) {
		        this = &prey;
                tmp = tmp2;
		    }
		}
        void                            clear() {
            for (int i = 0; i < _size; ++i)
                _alloc.destroy(_vector + i);
            _size = 0;
		}
		Alloc                           get_allocator() const { return (_alloc); }
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
			if (lhs.size() == rhs.size())
				return (false);
			for (int i = 0; i < rhs.size(); ++i) {
				if (lhs._vector[i] == rhs._vector[i])
					return (false);
			}
			return (true);
		}
		friend bool						operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			size_type 	tmpSize;
			
			tmpSize = (lhs < rhs) ? lhs : rhs;
			if (lhs == rhs)
				return (false);
			for (size_type i = 0; i < tmpSize; ++i) {
				if (lhs._vector[i] > rhs._vector[i])
					return (false);
			}
			return (true);
		}
		friend bool 					operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return ((lhs == rhs) || (lhs < rhs));
		}
		friend bool						operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			size_type 	tmpSize;
			
			tmpSize = (lhs > rhs) ? lhs : rhs;
			if (lhs == rhs)
				return (false);
			for (size_type i = 0; i < tmpSize; ++i) {
				if (lhs._vector[i] < rhs._vector[i])
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