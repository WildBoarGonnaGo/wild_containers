#include <iostream>
#include <list>

class Graph {
		//Number of verticies
		int _v;
		//pointer to adjacency list
		std::list<int>	*_adj;
	public:
		//Contructor prototype
		Graph(int v);
		//Method to add an edge
		void	addEdge(int v, int w);
		//Method for BFS traversal give a source "s"
		void	BFS(int s);
};

Graph::Graph(int v) : _v(v) {
	/*
	_v(v) - set number of verticies
	Let's create new adjacency list
	*/
	_adj = new std::list<int>(_v);
}

//Implementation of method to add edges
void	Graph::addEdge(int v, int w) {
	_adj[v].push_back(w);
}

//Perform BFS given a starting vertex
void	Graph::BFS(int s) {
	//Start with all verticies as not visited
	bool	*visited = new bool[_v];
	for (size_t i = 0; i < _v; i++)
		visited[i] = false;
	//Create a queue for BFS
	std::list<int>	queue;
	//
	visited[s] = true;
	queue.push_back(s);
	//Continue until queue is empty 
	while (!queue.empty()) {
		//Get the front of the queue and remove it
		std::cout << "Checking adjacent vecricies for vertex: "
			<< s << std::endl;
		for (auto i = _adj[s].begin(); i != _adj[s].end(); ++i) {
			//We only care about nodes not visited yet
			if (!visited[*i]) {
				//Mark as visited
				std::cout << "Visit and enqueue: "
					<< *i << std::endl;
				visited[*i] = true;
				//Push 
			}
		}
	}
}

