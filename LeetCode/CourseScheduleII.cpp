#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> sortedList;
        if (numCourses == 0) {
            return {};
        }
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }
        queue<int> sources;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                sources.push(i);
        }
        while (!sources.empty()) {
            int vertex = sources.front();
            sources.pop();
            sortedList.push_back(vertex);
            for (int child : graph[vertex]) {
                inDegree[child]--;
                if (inDegree[child] == 0)
                    sources.push(child);
            }
        }
        if (sortedList.size() < numCourses)
            return {};
        return sortedList;
    }
};
