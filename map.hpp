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

		class iterator : public virtual bidirectional_iterator<pair<key_type, mapped_type> > {
		public:
		    friend class map;
			typedef	typename base_iterator<pair<key_type, mapped_type> >::reference	reference;
			typedef typename base_iterator<pair<key_type, mapped_type> >::distance	distance;
			typedef typename base_iterator<pair<key_type, mapped_type> >::pointer	pointer;

			iterator() : _iterHead(0x0) { }
			iterator(const iterator &rhs) {
				if (this != &rhs)
					*this = rhs;
			}
			iterator															&operator=(const iterator &rhs) {
				this->_ptr = rhs._ptr;
				this->_iterHead = rhs._iterHead;
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
			iterator															&operator=(map const *rhs) {
			    this->_iterHead = const_cast<map *>(rhs);
			    return (*this);
			}
			reference															operator*() { return (*(this->_ptr)); }
			pointer																operator->() { return (this->_ptr); }
			virtual base_iterator<pair<key_type, mapped_type> >					&operator++() {
				map 								*mapFound = 0x0;

				vector<map<key_type, mapped_type> *> ret = _iterHead->iterativeInorder(_iterHead->_head);
				for (size_type i = 0; i < ret.size(); ++i) {
					if (ret[i]->_data->first <= this->_ptr->first)
						continue ;
					else {
						mapFound = ret[i];
						break ;
					}
				}
				if (!mapFound)
					mapFound = _iterHead;
				this->_ptr = mapFound->_data;
				return (*this);
			}
			virtual base_iterator<pair<key_type, mapped_type> >					operator++(int) {
				iterator	tmp = *this;
				operator++();
				return (tmp);
			}
			virtual bidirectional_iterator<pair<key_type, mapped_type> >		&operator--() {
			    map 								*mapFound = 0x0;

			    vector<map<key_type, mapped_type> *> ret = _iterHead->iterativeInorder(_iterHead->_head);
			    for ( int i = static_cast<int>(_iterHead->size() - 1); i >= 0; --i) {
			        if (ret[i]->_data->first >= this->_ptr->first)
			            continue ;
			        else {
			            mapFound = ret[i];
			            break ;
			        }
			    }
			    if (!mapFound)
			        mapFound = _iterHead;
			    this->_ptr = mapFound->_data;
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
			bool            operator==(pointer const rhs) { return this->_ptr->first == rhs->second; }
			bool            operator==(iterator const &rhs) { return (this->_ptr == rhs._ptr); }
			bool            operator!=(iterator const &rhs) { return (!(*this == rhs)); }
			virtual ~iterator( ) { }
		protected:
			map				             *_iterHead;
		};
		class reverse_iterator : public virtual bidirectional_iterator<pair<key_type, mapped_type> > {
		public:
		    friend class map;
		    typedef	typename base_iterator<pair<key_type, mapped_type> >::reference	reference;
		    typedef typename base_iterator<pair<key_type, mapped_type> >::distance	distance;
		    typedef typename base_iterator<pair<key_type, mapped_type> >::pointer	pointer;

		    reverse_iterator() : _iterHead(0x0) { }
		    reverse_iterator(const reverse_iterator &rhs) {
		        if (this != &rhs)
		            *this = rhs;
		    }
		    reverse_iterator															&operator=(const reverse_iterator &rhs) {
		        this->_ptr = rhs._ptr;
		        return (*this);
		    }
		    reverse_iterator															&operator=(const pointer rhs) {
		        this->_ptr = rhs;
		        return (*this);
		    }
		    reverse_iterator															&operator=(map *rhs) {
		        this->_iterHead = rhs;
		        return (*this);
		    }
		    reverse_iterator															&operator=(map const *rhs) {
		        this->_iterHead = const_cast<map *>(rhs);
		        return (*this);
		    }
		    reference															operator*() { return (*(this->_ptr)); }
		    pointer																operator->() { return (this->_ptr); }
		    virtual base_iterator<pair<key_type, mapped_type> >					&operator++() {
		        map 								*mapFound = 0x0;

		        vector<map<key_type, mapped_type> *> ret = _iterHead->iterativeInorder(_iterHead->_head);
		        for (int i = static_cast<int>(_iterHead->size() - 1); i >= 0; --i) {
		            if (ret[i]->_data->first >= this->_ptr->first)
		                continue ;
		            else {
		                mapFound = ret[i];
		                break ;
		            }
		        }
		        if (!mapFound)
		            mapFound = _iterHead;
		        this->_ptr = mapFound->_data;
		        return (*this);
		    }
		    virtual base_iterator<pair<key_type, mapped_type> >					operator++(int) {
		        reverse_iterator	tmp = *this;
		        operator++();
		        return (tmp);
		    }
		    virtual bidirectional_iterator<pair<key_type, mapped_type> >		&operator--() {
		        map 								*mapFound = 0x0;

		        vector<map<key_type, mapped_type> *> ret = _iterHead->iterativeInorder(_iterHead->_head);
		        for (size_type i = 0; i < ret.size(); ++i) {
		            if (ret[i]->_data->first <= this->_ptr->first)
		                continue ;
		            else {
		                mapFound = ret[i];
		                break ;
		            }
		        }
		        if (!mapFound)
		            mapFound = _iterHead;
		        this->_ptr = mapFound->_data;
		        return (*this);
		    }
		    virtual bidirectional_iterator<pair<key_type, mapped_type> >		operator--(int) {
		        reverse_iterator	tmp = *this;
		        operator--();
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
		    bool            operator==(pointer const rhs) { return this->_ptr->first == rhs->second; }
		    bool            operator==(reverse_iterator const &rhs) { return (this->_ptr == rhs._ptr); }
		    bool            operator!=(reverse_iterator const &rhs) { return (!(*this == rhs)); }
		    virtual ~reverse_iterator( ) { }
		protected:
		    map				             *_iterHead;
		};
		class const_iterator : public iterator {
		public:
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
			const_iterator		&operator=(map *rhs) {
			    this->_iterHead = rhs;
			    return (*this);
			}
			const_iterator		&operator=(map const *rhs) {
			    this->_iterHead = const_cast<map *>(rhs);
			    return (*this);
			}
			const_iterator		&operator=(iterator &rhs) {
				this->_ptr = rhs.operator->();
				this->_iterHead = rhs._iterHead;
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
			const_reverse_iterator(reverse_iterator &rhs) {
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
			const_reverse_iterator		&operator=(map *rhs) {
			    this->_iterHead = rhs;
			    return (*this);
			}
			const_reverse_iterator		&operator=(map const *rhs) {
			    this->_iterHead = const_cast<map *>(rhs);
			    return (*this);
			}
			const_reverse_iterator		&operator=(iterator &rhs) {
			    this->_ptr = rhs.operator->();
			    this->_iterHead = rhs._iterHead;
			    return (*this);
			}
			reference			        operator*() { return (*(this->_ptr)); }
			pointer				        operator->() { return (this->_ptr); }
			const reference		        operator*() const {
			    return (*(this->_ptr));
			}
			const pointer		        operator->() const { return (this->_ptr); }
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
			_comp = comp;
			_data = _inAlloc.allocate(1);
			_inAlloc.construct(_data, lValue);
		 };
		map(const map &x) {
			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = 0x0;
			if (this != &x)
				*this = x;
		}
		map									&operator=(const map &x) {
		    pair<Key, T>    pairDefault;

			clearMap(&_head);
			_size = 0;
			_head = 0x0;
			_lNode = 0x0;
			_rNode = 0x0;
			pairDefault.first = key_type();
			pairDefault.second = mapped_type();
			_data = _inAlloc.allocate(1);
			_comp = x._comp;
			_alloc = x.get_allocator();
			_inAlloc.construct(_data, pairDefault);
			for (const_iterator first = x.begin(); first != x.end(); ++first)
			    (*this)[first->first] = first->second;
			return (*this);
		}
		explicit 							map(iterator first, iterator last,
		             						const key_compare &comp = key_compare(),
											const allocator_type &alloc = allocator_type()) {
			pair<Key, T>    pairValue;

			_size = 0;
			_lNode = 0x0;
			_rNode = 0x0;
			_head = 0x0;
			_alloc = alloc;
			_data = _inAlloc.allocate(1);
			pairValue.first = key_type();
			pairValue.second = key_type();
			_inAlloc.construct(_data, pairValue);
			_comp = comp;
			for ( ; first != last; ++first)
			    (*this)[first->first] = first->second;
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
			res = this;
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
			res = this;
			res = _data;
			return (res);
		}
		reverse_iterator					    rend() {
		    reverse_iterator res;
		    res = this;
		    res = _data;
		    return (res);
		}
		const_reverse_iterator				    rend() const {
		    reverse_iterator res;
		    res = this;
		    res = _data;
		    return (res);
		}
		reverse_iterator					    rbegin() {
			map			*tmpMap = maxElement(_head);
			reverse_iterator	res;
			res = this;
			res = (tmpMap != 0x0) ? tmpMap->_data : _data;
			return (res);
		}
		const_reverse_iterator				    rbegin() const {
			map			*tmpMap = const_cast<map<key_type, mapped_type> *>(maxElement(_head));
			reverse_iterator	res;
			res = this;
			res = (tmpMap != 0x0) ? tmpMap->_data : _data;
			return (res);
		}
		bool 								empty() const { return (!_size); }
		size_type 							size() const { return (_size); }
		size_type 							max_size() const { return ( _alloc.max_size() / sizeof(pair<Key, T> *)); }
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
			bool		                state = false;
			iterator                    res;

			if (!search_key(_head, val.first)) {
				addElement(&_head, val.first);
				++_size;
				maxElement(_head)->_rNode = this;
				minElement(_head)->_lNode = this;
				state = true;
				(*_head)[val.first] = val.second;
			}
			for (res = this->begin(); res != this->end(); ++res) {
			    if ((res->first == val.first && res->second == val.second && state) ||
			    (res->first == val.first && !state))
			        break ;
			}
			const pair<iterator, bool>  ret = make_pair<iterator, bool>(res, state);
			return (ret);
		}
		iterator							insert(iterator position, const pair<key_type, mapped_type> &val) {
		    map         *searchObj = search_key(_head, position->first);
		    iterator    it;

		    it = find(val.first);
		    if (it == end()) {
		        if (val.first > position->first && (!searchObj->_rNode || searchObj->_rNode == this)) {
		            addElement(&(searchObj->_rNode), val.first);
		            searchObj->_rNode->_data->second = val.second;
		            it = searchObj->_rNode->_data;
		        } else if (val.first < position->first && (!searchObj->_lNode || searchObj->_lNode == this)) {
		            addElement(&(searchObj->_lNode), val.first);
		            searchObj->_lNode->_data->second = val.second;
		            it = searchObj->_lNode->_data;
		        }
		        else {
		            pair<iterator, bool>    tmp;

		            tmp = insert(val);
		            it = tmp.first;
		        }
		        maxElement(_head)->_rNode = this;
		        minElement(_head)->_lNode = this;
		    }
		    return (it);
		}
		void									insert(iterator first, iterator last) {
		    iterator               res;

			for ( ; first != last; ++first) {
			    if (find(first->first) == end()) {
			        insert(*first);
			        res = find(first->first);
			        res->second = first->second;
			    }
			}
		}
		void                    				erase(iterator position) {
			if (position != end())
				deleteElement(&_head, position->first);
			maxElement(_head)->_rNode = this;
			minElement(_head)->_lNode = this;
		}
		size_type               				erase(const key_type &k) {
			size_type   res = 0;
			map         *tmp = 0x0;

			while ((tmp = search_key(_head, k))) {
				++res;
				deleteElement(&_head, k);
			}
			maxElement(_head)->_rNode = this;
			minElement(_head)->_lNode = this;
			return (res);
		}
		void                					erase(iterator first, iterator last) {
		    iterator    prev;

			while ( first != last ) {
			    prev = first;
			    ++first;
			    erase(prev);
			}
		}
		void                					swap(map &x) {
			map buff(*this);

			*this = x;
			x = buff;
			maxElement(_head)->_rNode = this;
			minElement(_head)->_lNode = this;
			maxElement(x._head)->_rNode = this;
			minElement(x._head)->_lNode = this;
		}
		void                					clear() {
			clearMap(&_head);
			_size = 0;
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
		    iterator    res;

			map	*tmp = search_key(_head, k);
			if (!tmp)
			    return (end());
			res = tmp->_data;
			res = this;
			return (res);
		}
		const_iterator							find(const key_type &k) const {
		    iterator    res;

		    map	*tmp = search_key(_head, k);
		    if (!tmp)
		        return (end());
		    res = tmp->_data;
		    res = this;
		    return (res);
		}
		size_type								count(const key_type &k) {
			return ((search_key(_head, k) != 0x0));
		}
		iterator								lower_bound(const key_type &k) {
			for (iterator it = begin(); it != end(); ++it) {
				//pair<key_type, mapped_type>	tmp = *it;
				if (!(_comp(it->first, k)))
				    return (it);
			}
			return (end());
		}
		const_iterator							lower_bound(const key_type &k) const {

			for (iterator it = begin(); it != end(); ++it) {
				//pair<key_type, mapped_type>	tmp = *it;
				if (!(_comp(it->first, k)))
				    return (it);
			}
			return (end());
		}
		iterator								upper_bound(const key_type &k) {
			for (iterator it = begin(); it != end(); ++it) {
				//pair<key_type, mapped_type>	tmp = *it;
				if (!(_comp(it->first, k))) {
				    ++it;
				    return (it);
				}
			}
			return (end());
		}
		const_iterator							upper_bound(const key_type &k) const {
			for (iterator it = begin(); it != end(); ++it) {
				//pair<key_type, mapped_type>	tmp = *it;
				if (!(_comp(it->first, k))) {
				    ++it;
				    return (it);
				}
			}
			return (end());
		}
		pair<const_iterator, const_iterator>	equal_range(const key_type &k) const {
			pair<const_iterator, const_iterator>	res;

			res.first = lower_bound(k);
			res.second = upper_bound(k);
			return (res);
		}
		pair<iterator, iterator>				equal_range(const key_type &k) {
			pair<iterator, iterator>	res;

			res.first = lower_bound(k);
			res.second = upper_bound(k);
			return (res);
		}
		allocator_type							get_allocator() const {
			return (_alloc);
		}
		~map() { clear(); }
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
				if ((*head)->_data->first > key)
					addElement(&(*head)->_lNode, key);
				else
					addElement(&(*head)->_rNode, key);
			}
		}
		void									clearMap(map **head) {
			if (*head && *head != this) {
				clearMap(&(*head)->_lNode);
				clearMap(&(*head)->_rNode);
				_inAlloc.destroy((*head)->_data);
				_inAlloc.deallocate((*head)->_data, 1);
				_allocMap.destroy(*head);
				_allocMap.deallocate(*head, 1);
				*head = 0x0;
			}
		}
		vector<map<key_type, mapped_type> *> 	iterativeInorder(map *head) {
			map										*tmp = head;
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
				if ((*head)->_data->first > k)
					deleteElement(&(*head)->_lNode, k);
				else if ((*head)->_data->first < k)
					deleteElement(&(*head)->_rNode, k);
				else {
					if (!(*head)->_lNode) {
						tmp = *head;
						*head = (*head)->_rNode;
						_inAlloc.destroy(tmp->_data);
						_inAlloc.deallocate(tmp->_data, 1);
						_allocMap.destroy(tmp);
						_allocMap.deallocate(tmp, 1);
						tmp = 0x0;
					} else if (!(*head)->_rNode) {
						tmp = *head;
						*head = (*head)->_lNode;
						_inAlloc.destroy(tmp->_data);
						_inAlloc.deallocate(tmp->_data, 1);
						_allocMap.destroy(tmp);
						_allocMap.deallocate(tmp, 1);
						tmp = 0x0;
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
