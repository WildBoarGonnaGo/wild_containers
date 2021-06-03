#include <iostream>
#include <ctime>
#include <cstdlib>

template<class T> struct Tree {
	T 			data;
	Tree<T>		*left;
	Tree<T>		*right;
};

template<class type>
Tree<type>	*balancing_tree(type *arr, size_t size, size_t *count) {
	Tree<type>			*res;
	size_t				rNodeSize;
	size_t				lNodeSize;		

	if (!size)
		return (nullptr);
	else {
		res = new Tree<type>;
		lNodeSize = size / 2;
		rNodeSize = size - lNodeSize - 1;
		res->data = *(arr + *count);
		++*count;
		res->left = balancing_tree(arr, lNodeSize, count);
		res->right = balancing_tree(arr, rNodeSize, count);
		return (res);
	}
}

template<class type>
void		outputTree(Tree<type> *target, size_t size) {
	if (!target)
		return ;
	else {
		outputTree(target->right, size + 5);
		for (size_t i = 0; i < size; i++)
			std::cout << ' ';
		std::cout << target->data << std::endl;
		outputTree(target->left, size + 5);
	}
}

template<class type>
void		destroyTree(Tree<type> *target) {
	if (target) {
		destroyTree(target->left);
		destroyTree(target->right);
		delete target;
	}
}

template<class type>
void	countRoll(Tree<type> *target, size_t &count) {
	if (!target) {
		--count;
		return ;
	} else {
		++count;
		countRoll(target->left, count);
		countRoll(target->right, count);
	}
}

template<class type>
size_t	countElements(Tree<type> *target) {
	size_t count;

	countRoll(target, count);
	return (++count);
}

template<class type>
int	countNodes(Tree<type> *target) {
	if (!target)
		return (0);
	else {
		return (1 + countNodes(target->left)
			+ countNodes(target->right));
	}
}

template<class type>
size_t		countLeafs(Tree<type> *target) {
	if (!target)
		return (0);
	else {
		if (!target->left && !target->right)
			return (1);
		else
			return (countLeafs(target->left)
				+ countLeafs(target->right));
	}
}

template<class type>
void	treeElementsSum(Tree<type> *target, type &res) {
	if (!target)
		return ;
	else {
		treeElementsSum(target->left, res);
		treeElementsSum(target->right, res);
		res += target->data;
	}
}

template<class type>
bool	treeBalanceStatus(Tree<type> *target) {
	if (!target)
		return (true);
	else {
		if (abs(countNodes(target->left) - countNodes(target->right)) > 1)
			return (false);
		else return (treeBalanceStatus(target->left)
			&& treeBalanceStatus(target->right));
	}
}

int main(void) {
	srand(time(NULL));

	size_t		arrSize = rand() % 20;
	int			*arr = new int[arrSize];
	Tree<int>	*res;
	size_t		count = 0;
	int			sum = 0;

	std::cout << "Array output: ";
	for (size_t i = 0; i < arrSize; i++) {
		arr[i] = rand() % 43;
		std::cout << arr[i] << ' ';	
	}
	std::cout << std::endl;
	std::cout << "Tree output:" << std::endl;
	res = balancing_tree<int>(arr, arrSize, &count);
	outputTree<int>(res, arrSize);
	std::cout << "Number of elements: " << countNodes(res) << std::endl;
	std::cout << "Number of leafs: " << countLeafs<int>(res)
		<< std::endl; 
	treeElementsSum<int>(res, sum);
	std::cout << "Sum of elements of tree: " << sum << std::endl;
	std::cout << std::boolalpha << "Is tree balanced: "
		<< treeBalanceStatus<int>(res) << std::endl;
	destroyTree<int>(res);
	delete [] arr;
}