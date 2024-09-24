#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Min-heap to store projects by their capital requirements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap;

        // Max-heap to store projects by their profits
        priority_queue<pair<int, int>> maxProfitHeap;

        // Insert all project capitals into the min-heap
        for(int i = 0; i < capital.size(); i++) {
            minCapitalHeap.push({capital[i], i});
        }

        int availableCapital = w;

        // Try to select the best 'numberOfProjects'(k) projects
        for(int i = 0; i < k; i++) {
            // Find all projects that can be completed with the available capital and move them to the max-heap
            while(!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
                int projectIndex = minCapitalHeap.top().second;
                minCapitalHeap.pop();
                maxProfitHeap.push({profits[projectIndex], projectIndex});
            }

            // If no projects can be completed, break
            if (maxProfitHeap.empty()) {
                break;
            }

            // Select the project with the maximum profit
            availableCapital += maxProfitHeap.top().first;
            maxProfitHeap.pop();
        }

        return availableCapital;
    }
};