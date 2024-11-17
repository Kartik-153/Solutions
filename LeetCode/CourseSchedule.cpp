#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> schedule;
        if(numCourses <= 0) return false;

        vector<int> steps(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(auto& prereq: prerequisites) {
            int parent = prereq[0];
        int child = prereq[1];
        graph[parent].push_back(child);
        steps[child]++;
        }

        queue<int> sources;
        for(int i = 0; i < numCourses; i++) {
            if(steps[i] == 0) {
                sources.push(i);
            }
        }

        while (!sources.empty()) {
        int vertex = sources.front();
        sources.pop();
        schedule.push_back(vertex);

        for (int child : graph[vertex]) {
            steps[child]--; 
            if (steps[child] == 0) {
                sources.push(child);
            }
        }
        }
        return schedule.size() == numCourses;
    
    }
};