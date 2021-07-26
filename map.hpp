//
// Created by lchantel on 25.07.2021.
//

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <functional>
# include "iterator.hpp"
# include "lexicographical_compare.hpp"

namespace ft {
	template<class T1, class T2> struct pair {
		pair() : first(T1()), second(T2()) { }
		pair(const pair<T1, T2> &rhs) {
			if (this != &rhs)
				*this = rhs;
		}
		pair(const T1 &a, const T2 &b) : first(a), second(b) { }
		pair    &operator=(const pair &rhs) {
			first = rhs.first;
			second = rhs.second;
			return (*this);
		}
		T1  first;
		T2  second;
	};
	template<class T1, class T2>
	bool    operator==(pair<T1, T2> &lhs, pair<T1, T2> &rhs) {
		return (lhs.first = rhs.first && lhs.second = rhs.second);
	}
	template<class T1, class T2>
	bool    operator!=(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (!(lhs == rhs)); }
	template<class T1, class T2>
	bool    operator<(pair<T1, T2> &lhs, pair<T1, T2> &rhs) {
		return (lhs.first < rhs.frst || (!(lhs.first < rhs.first) && lhs.second < rhs.second));
	}
	template<class T1, class T2>
	bool    operator<=(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (!(rhs < lhs)); }
	template<class T1, class T2>
	bool    operator>(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (lhs < rhs); }
	template<class T1, class T2>
	bool    operator>=(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (!(lhs < rhs)); }
	template<class T1, class T2>
	pair<T1, T2>    make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map {
	public:
		typedef size_t				size_type;
		typedef Key					key_type;
		typedef T					mapped_type;
		typedef pair<const Key, T>	value_type;
		typedef Compare				key_compare;
		typedef Allocator			allocator_type;
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
		class iterator : public forward_iterator<map<key_type, mapped_type> > {
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
			reference		operator*() { return (*this->_ptr->_data); }
			virtual base_iterator<map<key_type, mapped_type> >		&operator++() {
				if (this->_ptr->_rNode)
					this = this->_ptr->_rNode;
				else if (!this->_ptr->_rNode && !this->_ptr->_lNode && this == _head->_rNode)
					return (*this);
				else
					this = this->_ptr->_head;
				return (*this); 
			}
			virtual base_iterator<map<key_type, mapped_type> >		operator++(int) {
				iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			iterator		                                        &operator--() {
				if (this->_ptr->_lNode)
					this = this->_ptr->_lNode;
				else if (!this->_ptr->_rNode && !this->_ptr->_lNode && this == _head->_lNode)
					return (this);
				else
					this = this->_ptr->_head;
				return (*this); 
			}
			iterator		                                        operator--(int) {
				iterator	tmp = *this;
				operator++();
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
		};
		class reverse_iterator : public forward_iterator<map<key_type, mapped_type> > {
			typedef	typename base_iterator<T>::reference	reference;
			typedef typename base_iterator<T>::distance		distance;
			typedef typename base_iterator<T>::pointer		pointer;

			reverse_iterator() { }
			reverse_iterator(const reverse_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			reverse_iterator		&operator=(const reverse_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			reverse_iterator		&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			reference				operator*() { return (*(this->_ptr->_data)); }
			reverse_iterator		                                &operator--() {
				if (this->_ptr->_rNode)
					this = this->_ptr->_rNode;
				else if (!this->_ptr->_rNode && !this->_ptr->_lNode && this == _head->_rNode)
					return (*this);
				else
					this = this->_ptr->_head;
				return (*this); 
			}
			reverse_iterator		                                operator--(int) {
				reverse_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			virtual base_iterator<map<key_type, mapped_type> >		&operator++() {
				if (this->_ptr->_lNode)
					this = this->_ptr->_lNode;
				else if (!this->_ptr->_rNode && !this->_ptr->_lNode && this == _head->_lNode)
					return (*this);
				else
					this = this->_ptr->_head;
				return (*this);
			}
			virtual base_iterator<map<key_type, mapped_type> >		operator++(int) {
				reverse_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			bool			operator<(reverse_iterator const &rhs) { return (this->_ptr < rhs._ptr); }
			bool	        operator<=(reverse_iterator const &rhs) {
				return (*this == rhs || *this < rhs);
			}
			bool			operator>(reverse_iterator const &rhs) { return (this->_ptr > rhs._ptr); }
			bool			operator>=(reverse_iterator const &rhs) {
				return (*this == rhs || *this > rhs);
			}
			bool            operator==(pointer const rhs) { return this->_ptr == rhs; }
			virtual ~reverse_iterator( ) { }
		};
		iterator			begin() { 
			iterator	tmp = this;
			while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				--tmp;
			return (tmp);
		}
		iterator			end() { 
			iterator	tmp = this;
			while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				++tmp;
			return (tmp->_rNode);
		}
		reverse_iterator	rend() { 
			reverse_iterator	tmp = this;
			while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				--tmp;
			return (tmp);
		}
		reverse_iterator	rbegin() { 
			reverse_iterator	tmp = this;
			while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				++tmp;
			return (tmp);
		}
		bool 				empty() const { return (!_size); }
		size_type 			size() const { return (_size); }
		size_type 			max_size() const { return ( _alloc.max_size()); }
		mapped_type			&operator[](const key_type &k) {
			map	*tmp = this;
			map	*res = 0x0;
		
			if (!(res = search_key(tmp, k))) {
				addElement(&tmp, k, &res);
				++_size;
			}
			return (res->_data->second);
		}

	private:
		size_type							_size;
		map									*_lNode;
		map									*_rNode;
		map									*_head;
		allocator_type						_alloc;
		std::allocator<map<Key, T> >		_allocMap;			
		value_type							_data;
		map									*search_key(map *roll, key_type const &key) {
			if (!roll)
				return (0x0);
			else {
				if (roll->_data->first == key)
					return (roll);
				if (roll->_data->first > key)
					return (search_key(roll->_lNode, key));
				else
					return (search_key(roll->_rNode, key));
			}	
		}		
		void							addElement(map **head, key_type const &key, map **res) {
			if (!(*head)) {
				map	tmp;
				tmp._data.first = key;
				tmp._data.second = mapped_type();
				tmp._lNode = 0x0;
				tmp._rNode = 0x0;
				_allocMap.allocate(*head, 1);
				/*(*head)->_data->first = key;
				(*head)->_data->second = mapped_type();
				(*head)->_lNode = 0x0;
				(*head)->_rNode = 0x0;*/
				_allocMap.construct(*head, tmp);
				*res = *head;
			} else {
				if ((*head)->_data->first > key)
					addElement(&(*head)->_lNode, key);
				else
					addElement(&(*head)->_rNode, key);
			}
		}
	};
}

#endif //FT_CONTAINERS_MAP_HPP
