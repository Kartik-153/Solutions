#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        for(auto edge: edges) {
            vector<bool> visited(n, false);
            if(isConnected(edge[0] - 1, edge[1] - 1, visited, adj)) {
                return edge;
            }

            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        return {};
    }
private:
    bool isConnected(int src, int target, vector<bool>& visited, vector<int> adj[]) {
        visited[src] = true;

        if(src == target) {
            return true;
        }

        int isFound = false;
        for(int _adj: adj[src]) {
            if(!visited[_adj]) {
                isFound = isFound || isConnected(_adj, target, visited, adj);
            }
        }
        return isFound;
    }
};