//
// Created by lchantel on 28.07.2021.
//

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> > class stack {
	public:
		typedef T          value_type;
		typedef size_t     size_type;
		typedef Container  container_type;
	protected:
		Container c;
	public:
		explicit stack(Container s()) : c(s) { }
		bool                empty() const { return (c.empty()); }
		size_type           size() const { return (c.size()); }
		value_type          &top() { return (c.back()); }
		const value_type    &top() const { return (c.back()); }
		void                push(const value_type &x) { c.push_back(x); }
		void                pop() { c.pop_back(); }
		friend bool operator==(const stack<T, Container>& x,
		                const stack<T, Container>& y) { return (x == y); }
		friend bool operator< (const stack<T, Container>& x,
		                const stack<T, Container>& y) { return (x < y); }
		friend bool operator!=(const stack<T, Container>& x,
		                const stack<T, Container>& y) { return (!(x == y)); }
		friend bool operator> (const stack<T, Container>& x,
		                const stack<T, Container>& y) { return (x > y); }
		friend bool operator>=(const stack<T, Container>& x,
		                const stack<T, Container>& y) { return (x > y || x == y); }
		friend bool operator<=(const stack<T, Container>& x,
		                const stack<T, Container>& y) { return (x < y || x == y); }
	};
}


#endif //FT_CONTAINERS_STACK_HPP
