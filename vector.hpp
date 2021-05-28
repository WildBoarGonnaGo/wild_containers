#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <stdexcept>
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
		class iterator {
		protected:
			T*	_ptr;
		public:
			T	&operator*() { return (*_ptr); }
			T	*operator->() { return (_ptr); }
			iterator() { }
			iterator(const iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			virtual iterator	&operator++() { ++_ptr; return (*this); }
			iterator	&operator=(const iterator &rhs) {
				_ptr = rhs._ptr;
				return (*this);
			}
			virtual iterator	operator++(int) const{
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
			reverse_iterator( ) { };
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
			virtual iterator	operator++(int) const {
				iterator	tmp = *this;
				--(*this);
				return (tmp);
			}
			virtual ~reverse_iterator( ) { }
		};
		
		typedef const iterator			const_iterator;
		typedef const reverse_iterator	const_reverse_iterator;
		
		explicit vector<T>(Alloc &alloc = Alloc()) : _size(0), _capacity(0),
			_alloc(alloc) { }
			
		explicit vector<T>(size_type n, const T &val = T(),
					 Alloc &alloc = Alloc()) : _size(n),
					_capacity(n), _alloc(alloc) {
			_vector = alloc.allocate(n);
			for (int i = 0; i < n; ++i)
				alloc.contruct(val);
		};
		
		vector(const_iterator first, const_iterator last,
		 	Alloc &alloc = Alloc()) {
			size_type	tmp;
			size_type	i = 0;
			
			tmp = last - first;
			if (_size < tmp && tmp < _capacity)
			{
				for (int i = _size - 1; i >= 0 ; --i)
				{
					alloc.destroy(_vector + i);
					alloc.constructor(_vector + i, *(first + i));
				}
				_size = last - first;
			}
			if (_capacity < tmp)
			{
				alloc.deallocate(_capacity);
				_capacity = tmp;
				_size = _capacity;
				_vector = alloc.allocate(tmp);
			}
			for (first; first != last; ++first) {
				alloc.contructor(_vector + i++, *(first));
			}
			_alloc = alloc;
		}
		
		vector(const vector &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		
		vector		&operator=(const vector &rhs) {
			for (int i = _capacity - 1; i >= 0 ; --i)
				_alloc.destroy(_vector + i);
			if (_capacity < rhs._capacity)
				_alloc.deallocate(_vector, _capacity);
			_capacity = rhs._capacity;
			_size = rhs._size;
			for (int i = 0; i < _size; ++i) {
				*(_vector + i) = *(rhs._vector + i);
			}
			return (*this);
		}
		
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
				for (int i = n; i < _size; ++i)
					_alloc.destroy(_vector + i);
				_size = n;
			}
			else if (n >= _size && n < _capacity)
			{
				for (int i = _size; i < n; ++i) {
					_alloc.constructor(_vector + i, val);
					_size += (val != T());
				}
			}
			else {
				T		*allocTmp = _alloc.allocate(n);
				int		idx;
				
				for (idx = 0; idx < _size; +idx)
					_alloc.constructor(allocTmp + idx, *(_vector + idx));
				for ( ; idx < n; ++idx)
					_alloc.constructor(allocTmp + idx, val);
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
					_alloc.contructor(allocTmp + i, *(_vector + i)); 
					_alloc.destroy(allocTmp + i);
				}
				_alloc.deallocate(_vector, _capacity);
				_capacity = n;
				_vector = allocTmp;
			}
		}

		vector							&operator[](size_type n) {
			return (*(_vector + n));
		}

		vector const					&operator[](size_type n) const {
			return (*(_vector + n));
		}

		vector							&at(size_type n) {
			if (n >= _size)
				throw std::out_of_range();
			return (_vector[n]);
		}

		vector const					&at(size_type n) const {
			if (n >= _size)
				throw std::out_of_range();
			return (_vector[n]);
		}
		
		vector							&front() {
			return (_vector[0]);
		}

		vector const					&front(size_type n) const {
			return (_vector[0]);
		}

		vector							&back() {
			return (_vector[_size - 1]);
		}

		vector const					&back(size_type n) const {
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
					_alloc.contructor(_vector + i, *(first++))
				}
				if (tempSize > _size)
					_size = tempSize;
			} else {
				allocTemp = _alloc.allocate(tempSize);
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				_alloc.deallocate(_vector, _capacity);
				for (size_t i = 0; i < tempSize; i++)
					_alloc.contructor(_vector + i, *(first++));
				_vector = allocTemp;
			}
		}

		void							assign(size_type n, const T &val) {
			T	*allocTemp;

			if (n < _capacity) {
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				for (size_t i = 0; i < n; i++)	
					_alloc.constructor(_vector + i, val);
				if (_size < n)
					_size = n;
			}
			else {
				allocTemp = _alloc.allocate(tempSize);
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_vector + i);
				_alloc.deallocate(_vector, _capacity);
				for (size_t i = 0; i < tempSize; i++)
					_alloc.contructor(_vector + i, val)
				_vector = allocTemp;
			}
		}

		void							push_back(const T &val) {
			T*			allocTemp;

			if (_size < _capacity)
				_alloc.contructor(_vector + _size++, val);
			else {
				_capacity = 2 * _size;
				allocTemp = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; i++) {
					_alloc.contructor(allocTemp + i, _vector[i])
					_alloc.destroy(_vector + i);
				}
				_alloc.deallocate(_vector, _capacity);
				_alloc.contructor(allocTemp + _size++, val);
				_vector = allocTemp;
			}
		}

		void							pop_back() {
			if (_size > 0) {
				alloc.destroy(_vector + _size - 1);
				--_size;
			}
				 
		}	

		iterator						insert(iterator position, const T &val) {
			if 
		}

		~vector( ) {
			for (int i = _size - 1; i >= 0 ; --i) {
				_alloc.destroy(_vector + i);
			}
			_alloc.deallocate(_size);
		};
	private:
		size_type			_capacity;
		size_type			_size;
		Alloc				_alloc;
		T					*_vector;
	};
}

#endif