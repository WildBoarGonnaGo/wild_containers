/*Build user-defined input search tree */
#include <iostream>
#include "../ft_queue.hpp"
#include <vector>

template <class T>struct		userTree {
		userTree( ) : _size(0) { }
    	T           			*data;
    	userTree    			*leftNode;
    	userTree    			*rightNode;
		size_t const			getSize() const { return (_size); }
	private:
        size_t const            countNodes() const;
		size_t					_size;
};

template<class T>size_t			userTree<T>::countNodes() {
	if (!this)
		return (0);
	else 
		return (1 + this->leftNode->setSize()
			+ this->rightNode->setSize());
}

template<class T>size_t const   userTree<T>::getSize() const {
    _size = this->countNodes();
    return (_size);
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
        ft::queue<userTree<T> *>    obj;
        std::vector<userTree<T> *>  tmpVector;

        obj.push(&head);
        while (!obj.empty()) {
            tmpVector.push_back(obj.front());
            obj.pop;
            if (obj.front()->leftNode)
                obj.push(obj.front()->leftNode);
            if (obj.front()->rightNode)
                obj.push(obj.front()->rightNode);
        }
        for (int i = 0; ; ++i) {
            size_
        }
	}
}