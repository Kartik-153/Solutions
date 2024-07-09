#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    struct VectorHash {
        std::size_t operator()(const std::vector<int>& v) const {
            std::size_t hash = 0;
            for (int i : v) {
                hash ^= std::hash<int>()(i) + 0x9e3779b9 + (hash << 6) +
                        (hash >> 2);
            }
            return hash;
        }
    };

    struct VectorEqual {
        bool operator()(const std::vector<int>& v1,
                        const std::vector<int>& v2) const {
            return v1 == v2;
        }
    };

    int equalPairs(const std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        unordered_map<vector<int>, int, VectorHash, VectorEqual> rowMap;
        for (const auto& row : grid) {
            rowMap[row]++;
        }
        int count = 0;
        for (int col = 0; col < n; ++col) {
            vector<int> colVector;
            for (int row = 0; row < n; ++row) {
                colVector.push_back(grid[row][col]);
            }
            if (rowMap.find(colVector) != rowMap.end()) {
                count += rowMap[colVector];
            }
        }
        return count;
    }
};
