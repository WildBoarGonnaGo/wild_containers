//
// Created by lchantel on 25.07.2021.
//

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
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
		bool    operator==(pair<T1, T2> &lhs, pair<T1, T2> &rhs) {
			return (lhs.first = rhs.first && lhs.second = rhs.second);
		}
		bool    operator!=(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (!(lhs == rhs)); }
		bool    operator<(pair<T1, T2> &lhs, pair<T1, T2> &rhs) {
			return (lhs.first < rhs.frst || (!(lhs.first < rhs.first) && lhs.second < rhs.second))
		}
		bool    operator<=(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (!(rhs < lhs)); }
		bool    operator>(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (lhs < rhs); }
		bool    operator>=(pair<T1, T2> &lhs, pair<T1, T2> &rhs) { return (!(lhs < rhs)); }
		T1  first;
		T2  second;
	};
	template<class T1, class T2>
	pair<T1, T2>    make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }
	template<class Key, class T>
}

#endif //FT_CONTAINERS_MAP_HPP
