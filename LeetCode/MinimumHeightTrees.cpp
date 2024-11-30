#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 0)
            return {};

        if (n == 1)
            return {0};

        vector<int> steps(n, 0);
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);

            steps[node1]++;
            steps[node2]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (steps[i] == 1)
                leaves.push(i);
        }

        int totalNodes = n;
        while (totalNodes > 2) {
            int leavesSize = leaves.size();
            totalNodes -= leavesSize;

            for (int i = 0; i < leavesSize; i++) {
                int vertex = leaves.front();
                leaves.pop();

                for (auto child : graph[vertex]) {
                    steps[child]--;
                    if (steps[child] == 1)
                        leaves.push(child);
                }
            }
        }

        vector<int> res;
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }

        return res;
    }
};
