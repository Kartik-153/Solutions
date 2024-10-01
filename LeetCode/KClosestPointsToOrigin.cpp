#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;

        for(auto point : points) {
            int currDist = calculateDistance(point);

            maxHeap.push({currDist, point});

            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        } 

        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }

private:
    int calculateDistance(vector<int>& point) {
        return pow(point[0], 2) + pow(point[1], 2);
    }
};