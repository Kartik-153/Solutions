#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int s) {
    int V = adj.size();
    vector<int> res;
    queue<int> q;
    vector<bool> visited(V, false);
    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for(int x: adj[curr]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}

int main()  {

    vector<vector<int>> adj = { {2, 3, 1}, {0},
                                {0, 4}, {0}, {2}};
    int src = 0;
    vector<int> ans = bfs(adj, src);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}