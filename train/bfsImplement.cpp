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

void	Graph::BFS(int s) {
	std::list<int>	tmp;
	bool			visit[_v] = { false };
	
	visit[s]
}

