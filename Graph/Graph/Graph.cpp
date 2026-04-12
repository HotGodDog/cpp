#include "Graph.h"
#include <queue>


void Graph::addNode(Node* node)
{
    if (node) nodes.insert(node);
}

void Graph::removeNode(Node* node)
{
    if (!node || nodes.find(node) == nodes.end())
        return;

    for (Node* neighbour : node->neighbours)
        neighbour->removeNeighbour(node);

    node->neighbours.clear();
    nodes.erase(node);
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


void Node::addNeighbour(Node* neighbour)
{
    if (neighbour) neighbours.insert(neighbour);
}

void Node::removeNeighbour(Node* neighbour)
{
    if (neighbour) neighbours.erase(neighbour);
}


bool BFS::connected(Node* begin, Node* end)
{
    if (!begin || !end)
        return false;

    queue<Node*> nodes;
    nodes.push(begin);
    set<Node*> visited;

    while (!nodes.empty())
    {
        Node* next = nodes.front();
        nodes.pop();

        if (next == end)
            return true;

        visited.insert(next);

        for (Node::node_iterator it = next->nb_begin(); it != next->nb_end(); it++)
            if (visited.find(*it) == visited.end())
                nodes.push(*it);
    }
    return false;
}

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

    for (Node::node_iterator it = begin->nb_begin(); it != begin->nb_end(); it++)
        if (visited.find(*it) == visited.end())
            if (connectedRecursive(*it, end))
                return true;

    return false;
}