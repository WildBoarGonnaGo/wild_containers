//
// Created by lchantel on 25.07.2021.
//

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <functional>
# include "iterator.hpp"
# include "lexicographical_compare.hpp"
# include "stack.hpp"

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
		typedef std::allocator<pair<Key, T> >	inner_allocator;
	public:
		typedef size_t                  		size_type;
        typedef Key                     		key_type;
        typedef T                       		mapped_type;
        typedef pair<const Key, T>      		value_type;
        typedef Compare                 		key_compare;
        typedef Allocator               		allocator_type;

		class iterator : public virtual bidirectional_iterator<pair<key_type, mapped_type> >,
		        public virtual map<Key, T> {
		public:
			typedef	typename base_iterator<pair<key_type, mapped_type> >::reference	reference;
			typedef typename base_iterator<pair<key_type, mapped_type> >::distance	distance;
			typedef typename base_iterator<pair<key_type, mapped_type> >::pointer	pointer;

			iterator() { }
			iterator(const iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			iterator															&operator=(const iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			iterator															&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			iterator															&operator=(map *rhs) {
				this->_iterHead = rhs;
				return (*this);
			}
			reference															operator*() { return (*(this->_ptr)); }
			pointer																operator->() { return (this->_ptr); }
			virtual base_iterator<pair<key_type, mapped_type> >					&operator++() {
				//iterator							*res = this;
				map 								*mapFound = 0x0;
				//vector<map<key_type, mapped_type> *> ret = map::_hintTransCp->iterativeInorder();
				vector<map<key_type, mapped_type> *> ret = _iterHead->iterativeInorder(_iterHead->_head);
				for (size_type i = 0; i < ret.size(); ++i) {
					if (ret[i]->_data->first <= (*this)->first)
						continue ;
					else {
						mapFound = ret[i];
						break ;
					}
				}
				if (!mapFound)
					mapFound = _iterHead;
				(*this)->first = mapFound->_data->first;
				(*this)->second = mapFound->_data->second;
				return (*this);
			}
			virtual base_iterator<pair<key_type, mapped_type> >					operator++(int) {
				iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			virtual bidirectional_iterator<pair<key_type, mapped_type> >		&operator--() {
				map *mapFound = 0x0;
				//vector<map<key_type, mapped_type> *> ret = map::_hintTransCp->iterativeInorder();
				vector<map<key_type, mapped_type> *> ret = iterativeInorder(getInstanceHead());
				for (size_type i = ret.size() - 1; i >= 0; --i) {
					if (ret[i]->_data->first >= (*this)->first)
						continue ;
					else
						mapFound = ret[i];
				}
				(*this)->first = mapFound->_data->first;
				(*this)->second = mapFound->_data->second;
				return (*this);
			}
			virtual bidirectional_iterator<pair<key_type, mapped_type> >		operator--(int) {
				iterator	tmp = *this;
				operator--();
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
			bool            operator==(iterator const &rhs) { return ((*this)->first == rhs._ptr->first && (*this)->second == rhs._ptr->second); }
			bool            operator!=(iterator const &rhs) { return (!(*this == rhs)); }
			virtual ~iterator( ) { }
		protected:
			map				*_iterHead;
		};
		class reverse_iterator : public virtual bidirectional_iterator<pair<key_type, mapped_type> >,
		public virtual map<Key, T> {
		public:
			typedef	typename base_iterator<pair<key_type, mapped_type> >::reference	reference;
			typedef typename base_iterator<pair<key_type, mapped_type> >::distance	distance;
			typedef typename base_iterator<pair<key_type, mapped_type> >::pointer	pointer;

			reverse_iterator() { }
			reverse_iterator(const reverse_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			reverse_iterator				&operator=(const reverse_iterator &rhs) {
				this->_ptr = rhs._ptr;
				return (*this);
			}
			reverse_iterator				&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			reverse_iterator				&operator=(map *rhs) {
			    this->_iterHead = rhs;
			    return (*this);
			}
			reference						operator*() { return (*(this->_ptr)); }
			pointer							operator->() { return (this->_ptr); }
			virtual bidirectional_iterator<pair<key_type, mapped_type> > &operator--() {
				map *mapFound = 0x0;
				//vector<map<key_type, mapped_type> *> ret = map::_hintTransCp->iterativeInorder();
				vector<map<key_type, mapped_type> *> ret = iterativeInorder(getInstanceHead());
				for (size_type i = 0; i < ret.size(); ++i) {
					if (ret[i]->_data->first < this->first)
						continue ;
					else
						mapFound = ret[i];
				}
				(*this)->first = mapFound->_data->first;
				(*this)->second = mapFound->_data->second;
				return (*this); 
			}
			virtual bidirectional_iterator<pair<key_type, mapped_type> >	operator--(int) {
				reverse_iterator	tmp = *this;
				operator--();
				return (tmp);
			}
			virtual base_iterator<pair<key_type, mapped_type> >		    	&operator++() {
				map *mapFound = 0x0;
				vector<map<key_type, mapped_type> *> ret = iterativeInorder(getInstanceHead());
				for (size_type i = ret.size() - 1; i >= 0; --i) {
					if (ret[i]->_data->first > (*this)->first)
						continue ;
					else
						mapFound = ret[i];
				}
				(*this)->first = mapFound->_data->first;
				(*this)->second = mapFound->_data->second;
				return (*this);
			}
			virtual base_iterator<pair<key_type, mapped_type> >		    	operator++(int) {
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
		protected:
		    map				*_iterHead;
		};
		class const_iterator : public iterator {
		public:
			//friend class base_iterator<pair<key_type, mapped_type> >;
			typedef	typename base_iterator<pair<key_type, mapped_type> >::reference	reference;
			typedef typename base_iterator<pair<key_type, mapped_type> >::distance	distance;
			typedef typename base_iterator<pair<key_type, mapped_type> >::pointer	pointer;

			const_iterator() { }
			const_iterator(const const_iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			const_iterator(iterator &rhs) {
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
			const_iterator		&operator=(iterator &rhs) {
				this->_ptr = rhs.operator->();
				return (*this);
			}
			reference			operator*() { return (*(this->_ptr)); }
			pointer				operator->() { return (this->_ptr); }
			const reference		operator*() const {
				return (*(this->_ptr));
			}
			const pointer		operator->() const { return (this->_ptr); }
		};
		class const_reverse_iterator : virtual public reverse_iterator {
		public:
			typedef	typename base_iterator<pair<key_type, mapped_type> >::reference	reference;
			typedef typename base_iterator<pair<key_type, mapped_type> >::distance	distance;
			typedef typename base_iterator<pair<key_type, mapped_type> >::pointer		pointer;

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
			const_reverse_iterator		&operator=(const pointer rhs) {
				this->_ptr = rhs;
				return (*this);
			}
			const_reverse_iterator		&operator=(const reverse_iterator &rhs) {
				this->_ptr = rhs.operator->();
				return (*this);
			}
			reference					operator*() { return (*(this->_ptr)); }
			pointer						operator->() { return (this->_ptr); }
			const reference				operator*() const {
				return (*(this->_ptr));
			}
			const pointer				operator->() const { return (this->_ptr); }
		};
		explicit 						map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())  {
			pair<key_type, mapped_type>	lValue;
			lValue.first = key_type();
			lValue.second = mapped_type();
			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = 0x0;
			_alloc = alloc;
			//_in = inner_allocator();
			_comp = comp;
			_data = _inAlloc.allocate(1);
			//map::_hintTransCp = this;
			_inAlloc.construct(_data, lValue);
		 };
		map(const map &x) {
			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = 0x0;
			//_alloc = inner_allocator();
			//_data = ft::pair<Key, T>();
			//_data = _alloc.allocate(1);
			//_alloc.construct(_data, make_pair(key_type(), mapped_type()));
			//map::_hintTransCp = this;
			if (this != &x)
				*this = x;
		}
		map									&operator=(const map &x) {
			clearMap(_head);
			_head = _allocMap.allocate(1);
			//_head->_alloc = x._alloc;
			//_head->_allocMap = x._allocMap;
			_head->_lNode = 0x0;
			_head->_rNode = 0x0;
			_data = _inAlloc.allocate(1);
			_head->_comp = x._comp;
			_inAlloc.construct(_data, make_pair(x._data->first, x._data->second));
			for (iterator first = x.begin(); first != x.end(); ++first)
				_head->operator[](first->first) = first->second;
			return (*this);
		}
		explicit 							map(iterator first, iterator last,
		             						const key_compare &comp = key_compare(),
											const allocator_type &alloc = allocator_type()) {
			map		*roll = this;
			map		*lazy = 0x0;
			//bool	start = false;

			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = 0x0;
			_alloc = alloc;
			//_alloc = inner_allocator();
			_data = _inAlloc.allocate(1);
			_inAlloc.construct(pair<key_type, mapped_type>());
			_comp = comp;
			for ( ; first != last; ++first)
				_head->operator[](first->first) = first->second;
		}
		iterator								begin() {
			map			*tmpMap = minElement(_head);
			iterator	res;
			res = this;
			res = (tmpMap != 0x0) ? tmpMap->_data : _data;
			return (res);
		}
		const_iterator							begin() const {
			map			*tmpMap = const_cast<map<key_type, mapped_type> *>(minElement(_head));
			iterator	res;
			res = (tmpMap != 0x0) ? tmpMap->_data : _data;
			return (res);
		}
		iterator								end() {
			iterator	res;
			res = this;
			res = _data;
			return (res);
		}
		const_iterator							end() const {
			iterator res;
			res = const_cast<map *>(this);
			res = _data;
			return (res);
		}
		reverse_iterator					rend() { 
			//map::_hintTransCp = this;
			map					**tmpMap;
			(*tmpMap) = minElement(_head);
			//reverse_iterator	tmp;
			/*while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				--tmp;
			return (tmp->_lNode);*/
			//closeTree(&tmpMap, false);
			(*tmpMap)->_lNode = this;
			reverse_iterator res;
			res = _data;
			return (res);
		}
		const_reverse_iterator				rend() const {
			//map::_hintTransCp = this; 
			map::_hintTransCp = const_cast<map<key_type, mapped_type> *>(this);
			map					**tmpMap;
			(*tmpMap) = minElement(_head);
			//reverse_iterator	tmp;
			/*while (tmp->_lNode && tmp->rNode && tmp != tmp->_head->_lNode)
				--tmp;
			return (tmp->_lNode);*/
			//closeTree(&tmpMap, false);
			if (tmpMap)
				*(tmpMap)->_lNode = const_cast<map<key_type, mapped_type> *>(this);
			reverse_iterator	res;
			res = _data;
			return (res);
		}
		reverse_iterator					rbegin() {
			map			*tmpMap = minElement(_head);
			reverse_iterator	res;
			res = (tmpMap != 0x0) ? tmpMap->_data : _data;
			return (res);
		}
		const_reverse_iterator				rbegin() const {
			map			*tmpMap = const_cast<map<key_type, mapped_type> *>(minElement(_head));
			reverse_iterator	res;
			res = (tmpMap != 0x0) ? tmpMap->_data : _data;
			return (res);
		}
		bool 								empty() const { return (!_size); }
		size_type 							size() const { return (_size); }
		size_type 							max_size() const { return ( _inAlloc.max_size()); }
		mapped_type							&operator[](const key_type &k) {
			map	*tmp = 0x0;
			map	*res = 0x0;
			
			if (!(res = search_key(_head, k))) {
				addElement(&_head, k);
				++_size;
				tmp = search_key(_head, k);
				maxElement(_head)->_rNode = this;
				minElement(_head)->_lNode = this;
				return (tmp->_data->second);	
			}
			return (res->_data->second);
		}
		pair<iterator, bool>				insert(const pair<key_type, mapped_type>& val) {
			pair<key_type, mapped_type>	*result;
			//map			*paper = 0x0;
			//iterator	it;
			bool		state = false;

			//result._data = val;
			if (!search_key(_head, val.first)) {
				addElement(&_head, val.first);
				++_size;
				state = true;
			}
			_head[val.first] = val.second;
			result = search_key(_head, val.first)->_data;
			return (make_pair(result, state));
		}
		iterator								insert(iterator position, const pair<key_type, mapped_type> &val) {
			/*map 					lValue = *position;
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
			return (it);*/
			if (val == *position)
				_head[position->first] == position->second;
			else
				insert(val);
		}
		void									insert(iterator first, iterator last) {
			for ( ; first != last; ++first) {
				insert(*first);
			}
		}
		void                    				erase(iterator position) {
			//map tmp = *position;
			map *ptr = search_key(position->first);

			//ptr = search_key(this, tmp._data.first);
			if (ptr)
				deleteElement(&_head, ptr->_data->first);
		}
		size_type               				erase(const key_type &k) {
			size_type   res = 0;
			map         *tmp = 0x0;

			while ((tmp = search_key(k))) {
				++res;
				deleteElement(&this, k);
			}
			return (res);
		}
		void                					erase(iterator first, iterator last) {
			for ( ; first != last; ++first)
				erase(first);
		}
		void                					swap(map &x) {
			map buff(*this);

			*this = x;
			x = buff;
		}
		void                					clear() {
			clearMap(_head);
		}
		key_compare								key_comp() const {
			return (key_compare());
		}
		class value_compare : public std::binary_function<value_type, value_type, bool>{
			friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) { }
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool operator()(const value_type &x, const value_type &y) const {
				return (comp(x.first, y.first));
			}
		};
		value_compare							value_comp() const {
			value_compare	result((key_compare()));
			return (result);
		}
		iterator								find(const key_type &k) {
			map	*tmp = search_key(this, k);
			return (tmp->_data);
		}
		const_iterator							find(const key_type &k) const {
			map	*tmp = search_key(this, k);
			return (tmp->_data);
		}
		size_type								count(const key_type &k) {
			return ((search_key(this, k) != 0x0));
		}
		iterator								lower_bound(const key_type &k) {
			for (iterator it = _head->begin(); it != _head->end(); ++it) {
				pair<key_type, mapped_type>	tmp = *it;
				if (!(key_compare(tmp.first, k)))
					return (it);
			}
			return (end());
		}
		const_iterator							lower_bound(const key_type &k) const {

			for (iterator it = _head->begin(); it != _head->end(); ++it) {
				pair<key_type, mapped_type>	tmp = *it;
				if (!(key_compare(tmp.first, k)))
					return (it);
			}
			return (0x0);
		}
		iterator								upper_bound(const key_type &k) {
			for (iterator it = _head->begin(); it != _head->end(); ++it) {
				pair<key_type, mapped_type>	tmp = *it;
				if (key_compare(tmp.first, k))
					return (it);
			}
			return (end());
		}
		const_iterator							upper_bound(const key_type &k) const {
			const_iterator cit;

			for (iterator it = this->begin(); it != this->end(); ++it) {
				pair<key_type, mapped_type>	tmp = *it;
				if (key_compare(tmp.first, k))
					return ((cit = it));
			}
			return (0x0);
		}
		pair<const_iterator, const_iterator>	equal(const key_type &k) const {
			pair<const_iterator, const_iterator>	res;
			for (iterator it = _head->begin(); it != _head->end(); ++it) {
				pair<key_type, mapped_type>	tmp = *it;
				if (tmp.first == k) {
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
			for (iterator it = _head->begin(); it != _head->end(); ++it) {
				value_type	tmp = *it;
				if (tmp.first == k) {
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
	protected:
		size_type							        _size;
		map									        *_head;
		allocator_type						        _alloc;
		inner_allocator								_inAlloc;
		pair<key_type, mapped_type>					*_data;
		map									        *_lNode;
		map									        *_rNode;
		key_compare									_comp;
		std::allocator<map<key_type, mapped_type> > _allocMap;
		static map									*_hintTransCp;
		map										*search_key(map *roll, key_type const &key) {
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
		void									addElement(map **head, key_type const &key) {
			if (!(*head) || (*head) == this) {
				*head = _allocMap.allocate(1);
				map doll;
				_allocMap.construct((*head), doll);
				(*head)->_data = _inAlloc.allocate(1);
				pair<Key, T> dataValue;
				dataValue.first = key;
				dataValue.second = mapped_type();
				_inAlloc.construct((*head)->_data, dataValue);
				(*head)->_lNode = 0x0;
				(*head)->_rNode = 0x0;
			} else {
				//parrent = *head;
				if ((*head)->_data->first > key)
					addElement(&(*head)->_lNode, key);
				else
					addElement(&(*head)->_rNode, key);
			}
		}
		void									clearMap(map *head) {
			if (head) {
				clearMap(head->_lNode);
				clearMap(head->_rNode);
				_inAlloc.destroy(head->_data);
				_inAlloc.deallocate(head->_data, 1);
				_allocMap.destroy(head);
				_allocMap.deallocate(head, 1);
				head = 0x0;
			}
		}
		void									closeTree(map **tail, bool toMax) {
			if (!toMax)
				*tail->_lNode = this;
			else
				*tail->_rNode = this;
		}
		vector<map<key_type, mapped_type> *> 	iterativeInorder(map *head) {
			map										*tmp = head;
			//size_type								size;
			//value_type							res;
			stack<map<key_type, mapped_type> *>     cage;
			vector<map<key_type, mapped_type> *>    iterBox;

			while (!cage.empty() || (tmp && tmp != this)) {
				if (tmp && tmp != this) {
					cage.push(tmp);
					tmp = tmp->_lNode;
				} else {
					tmp = cage.top();
					cage.pop(); 
					iterBox.push_back(tmp);
					tmp = tmp->_rNode;
				}
			}
			return (iterBox);
		}
		map                                 	*minElement(map *head) {
			if (!head)
				return (0x0);
			while (head->_lNode && head->_lNode != this)
				head = head->_lNode;
			return (head);
		}
		map const                                *minElement(map *head) const {
			if (!head)
				return (0x0);
			while (head->_lNode && head->_lNode != this)
				head = head->_lNode;
			return (head);
		}
		map										*maxElement(map *head) {
			if (!head)
				return (0x0);
			while (head->_rNode && head->_rNode != this)
				head = head->_rNode;
			return (head);
		}
		map	const								*maxElement(map *head) const {
			if (!head)
				return (0x0);
			while (head->_rNode && head->_rNode != this)
				head = head->_rNode;
			return (head);
		}
		void									deleteElement(map **head, key_type const &k) {
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
						_inAlloc.destroy(tmp->_data);
						_inAlloc.deallocate(tmp->_data, 1);
						_allocMap.destroy(tmp);
						_allocMap.deallocate(tmp, 1);
					} else if (!*head->_rNode) {
						tmp = *head;
						*head = (*head)->_lNode;
						_inAlloc.destroy(tmp->_data);
						_inAlloc.deallocate(tmp->_data), 1;
						_allocMap.destroy(tmp);
						_allocMap.deallocate(tmp, 1);
					} else {
						tmp = maxElement((*head)->_lNode);
						(*head)->_data = tmp->_data;
						deleteElement(&((*head)->_lNode), tmp->_data->first);
					}
				}
			}
		}
		map	*getInstanceHead() {
			return (this->_head);
		}
	};
}

#endif //FT_CONTAINERS_MAP_HPP
