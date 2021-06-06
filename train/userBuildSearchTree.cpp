/*Build user-defined input search tree */
#include <iostream>
#include "../ft_queue.hpp"
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

template <class T>struct		userTree {
		userTree( ) : _size(0) { }
    	T           			data;
    	userTree    			*leftNode;
    	userTree    			*rightNode;
		size_t					getSize();
		size_t					getTreeHeight(userTree<T> *head);
		bool                    findElement(userTree<T> *head, T const &val);
	private:
        size_t		            countNodes(userTree<T> *head);
		size_t					_size;
};

template<class T>size_t		userTree<T>::countNodes(userTree<T> *head) {
	if (!head)
		return (0);
	else 
		return (1 + head->countNodes(head->leftNode)
			+ head->countNodes(head->rightNode));
}

template<class T>size_t 	   userTree<T>::getSize() {
    _size = this->countNodes(this);
    return (_size);
}

template<class T>void    		pushBack(userTree<T> **head, T &data) {
    if (!(*head)) {
        *head = new userTree<T>;
        (*head)->data = data;
        (*head)->leftNode = NULL;
        (*head)->rightNode = NULL;
    } else {
        if ((*head)->data > data)
            pushBack(&(*head)->leftNode, data);
        else
            pushBack(&(*head)->rightNode, data);
    }
}

template<class T>void			userInsert(userTree<T> **head) {
	T	data;
	
    std::cout << "Input data: ";
    std::cin >> data;
    pushBack(head, data);
}

template<class T>size_t			userTree<T>::getTreeHeight(userTree<T> *head) {
	static size_t	leftTSize;
	static size_t	rightTSize;
	
	if (!head)
		return (0);
	leftTSize = getTreeHeight(head->leftNode);
	rightTSize = getTreeHeight(head->rightNode);
	return (std::max(leftTSize, rightTSize) + 1);
}

template<class T>std::ostream	&operator<<(std::ostream &o, userTree<T> &head) {
	ft::queue<userTree<T> *>    obj;
    std::vector<userTree<T> *>  tmpVector;
    userTree<T>                 *tmpNode;
    size_t                      space;
    size_t						tmp;

	obj.push(&head);
	while (!obj.empty()) {
	    tmpVector.push_back(obj.front());
		if (obj.front()->leftNode)
			obj.push(obj.front()->leftNode);
		if (obj.front()->rightNode)
			obj.push(obj.front()->rightNode);
		obj.pop();
	}
    typename std::vector<userTree<T> *>::iterator	it = tmpVector.begin();
    for (size_t i = 0; i < head.getTreeHeight(&head); ++i) {
		space = static_cast<size_t>(pow(2, i));
       	tmp = head.getSize() - space;
		for (size_t j = 0; j < tmp; ++j)
			o << ' ';
		for (size_t j = 0; j < space; ++j) {
			if (it == tmpVector.end()) {
				o << std::endl;
				return (o);
			}
			tmpNode = *(it++);
			o << tmpNode->data << ' ';
		}
		o << std::endl;
    }
    return (o);
}

template<class type>void	printGraphTree(userTree<type> *obj, size_t size) {
	if (!obj)
		return ;
	else {
		printGraphTree(obj->rightNode, size + 5);
		for (size_t i = 0; i < size; ++i)
			std::cout << ' ';
		std::cout << obj->data << std::endl;
		printGraphTree(obj->leftNode, size + 5);
	}
}

template<class T>bool       userTree<T>::findElement(userTree<T> *head, const T &val) {
	if (!head)
		return (false);
	if (head->data == val)
		return (true);
	if (head->data > val)
		return (findElement(head->leftNode, val));
	else
		return (findElement(head->rightNode, val));
}

int main(void) {
	srand(time(NULL));
	
	userTree<int>	*searchTree = NULL;
	size_t			count = rand() % 10 + 1;
	std::cout << "Number of nodes of binary tree: " << count << std::endl;
	for (size_t i = 0; i < count; ++i)
		userInsert(&searchTree);
	//std::cout << *searchTree;
	printGraphTree(searchTree, 5);
	std::cout << std::boolalpha << "If element 7 in tree: " << searchTree->findElement(searchTree, 7)
		<< std::endl;
	return (0);
}