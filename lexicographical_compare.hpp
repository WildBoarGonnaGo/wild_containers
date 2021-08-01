//
// Created by lchantel on 25.07.2021.
//

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP
#include "iterator.hpp"

namespace ft {
    struct false_type {
        static const bool value = false;
        bool operator()() const{ return value; }
        // There is more here, but it doesn't really matter for your question
    };
    struct true_type {
        static const bool value = true;
        bool operator()() const{ return value; }
        // There is more here, but it doesn't really matter for your question
    };
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };
    template< typename T > struct  is_integral : public false_type { };
    template<> struct  is_integral< bool > : public true_type { };
    template<> struct  is_integral< char > : public true_type{ };
    template<> struct  is_integral< wchar_t > : public true_type { };
    template<>struct  is_integral< short > : public true_type { };
    template<>struct  is_integral< int > : public true_type { };
    template<>struct  is_integral< long > : public true_type{ };
    template<>struct  is_integral< unsigned long > : public true_type{ };
    template<>struct  is_integral< long long > : public true_type { };

	template<class InputIterator1, class InputIterator2>
	bool    lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif //FT_CONTAINERS_LEXICOGRAPHICAL_COMPARE_HPP
