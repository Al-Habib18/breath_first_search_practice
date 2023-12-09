#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int v) {
        vertices = v;
        adjacencyList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // For undirected graph
    }

    void bfs(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    q.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    Graph graph(6); // Create a graph with 6 vertices

    graph.addEdge(0, 1);   
    graph.addEdge(0, 2);    
    graph.addEdge(1, 3);    
    graph.addEdge(1, 4);    
    graph.addEdge(2, 4);         
    graph.addEdge(3, 5);           
    graph.addEdge(4, 5);    

    cout << "BFS starting from vertex 0: ";
    graph.bfs(0);
    cout << endl ;
    return 0;
}
