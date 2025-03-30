#include <bits/stdc++.h>
using namespace std;

class GraphMatrix {
private:
    vector<vector<int>> adjMatrix;
    int vertices;

public:
    GraphMatrix(int v) : vertices(v) {
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << ' ';

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

class GraphList {
private:
    vector<vector<int>> adjList;
    int vertices;

public:
    GraphList(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Assuming an undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int vertices = 5;
    GraphMatrix gm(vertices);
    gm.addEdge(0, 1);
    gm.addEdge(0, 2);
    gm.addEdge(1, 3);
    gm.addEdge(1, 4);
    gm.addEdge(2, 4);

    cout << "BFS using Adjacency Matrix: ";
    gm.BFS(0);
    cout << endl;

    GraphList gl(vertices);
    gl.addEdge(0, 1);
    gl.addEdge(0, 2);
    gl.addEdge(1, 3);
    gl.addEdge(1, 4);
    gl.addEdge(2, 4);

    cout << "BFS using Adjacency List: ";
    gl.BFS(0);
    cout << endl;

    return 0;
}
