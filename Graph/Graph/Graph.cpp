#include "Graph.h"
#include <queue>

// Helper: parse positive integer from C-string manually
// Returns -1 if no digits found
static int parseInt(const char* str)
{
    int result = 0;
    bool hasDigits = false;

    // Skip leading whitespace
    while (*str == ' ' || *str == '\t') str++;

    // Parse digits
    while (*str >= '0' && *str <= '9') {
        hasDigits = true;
        result = result * 10 + (*str - '0');
        str++;
    }

    return hasDigits ? result : -1;
}

// Constructor: build graph from a file containing edge list
// File format: "Source Target" header, then pairs of integers per line
Graph::Graph(const char* file_name)
{
    ifstream file(file_name);
    if (!file.is_open()) {
        return;
    }

    // Buffer for reading lines
    const int BUFFER_SIZE = 256;
    char line[BUFFER_SIZE];

    // Skip the header line
    file.getline(line, BUFFER_SIZE);

    // First pass: find the maximum node ID to size the lookup vector
    int maxId = -1;

    // Temporary storage for edges
    vector<pair<int, int>> edges;

    while (file.getline(line, BUFFER_SIZE)) {
        // Skip empty lines
        if (line[0] == '\0') continue;

        // Parse two integers from the line
        char* ptr = line;
        int sourceId = parseInt(ptr);
        if (sourceId < 0) continue;

        // Move pointer past first number and whitespace
        while (*ptr >= '0' && *ptr <= '9') ptr++;
        int targetId = parseInt(ptr);
        if (targetId < 0) continue;

        edges.push_back(make_pair(sourceId, targetId));

        if (sourceId > maxId) maxId = sourceId;
        if (targetId > maxId) maxId = targetId;
    }

    file.close();

    // Resize lookup vector for O(1) access by ID
    if (maxId >= 0) {
        nodesById.resize(maxId + 1, nullptr);
    }

    // Second pass: create nodes and add edges
    for (const auto& edge : edges) {
        int sourceId = edge.first;
        int targetId = edge.second;

        Node* source = findNode(sourceId);
        if (!source) {
            source = new Node(sourceId);
            addNode(source);
        }

        Node* target = findNode(targetId);
        if (!target) {
            target = new Node(targetId);
            addNode(target);
        }

        addEdge(source, target);
    }
}

// Destructor: delete all dynamically allocated nodes
Graph::~Graph()
{
    for (Node* node : nodes) {
        delete node;
    }
    nodes.clear();
    nodesById.clear();
}

void Graph::addNode(Node* node)
{
    if (node && nodes.find(node) == nodes.end()) {
        nodes.insert(node);
        int id = node->getId();
        if (id >= (int)nodesById.size()) {
            nodesById.resize(id + 1, nullptr);
        }
        nodesById[id] = node;
    }
}

void Graph::removeNode(Node* node)
{
    if (!node || nodes.find(node) == nodes.end())
        return;

    for (Node* neighbour : node->neighbours)
        neighbour->removeNeighbour(node);

    node->neighbours.clear();
    nodesById[node->getId()] = nullptr;
    nodes.erase(node);
    delete node;
}

void Graph::addEdge(Node* begin, Node* end)
{
    if (begin == end)
        return;

    if (nodes.find(begin) == nodes.end())
        return;

    if (nodes.find(end) == nodes.end())
        return;

    begin->addNeighbour(end);
    end->addNeighbour(begin);
}

void Graph::removeEdge(Node* begin, Node* end)
{
    if (!begin || !end)
        return;

    if (nodes.find(begin) == nodes.end())
        return;

    if (nodes.find(end) == nodes.end())
        return;

    begin->removeNeighbour(end);
    end->removeNeighbour(begin);
}

// Find a node by its ID using O(1) vector lookup
Node* Graph::findNode(int id) const
{
    if (id >= 0 && id < (int)nodesById.size())
        return nodesById[id];
    return nullptr;
}

void Node::addNeighbour(Node* neighbour)
{
    if (neighbour) neighbours.insert(neighbour);
}

void Node::removeNeighbour(Node* neighbour)
{
    if (neighbour) neighbours.erase(neighbour);
}

// BFS: check if two nodes are connected by a path
bool BFS::connected(Node* begin, Node* end)
{
    if (!begin || !end)
        return false;

    if (begin == end)
        return true;

    queue<Node*> q;
    q.push(begin);
    set<Node*> visited;
    visited.insert(begin);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        for (Node::node_iterator it = current->nb_begin(); it != current->nb_end(); ++it) {
            Node* neighbour = *it;

            if (neighbour == end)
                return true;

            if (visited.find(neighbour) == visited.end()) {
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
    return false;
}

// BFS: get all nodes in the same connected component as the start node
set<Node*> BFS::getComponent(Node* start)
{
    set<Node*> component;
    if (!start)
        return component;

    queue<Node*> q;
    q.push(start);
    component.insert(start);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        for (Node::node_iterator it = current->nb_begin(); it != current->nb_end(); ++it) {
            Node* neighbour = *it;
            if (component.find(neighbour) == component.end()) {
                component.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
    return component;
}

// DFS: check if two nodes are connected by a path
bool DFS::connected(Node* begin, Node* end)
{
    if (!begin || !end)
        return false;

    visited.clear();
    return connectedRecursive(begin, end);
}

bool DFS::connectedRecursive(Node* begin, Node* end)
{
    if (begin == end)
        return true;

    visited.insert(begin);

    for (Node::node_iterator it = begin->nb_begin(); it != begin->nb_end(); ++it) {
        Node* neighbour = *it;
        if (visited.find(neighbour) == visited.end()) {
            if (connectedRecursive(neighbour, end))
                return true;
        }
    }
    return false;
}