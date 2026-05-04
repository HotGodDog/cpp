#include "Graph.h"
#include <queue>


void Graph::addNode(Node* node)
{
    if (node) nodes.insert(node);
}

void Graph::removeNode(Node* node)
{
    // Проверка на наличие вершины в графе
    if (!node || nodes.find(node) == nodes.end())
        return;

    // Удаляем у соседей связи с удаляемой вершиной
    for (Node* neighbour : node->neighbours)
        neighbour->removeNeighbour(node);

    node->neighbours.clear();
    nodes.erase(node);
}

void Graph::addEdge(Node* begin, Node* end)
{
    // Нельзя добавить петлю
    if (begin == end)
        return;

    // Проверка вершин на принадлежность к графу
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

    // Проверка вершин на принадлежность к графу
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

    queue<Node*> nodes;     // Очередь непосещенных вершин
    nodes.push(begin);
    set<Node*> visited;     // Посещеные вершины

    // Пока есть непосещенные вершины
    while (!nodes.empty())
    {
        Node* next = nodes.front();
        nodes.pop();

        // Если нашли искомую вершину
        if (next == end)
            return true;

        visited.insert(next);

        // Перебираем всех соседей текущей вершины
        for (Node::node_iterator it = next->nb_begin(); it != next->nb_end(); it++)

            // Если сосед еще не посещен добавляем его в очередь
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

    // Рекурсивно обходим всех непосещённых соседей
    for (Node::node_iterator it = begin->nb_begin(); it != begin->nb_end(); it++)

        // Если сосед ещё не был посещён то ищем путь от этого соседа до end
        if (visited.find(*it) == visited.end())
            if (connectedRecursive(*it, end))
                return true;

    return false;
}