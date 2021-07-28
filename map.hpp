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
		typedef size_t                  size_type;
        typedef Key                     key_type;
        typedef T                       mapped_type;
        typedef pair<const Key, T>      value_type;
        typedef Compare                 key_compare;
        typedef Allocator               allocator_type;

		class iterator : public bidirectional_iterator<value_type > {
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
			reference					operator*() { return (*(this->_ptr)); }
			pointer						operator->() { return (this->_ptr); }
			virtual base_iterator<map<key_type, mapped_type> >				&operator++() {
				
			}
			virtual base_iterator<map<key_type, mapped_type> >				operator++(int) {
				iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			iterator		                                        		&operator--() {
				map									*tmp = _head;
				size_type							size;
				value_type							res;
				vector<map<key_type, mapped_type>>	stackImp;

				while (tmp != minElement()) {

				}
			}
			virtual bidirectional_iterator<map<key_type, mapped_type> >		operator--(int) {
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
		class reverse_iterator : public bidirectional_iterator<map<key_type, mapped_type> > {
		public:
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
			//pair<key_type, mapped_type>	&operator*() { return (*(this->_ptr->_data)); }
			//pair<key_type, mapped_type>	*operator->() { return (this->_ptr->_data); }
			reference					operator*() { return (*(this->_ptr->_data)); }
			pointer						operator->() { return (this->_ptr->_data); }
			pair<key_type, mapped_type>	&operator*() { return (*(this->_ptr->_data)); }
			pair<key_type, mapped_type>	*operator->() { return (this->_ptr->_data); }
			virtual bidirectional_iterator<map<key_type, mapped_type> > &operator--() {
				if (this->_ptr->_rNode)
					this = this->_ptr->_rNode;
				else if (!this->_ptr->_rNode && !this->_ptr->_lNode && this == _head->_rNode)
					return (*this);
				else
					this = this->_ptr->_head;
				return (*this); 
			}
			virtual bidirectional_iterator<map<key_type, mapped_type> > operator--(int) {
				reverse_iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			virtual base_iterator<map<key_type, mapped_type> >		    &operator++() {
				if (this->_ptr->_lNode)
					this = this->_ptr->_lNode;
				else if (!this->_ptr->_rNode && !this->_ptr->_lNode && this == _head->_lNode)
					return (*this);
				else
					this = this->_ptr->_head;
				return (*this);
			}
			virtual base_iterator<map<key_type, mapped_type> >		    operator++(int) {
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
		class const_iterator : public iterator {
		public:
			friend class iterator;
			typedef	typename base_iterator<T>::reference	reference;
			typedef typename base_iterator<T>::distance		distance;
			typedef typename base_iterator<T>::pointer		pointer;

			const_iterator() { }
			const_iterator(const const_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_iterator(const const_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_iterator		&operator=(const const_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			const_iterator		&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			const_iterator		&operator=(const iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			reference			operator*() { return (*(this->_ptr->_data)); }
			pointer				operator->() { return (this->_ptr->_data); }
			const reference		operator*() const {
				return (*(this->_ptr->_data));
			}
			const pointer		operator->() const { return (this->_ptr->_data); }
		};
		class const_reverse_iterator : public reverse_iterator {
		public:
			friend class reverse_iterator;
			typedef	typename base_iterator<T>::reference	reference;
			typedef typename base_iterator<T>::distance		distance;
			typedef typename base_iterator<T>::pointer		pointer;

			const_reverse_iterator() { }
			const_reverse_iterator(const const_reverse_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_reverse_iterator(const const_reverse_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_reverse_iterator		&operator=(const const_reverse_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			const_reverse_iterator		&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			const_reverse_iterator		&operator=(const reverse_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			reference			operator*() { return (*(this->_ptr->_data)); }
			pointer				operator->() { return (this->_ptr->_data); }
			const reference		operator*() const {
				return (*(this->_ptr->_data));
			}
			const pointer		operator->() const { return (this->_ptr->_data); }
		};
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())  {
			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = this;
			_alloc = alloc;
			_data = ft::pair<Key, T>();
		 };
		map(const map &x) {
			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = this;
			_alloc = Allocator();
			_data = ft::pair<Key, T>();
			if (this != &x)
				*this = x;
		}
		map		&operator=(const map &x) {
			clearMap(this);
			this->_lNode = 0x0;
			this->_rNode = 0x0;
			this->_data = make_pair(key_type(), mapped_type());
			this = x;
		}
		explicit map(iterator first, iterator last,
		             const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) {
			map		*roll = this;
			map		*lazy = 0x0;
			bool	start = false;

			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = 0x0;
			_alloc = alloc;
			for ( ; first != last; ++first) {
				if (!start) {
					addElement(&_head, first->_data->first, &lazy);
					this = _head;
					start = true;
				} else
					addElement(&this, first->_data->first, &lazy);
				++_size;
			}
		}
		iterator			begin() { 
			iterator	tmp = minElement(this);
			return (tmp);
		}
		iterator			end() { 
			iterator	tmp = this;
			while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				++tmp;
			return (tmp->_rNode);
			//return (0x0);
		}
		reverse_iterator	rend() { 
			reverse_iterator	tmp = minElement(this);
			/*while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				--tmp;
			return (tmp->_lNode);*/
			return();
		}
		reverse_iterator	rbegin() { 
			reverse_iterator	tmp = maxElement(this);
			/*while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				++tmp;*/
			return (tmp);
		}
		bool 					empty() const { return (!_size); }
		size_type 				size() const { return (_size); }
		size_type 				max_size() const { return ( _alloc.max_size()); }
		mapped_type				&operator[](const key_type &k) {
			map	*tmp = this;
			map	*res = 0x0;
		
			if (!(res = search_key(tmp, k))) {
				addElement(&tmp, k, &res);
				++_size;
			}
			return (res->_data.second);
		}
		pair<iterator, bool>	insert(const value_type& val) {
			map			result;
			map			*paper = 0x0;
			iterator	it;
			bool		state = false;

			result._data = val;
			if (!search_key(this, val.first)) {
				if (_head) {
					addElement(&_head, val.first, &paper);
					this = _head;
				} else
					addElement(&this, val.first, &paper);
				++_size;
				state = true;
			}
			this[val.first] = val.second;
			it = search_key(val.first);
			return (make_pair(it, state));
		}
		iterator				insert(iterator position, const value_type &val) {
			map 					lValue = *position;
			pair<iterator, bool>	insertRes;
			iterator				it;

			if (lValue._data > lValue._lNode->_data
				&& lValue._data < lValue._rNode->_data
				&& lValue._data > lValue._head->_data) {
				lValue._data = val;
				it = position;
			} else {
				insertRes = insert(val);
				it = insertRes.first;
			}
			return (it);
		}
		void					insert(iterator first, iterator last) {
			for ( ; first != last; ++first) {
				pair<iterator, bool>    calc;
				map                     tmp = *first;

				calc = insert(tmp._data);
				this[tmp._data.first] = tmp._data.second;
				_size += (calc.second == true);
			}
		}
		void                    erase(iterator position) {
			map tmp = *position;
			map *ptr = 0x0;

			ptr = search_key(this, tmp._data.first);
			if (ptr)
				deleteElement(&this, tmp._data.first);
		}
		size_type               erase(const key_type &k) {
			size_type   res = 0;
			map         *tmp = 0x0;

			while ((tmp = search_key(k))) {
				++res;
				deleteElement(&this, k);
			}
			return (res);
		}
		void                					erase(iterator first, iterator last) {
			for ( ; first != last; ++first) {
				erase(first);
			}
		}
		void                					swap(map &x) {
			map buff(*this);

			*this = x;
			x = buff;
		}
		void                					clear() {
			clearMap(this);
		}
		key_compare								key_comp() const {
			return (key_compare());
		}
		class value_compare {
			friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) { }
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool operator()(const value_type &x, const value_type &y) {
				return (comp(x.first, y.first));
			}
		};
		value_compare							value_comp() const {
			value_compare	result(key_compare());
			return (result);
		}
		iterator								find(const key_type &k) {
			map	*tmp = search_key(this, k);
			return (tmp);
		}
		const_iterator							find(const key_type &k) {
			map	*tmp = search_key(this, k);
			return (tmp);
		}
		size_type								count(const key_type &k) {
			return ((search_key(this, k) != 0x0));
		}
		iterator								lower_bound(const key_type &k) {
			for (iterator it = this.begin(); it != this.end(); ++it) {
				map	tmp = *it;
				if (!(key_compare(tmp._data.first, k)))
					return (it);
			}
			return (end());
		}
		const_iterator							lower_bound(const key_type &k) const {
			const_iterator cit;

			for (iterator it = this.begin(); it != this.end(); ++it) {
				map	tmp = *it;
				if (!(key_compare(tmp._data.first, k)))
					return ((cit = it));
			}
			return (0x0);
		}
		iterator								upper_bound(const key_type &k) {
			for (iterator it = this.begin(); it != this.end(); ++it) {
				map	tmp = *it;
				if (key_compare(tmp._data.first, k))
					return (it);
			}
			return (end());
		}
		const_iterator							upper_bound(const key_type &k) const {
			const_iterator cit;

			for (iterator it = this.begin(); it != this.end(); ++it) {
				map	tmp = *it;
				if (key_compare(tmp._data.first, k))
					return ((cit = it));
			}
			return (0x0);
		}
		pair<const_iterator, const_iterator>	equal(const key_type &k) const {
			pair<const_iterator, const_iterator>	res;
			for (iterator it = this.begin(); it != this.end(); ++it) {
				map tmp = *it;
				if (tmp._data.first == k) {
					res.first = it;
					res.second = ++it;
					return (res);
				}
			}
			res.first = 0x0;
			res.second = 0x0;
			return (res);
		}
		pair<iterator, iterator>				equal(const key_type &k) {
			pair<iterator, iterator>	res;
			for (iterator it = this.begin(); it != this.end(); ++it) {
				map tmp = *it;
				if (tmp._data.first == k) {
					res.first = it;
					res.second = ++it;
					return (res);
				}
			}
			res.first = 0x0;
			res.second = 0x0;
			return (res);
		}
		allocator_type							get_allocator() const {
			return (_alloc);
		}
	private:
		size_type							_size;
		map									*_lNode;
		map									*_rNode;
		map									*_head;
		allocator_type						_alloc;		
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
		void								addElement(map **head, key_type const &key, map **res) {
			static map	*parrent;

			if (!(*head)) {
				map	tmp;
				tmp._data = make_pair(key, mapped_type());
				tmp._lNode = 0x0;
				tmp._rNode = 0x0;
				_allocMap.allocate(*head, 1);
				_allocMap.construct(*head, tmp);
				if (!parrent)
					parrent = (*head);
				(*head)->_head = parrent;
				*res = *head;
			} else {
				parrent = *head;
				if ((*head)->_data->first > key)
					addElement(&(*head)->_lNode, key);
				else
					addElement(&(*head)->_rNode, key);
			}
		}
		void								clearMap(map *head) {
			if (head && head->_head != this) {
				clearMap(head->_lNode);
				clearMap(head->_rNode);
				_allocMap.destroy(head);
				_allocMap.deallocate(head);
			}
		}
		key_type							iterativePreorder(const key_type &k) {
			map										*tmp = _head;
			size_type								size;
			value_type								res;
			vector<map<key_type, mapped_type> *>	stackImp;
			vector<map<key_type, mapped_type> *>	stackImpRes;

			if (!_head)
				return ;
			stackImp.push_back(tmp);
			while (!stackImp.empty()) {
				tmp = stackImp.front();
				if (tmp->_lNode)
					
			}
		}
		map                                 *minElement(map *head) {
			if (!head)
				return (0x0);
			while (head->_lNode)
				head = head->_lNode;
			return (head);
		}
		map									*maxElement(map *head) {
			if (!head)
				return (0x0);
			while (head->_rNode)
				head = head->_rNode;
			return (head);
		}
		void								deleteElement(map **head, key_type const &k) {
			map	*tmp;
			if (*head) {
				if ((*head)->_data.first > k)
					deleteElement(&(*head)->_lNode, k);
				else if ((*head)->_data.first < k)
					deleteElement(&(*head)->_rNode, k);
				else {
					if (!(*head)->_lNode) {
						tmp = *head;
						*head = (*head)->_rNode;
						_allocMap.destroy(*head);
						_allocMap.deallocate(*head);
					} else if (!*head->_rNode) {
						tmp = *head;
						*head = (*head)->_lNode;
						_allocMap.destroy(*head);
						_allocMap.deallocate(*head);
					} else {
						tmp = maxElement((*head)->_lNode);
						(*head)->_data = tmp->_data;
						deleteElement(&((*head)->_lNode), tmp->_data.first);
					}
				}
			}
		}
	};
}

#endif //FT_CONTAINERS_MAP_HPP
