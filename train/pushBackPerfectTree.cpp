#include <cstdlib>
#include <iostream>
#include <ctime>

template<class type>
struct graphTree {
	type		data;
	graphTree	*leftNode;
	graphTree	*rightNode;
};

template<class type>size_t	countNodes(graphTree<type> *obj) {
	if (!obj)
		return (0);
	else
		return (1 + countNodes(obj->leftNode) + countNodes(obj->rightNode));
}

template<class type>void	pushBackNode(graphTree<type> **obj, type smpl) {
	if (!*obj) {
		*obj = new graphTree<type>;
		(*obj)->leftNode = nullptr;
		(*obj)->rightNode = nullptr;
		(*obj)->data = smpl;
		return ;
	} else {
		if (countNodes<type>((*obj)->leftNode) > countNodes<type>((*obj)->rightNode))
			pushBackNode(&(*obj)->rightNode, smpl);
		else
			pushBackNode(&(*obj)->leftNode, smpl);
	}
}

template<class type>void	printGraphTree(graphTree<type> *obj, size_t size) {
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

template<class type>void	deleteGraphTree(graphTree<type> *obj) {
	if (obj) {
		deleteGraphTree(obj->leftNode);
		deleteGraphTree(obj->rightNode);
		delete obj;
		obj = nullptr;
	}
}

int main(void) {
	srand(time(NULL));
	
	size_t			graphSize = rand() % 32;
	graphTree<int>	*sample = nullptr;
	
	for (size_t i = 0; i < graphSize; ++i)
		pushBackNode(&sample, rand() % 43);
	std::cout << "Graph tree:" << std::endl;
	printGraphTree(sample,5);
	std::cout << "Graph size: " << countNodes(sample)
		<< std::endl;
	deleteGraphTree<int>(sample);
	return (0);
}

