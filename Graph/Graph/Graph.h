#pragma once

#include <set>
#include <string>

using namespace std;

class Node {
private:
	string name;
	set<Node*> neighbours;

	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);

public:
	Node(const std::string& aname) : name(aname) {}
	const std::string& getName() const { return name; }

	using node_iterator = set<Node*>::const_iterator;
	node_iterator nb_begin() const { return neighbours.begin(); }
	node_iterator nb_end() const { return neighbours.end(); }

	friend class Graph;
};

class Graph {
private:
	set<Node*> nodes;

public:
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);
	
	using node_iterator = set<Node*>::const_iterator;
	node_iterator begin() const { return nodes.begin(); }
	node_iterator end() const { return nodes.end(); }
};

class BFS {
private:
	const Graph& graph;

public:
	BFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
};

class DFS
{
private:
	const Graph& graph;
	set<Node*> visited;
	bool connectedRecursive(Node* begin, Node* end);

public:
	DFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
};