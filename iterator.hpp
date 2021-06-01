#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>
# include <iterator>

namespace ft
{
template <class T> class base_iterator {
	private:
		base_iterator( ) { }
	public:
		typedef	pointer		T*;
		typedef reference	T&;
		typedef distance	std::ptrdiff_t;
		typedef T			value_type;

		base_iterator(const base_iterator &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		base_iterator	&operator=(const base_iterator &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}
		virtual	base_iterator	&operator++() { ++_ptr; return (*this); }
		virtual base_iterator	operator++(int) { 
			base_iterator tmp = *this;
			operator++();
			return (tmp);
		}

		~base_iterator();
	protected:
		pointer				_ptr;
	};	


template <class T> class input_iterator : public base_iterator<T> {
		input_iterator( ) { }
	public:
		input_iterator(const input_iterator &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		input_iterator	&operator=(const input_iterator &rhs) {
			this->_ptr = rhs._ptr;
			return (*this);
		}

		bool	 		operator==(const input_iterator &rhs) { return (*this == rhs); }
		bool			operator!=(const input_iterator &rhs) { return (*this != rhs); }

		reference		operator*() const { return (*_ptr); }
		pointer			operator->() const { return (_ptr); }
	};

	template <class T> class output_iterator : public base_iterator<T> {
			output_iterator() { }
		public:
			output_iterator(const output_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			output_iterator	&operator*() { return (*this); }
			output_iterator	&operator=(const output_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			output_iterator	&operator++() { return (*this); }
			output_iterator	operator++(int) { return (*this); }
	};

	template <class T> class forward_iterator : virtual public input_iterator<T>,
		virtual public output_iterator<T> {
		public:
			forward_iterator( ) { }
			forward_iterator(const forward_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			forward_iterator	&operator=(const forward_iterator &rhs) {
				this->_ptr = rhs._ptr;
			}
			virtual forward_iterator	&operator++() { ++_ptr; return (*this); }
			virtual forward_iterator	operator++(int) {
				forward_iterator	tmp = *this;
				operator++();
				return (tmp);
			} 
		};

	template <class T> class bidirectional_iterator : public forward_iterator<T> {
		public:
			bidirectional_iterator( ) { }
			bidirectional_iterator(const bidirectional_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			bidirectional_iterator	&operator=(const bidirectional_iterator &rhs) {
				this->_ptr = rhs._ptr;
			}
			virtual bidirectional_iterator	&operator--() { --_ptr; return (*this); }
			virtual bidirectional_iterator	operator--(int) {
				bidirectional_iterator tmp = *this;
				operator--();
				return (tmp);
			}
	};

	template <class T> class random_access_iterator : public
		bidirectional_iterator<T> {
		random_access_iterator( ) { }
		random_access_iterator(const random_access_iterator &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		random_access_iterator	&operator=(const random_access_iterator &rhs) {
			this->_ptr = rhs._ptr;
			return (*this);
		}
		random_access_iterator	&operator+=(distance n) {
			distance m = n;
			if (m >= 0) {
				while (m--)
					++this;
			}
			else {
				while (++m)
					--this;
			}
			return (*this);
		}
		random_access_iterator	operator+(distance n) {
			random_access_iterator	tmp = this;
			return (tmp += n);
		}
		random_access_iterator	&operator-=(distance n)  { return (this += -n) }
		random_access_iterator	operator-(distance n) {
			random_access_iterator	tmp = this;
			return (tmp -= n);
		}
		random_access_iterator	operator[](distance n) { return (*(this + n)); }
	};
 }


#endif