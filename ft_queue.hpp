#ifndef FT_QUEUE 
# define FT_QUEUE
# include <list>

namespace ft {
	template<class T, class Container = std::list<T> > class queue {
		public:
			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;
			typedef Container						container_type; 
		protected:
			Container c;
		public:
			explicit			queue(const Container& = Container()) { }
			bool				empty() const { return (c.empty()); }
			size_type			size() const { return (c.size()); }
			value_type			&front() { return (c.front()); }
			value_type const	&front() const { return (c.front()); }
			value_type			back() { return (c.back()); }
			value_type const	back() const { return (c.back()); }
			void				push(const value_type &x) { c.push_back(x); }
			void				pop() { c.pop_front(); }
			friend bool			operator==(const queue &x, const queue&y) { return (x.c == y.c); }
			friend bool			operator!=(const queue &x, const queue&y) { return (x.c != y.c); }
			friend bool			operator<(const queue &x, const queue&y) { return (x.c < y.c); }
			friend bool			operator<=(const queue &x, const queue&y) { return (x.c <= y.c)}
			friend bool			operator>(const queue &x, const queue&y) { return (x.c > y.c); }
			friend bool			operator>=(const queue &x, const queue&y) { return (x.c >= y.c); }
	};
}


#endif