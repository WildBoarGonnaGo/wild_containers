//
// Created by lchantel on 25.07.2021.
//

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP
#include "iterator.hpp"

namespace ft {
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
