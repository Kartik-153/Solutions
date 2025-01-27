#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (const auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
        }
        unordered_map<int, unordered_set<int>> prereqMap;
        function<unordered_set<int>(int)> dfs =
            [&](int course) -> unordered_set<int> {
            if (prereqMap.find(course) == prereqMap.end()) {
                prereqMap[course] = {};
                for (int pre : adj[course]) {
                    auto result = dfs(pre);
                    prereqMap[course].insert(result.begin(), result.end());
                }
            }
            prereqMap[course].insert(course);
            return prereqMap[course];
        };
        for (int i = 0; i < numCourses; ++i) {
            dfs(i);
        }
        vector<bool> res;
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            res.push_back(prereqMap[v].count(u) > 0);
        }

        return res;
    }
};
