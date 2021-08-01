#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>
# include <iterator>

namespace ft
{
template <class T> class base_iterator {
	public:
		typedef	T*				pointer;
		typedef T&				reference;
		typedef std::ptrdiff_t	distance;
		typedef T				value_type;

		base_iterator() { }
		base_iterator(const base_iterator &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		base_iterator			&operator=(const base_iterator &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}
		virtual	base_iterator	&operator++() { ++_ptr; return (*this); }
		virtual base_iterator	operator++(int) {
			base_iterator tmp = *this;
			operator++();
			return (tmp);
		}

		virtual ~base_iterator( ) { };
	protected:
		pointer				_ptr;
	};	


template <class T> class input_iterator : virtual public base_iterator<T> {
	protected:
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

		bool	 								operator==(const input_iterator &rhs) { return (this->_ptr == rhs._ptr); }
		bool									operator!=(const input_iterator &rhs) { return !(*this == rhs); }
		typename base_iterator<T>::reference	operator*() const { return (*this->_ptr); }
		typename base_iterator<T>::pointer		operator->() const { return (this->_ptr); }
		virtual 		~input_iterator( ) { }
	};

	template <class T> class output_iterator : virtual public base_iterator<T> {
		protected:
			output_iterator() { }
		public:
			output_iterator(const output_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			output_iterator				&operator*() { return (*this); }
			const output_iterator		&operator*() const { return (*this); }
			output_iterator				&operator=(const output_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			virtual base_iterator<T> 	&operator++() { return (*this); }
			virtual base_iterator<T>	operator++(int) { return (*this); }
			virtual						~output_iterator( ) { }
	};

	template <class T> class forward_iterator : public input_iterator<T>,
		public output_iterator<T> {
		public:
			forward_iterator( ) { }
			forward_iterator(const forward_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			forward_iterator	&operator=(const forward_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			virtual	base_iterator<T>		&operator++() { ++this->_ptr; return (*this); }
			virtual base_iterator<T>		operator++(int) {
				forward_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			virtual 					~forward_iterator( ) { }
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
				return (*this);
			}
			virtual bidirectional_iterator	&operator--() { --this->_ptr; return (*this); }
			virtual bidirectional_iterator	operator--(int) {
				bidirectional_iterator tmp = *this;
				operator--();
				return (tmp);
			}
			virtual							~bidirectional_iterator( ) { }
	};

	template <class T> class random_access_iterator : public
		bidirectional_iterator<T> {
		typedef typename base_iterator<T>::distance	distance;
		
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
					++*this;
			}
			else {
				while (++m)
					--*this;
			}
			return (*this);
		}
		random_access_iterator	operator+(distance n) {
			random_access_iterator	tmp = this;
			return (tmp += n);
		}
		random_access_iterator	&operator-=(distance n)  { return (this += -n); }
		random_access_iterator	operator-(distance n) {
			random_access_iterator	tmp = this;
			return (tmp -= n);
		}
		random_access_iterator	operator[](distance n) { return (*(this + n)); }
		bool					operator<(random_access_iterator const &rhs) { return (this->_ptr < rhs._ptr ); }
		bool					operator<=(random_access_iterator const &rhs) { 
			return (*this < rhs || *this == rhs);
		}
		bool					operator>(random_access_iterator const &rhs) {
			return (this->_ptr > rhs._ptr);
		}
		bool					operator>=(random_access_iterator const &rhs) { return (*this > rhs || *this == rhs); }
		virtual					~random_access_iterator( ) { }
	};
 }


#endif