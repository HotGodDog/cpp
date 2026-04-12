#include "Graph.h"
#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    Node A("A"), B("B"), C("C"), D("D"), E("E"), F("F");

    Graph g;
    g.addNode(&A);
    g.addNode(&B);
    g.addNode(&C);
    g.addNode(&D);
    g.addNode(&E);
    g.addNode(&F);

    g.addEdge(&A, &B);
    g.addEdge(&B, &C);
    g.addEdge(&D, &E);

    BFS bfs(g);
    DFS dfs(g);

    cout << "BFS connected(A, C): " << bfs.connected(&A, &C) << endl;
    cout << "DFS connected(A, C): " << dfs.connected(&A, &C) << endl;

    cout << "\nBFS connected(A, D): " << bfs.connected(&A, &D) << endl;
    cout << "DFS connected(A, D): " << dfs.connected(&A, &D) << endl;

    cout << "\nBFS connected(D, E): " << bfs.connected(&D, &E) << endl;
    cout << "DFS connected(D, E): " << dfs.connected(&D, &E) << endl;

    cout << "\nBFS connected(F, F): " << bfs.connected(&F, &F) << endl;
    cout << "DFS connected(F, F): " << dfs.connected(&F, &F) << endl;

    g.removeEdge(&B, &C);
    cout << "\nBFS connected(A, C) после удаления ребра (B, C): " << bfs.connected(&A, &C) << endl;
    cout << "DFS connected(A, C) после удаления ребра (B, C): " << dfs.connected(&A, &C) << endl;

    g.removeNode(&B);
    cout << "\nBFS connected(A, B) после удаления вершины B: " << bfs.connected(&A, &B) << endl;
    cout << "DFS connected(A, B) после удаления вершины B: " << dfs.connected(&A, &B) << endl << endl;

    for (Graph::node_iterator it = g.begin(); it != g.end(); ++it) {
        cout << (*it)->getName() << " ";
    }
    cout << endl;

    return 0;
}