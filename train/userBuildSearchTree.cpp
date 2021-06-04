/*Build user-defined input search tree */
#include <iostream>
#include "../ft_queue.hpp"

template <class T>struct		userTree {
		userTree( ) : _size(0) { }
    	T           			*data;
    	userTree    			*leftNode;
    	userTree    			*rightNode;
		size_t const			getSize() const { return (_size); }
		size_t					setSize();
	private:
		size_t					_size;
};

template<class T>struct			userQueue {
	T							*data;
	userQueue					*next;

};

template<class T>size_t			userTree<T>::setSize() {
	if (!this)
		return (0);
	else 
		return (1 + this->leftNode->setSize()
			+ this->rightNode->setSize());
}

template<class T>void    		pushBack(userTree<T> **head, T &data) {
    if (!(*head)) {
        *head = new userTree<T>;
        (*head)->data = data;
        (*head)->leftNode = nullptr;
        (*head)->rightNode = nullptr;
    } else {
        if ((*head)->data > data)
            pushBack(&(*head)->leftNode);
        else
            pushBack(&(*head)->rightNode);
    }
}

template<class T>void			insert(userTree<T> **head, T data) {
    std::cout << "Input data: ";
    std::cin >> data;
    pushBack(head, data);
}

template<class T>std::ostream	&operator<<(std::ostream &o, userTree<T> const &head) {
	if (&head) {
		for (size_t i = 0; i < head->getSize(); i++)
			o << ' ';
		o << head->data; 
		return (operator<<(o, head->leftNode));
	}
}