#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i, int j, bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}
	void dfsHelper(int node,bool *visited){
		visited[node] = true;
		cout<<node<<",";

		//make a dfs call on all its unvisited neighbours
		for(int nbr : l[node]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
		return;

	}

	void dfs(int source){
		bool *visited = new bool[V]{0};
		dfsHelper(source,visited);
	}
};

void DFSRec(vector<vector<int>>& adj, vector<bool>& visited, int s) {
    visited[s] = true;
    cout << s << " ";
    for(int i: adj[s]) {
        if(visited[i] == false) {
            DFSRec(adj, visited, i);
        }
    }
}

void DFS(vector<vector<int>>& adj, int s) {
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}

void addEdge(vector<vector<int>>& adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main(){
    int V = 5; 
    vector<vector<int>> adj(V);
  
    // Add edges
    vector<vector<int>> edges={{1, 2},{1, 0},{2, 0},{2, 3},{2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    int s = 1; // Starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    DFS(adj, s); // Perform DFS starting from the source vertex

    return 0;
}