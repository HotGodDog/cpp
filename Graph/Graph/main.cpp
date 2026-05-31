#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

// Constant input filename
//const char* INPUT_FILE = "testgraph.txt";
const char* INPUT_FILE = "1000.csv";

// Helper: convert integer to char array (filename)
// Returns length of written string
static int intToStr(int num, char* buf);

// Write one component to file with numeric name (1.txt, 2.txt, ...)
static void writeComponent(const Graph& graph, const set<Node*>& component, int fileNum);

// Find all connected components and write each to separate file
static int splitComponents(const Graph& graph);

// Count isolated nodes: IDs in [0, maxId] that are not in the graph
// These are nodes that never appeared in any edge of the input file
static int countIsolatedNodes(const Graph& graph);

int main()
{
    Graph g(INPUT_FILE);

    int components = splitComponents(g);
    int isolated = countIsolatedNodes(g);
    int totalNodes = (int)g.getNodesCount() + isolated;

    // Output statistics to CONSOLE (not to file)
    cout << "Input file:      " << INPUT_FILE << endl;
    cout << "Total nodes:     " << totalNodes << endl;
    cout << "Nodes in graph:  " << g.getNodesCount() << endl;
    cout << "Isolated nodes:  " << isolated << endl;
    cout << "Isolated graphs: " << components << endl;

    return 0;
}

static int intToStr(int num, char* buf)
{
    if (num == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }

    int temp = num;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    for (int i = digits - 1; i >= 0; i--) {
        buf[i] = '0' + (temp % 10);
        temp /= 10;
    }
    buf[digits] = '\0';
    return digits;
}

static void writeComponent(const Graph& graph, const set<Node*>& component, int fileNum)
{
    char filename[16];
    int len = intToStr(fileNum, filename);
    filename[len] = '.';
    filename[len + 1] = 't';
    filename[len + 2] = 'x';
    filename[len + 3] = 't';
    filename[len + 4] = '\0';

    ofstream out(filename);
    if (!out.is_open()) return;

    out << "Source\tTarget" << endl;

    set<pair<int, int>> written;
    for (Node* node : component) {
        for (Node::node_iterator it = node->nb_begin(); it != node->nb_end(); ++it) {
            Node* nb = *it;
            int a = node->getId();
            int b = nb->getId();
            if (a < b) {
                pair<int, int> e = make_pair(a, b);
                if (written.find(e) == written.end()) {
                    written.insert(e);
                    out << a << "\t" << b << endl;
                }
            }
        }
    }
}

static int splitComponents(const Graph& graph)
{
    set<Node*> unvisited;
    for (Graph::node_iterator it = graph.begin(); it != graph.end(); ++it) {
        unvisited.insert(*it);
    }

    BFS bfs(graph);
    int fileNum = 1;

    while (!unvisited.empty()) {
        Node* start = *unvisited.begin();
        set<Node*> comp = bfs.getComponent(start);

        writeComponent(graph, comp, fileNum);
        fileNum++;

        for (Node* node : comp) {
            unvisited.erase(node);
        }
    }

    return fileNum - 1;  // total components written
}

static int countIsolatedNodes(const Graph& graph)
{
    if (graph.getNodesCount() == 0) return 0;

    // Find maximum node ID in the graph
    int maxId = -1;
    for (Graph::node_iterator it = graph.begin(); it != graph.end(); ++it) {
        int id = (*it)->getId();
        if (id > maxId) maxId = id;
    }

    // Count how many IDs in [0, maxId] are missing from the graph
    int isolated = 0;
    for (int id = 0; id <= maxId; id++) {
        if (graph.findNode(id) == nullptr) {
            isolated++;
        }
    }

    return isolated;
}