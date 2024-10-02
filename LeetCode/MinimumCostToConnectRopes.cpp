#include<bits/stdc++.h>
using namespace std;

int minimumCostToConnectRopes(vector<int>& ropes) {
    if(ropes.size() == 1) return 0;
    
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());

    int totalCost = 0;

    while(minHeap.size() > 1) {
        int firstRope = minHeap.top();
        minHeap.pop();

        int secondRope = minHeap.top();
        minHeap.pop();

        int currentCost = firstRope + secondRope;
        totalCost += currentCost;

        minHeap.push(currentCost);
    }
    return totalCost;
}

int main() {

    vector<int> ropes3 = {1, 3, 11, 5};
    cout << "Minimum cost to connect ropes: " << minimumCostToConnectRopes(ropes3) << endl;
    
    return 0;
}