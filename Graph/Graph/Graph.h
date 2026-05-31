#pragma once

#include <vector>
#include <set>
#include <fstream>

using namespace std;

// Class representing a graph node with integer ID
class Node {
private:
    int id;                     // Node identifier (integer)
    set<Node*> neighbours;      // Set of pointers to adjacent nodes

    void addNeighbour(Node* neighbour);
    void removeNeighbour(Node* neighbour);

public:
    Node(int nodeId) : id(nodeId) {}
    int getId() const { return id; }

    // Iterator over adjacent nodes
    using node_iterator = set<Node*>::const_iterator;
    node_iterator nb_begin() const { return neighbours.begin(); }
    node_iterator nb_end() const { return neighbours.end(); }

    friend class Graph;
};

// Class representing an undirected graph
class Graph {
private:
    set<Node*> nodes;           // Set of pointers to all graph nodes
    vector<Node*> nodesById;    // Vector for O(1) node lookup by ID (index = id)

public:
    Graph() = default;

    // Constructor that builds a graph from an edge list file
    // File format: "Source Target" header, then pairs of integers per line
    Graph(const char* file_name);

    // Destructor: clean up all dynamically allocated nodes
    ~Graph();

    void addNode(Node* node);
    void removeNode(Node* node);
    void addEdge(Node* begin, Node* end);
    void removeEdge(Node* begin, Node* end);

    // Find a node by its ID, return nullptr if not found
    Node* findNode(int id) const;

    // Get the number of nodes in the graph
    size_t getNodesCount() const { return nodes.size(); }

    // Iterator over all graph nodes
    using node_iterator = set<Node*>::const_iterator;
    node_iterator begin() const { return nodes.begin(); }
    node_iterator end() const { return nodes.end(); }
};

// Breadth-First Search class
class BFS {
private:
    const Graph& graph;

public:
    BFS(const Graph& agraph) : graph(agraph) {}

    // Check if two nodes are connected by a path
    bool connected(Node* begin, Node* end);

    // Get all nodes reachable from the start node (connected component)
    set<Node*> getComponent(Node* start);
};

// Depth-First Search class
class DFS {
private:
    const Graph& graph;
    set<Node*> visited;
    bool connectedRecursive(Node* begin, Node* end);

public:
    DFS(const Graph& agraph) : graph(agraph) {}
    bool connected(Node* begin, Node* end);
};