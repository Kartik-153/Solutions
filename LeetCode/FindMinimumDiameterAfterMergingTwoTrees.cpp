#include<bits/stdc++.h>
using namespace std;

class Solution { // BFS
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameters of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Calculate the longest path that spans across both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum of the three possibilities
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    // Function to find the diameter of a tree using two BFS calls
    int findDiameter(int n, vector<vector<int>>& adjList) {
        // First BFS to find the farthest node from any arbitrary node (e.g., 0)
        auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
        return diameter;
    }

    // BFS helper function to find the farthest node and its distance from the
    // source
    pair<int, int> findFarthestNode(int n, vector<vector<int>>& adjList,
                                    int sourceNode) {
        queue<int> nodesQueue;
        vector<bool> visited(n, false);
        // Push source node into the queue
        nodesQueue.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0, farthestNode = sourceNode;

        // Explore neighbors
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                // Update farthest node
                // The farthest node is the last one that was popped out of the
                // queue.
                farthestNode = currentNode;

                for (int neighbor : adjList[currentNode]) {
                    // Explore neighbors
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
            }
            if (!nodesQueue.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};

class Solution { // DFS
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        int diameter1 =
            findDiameter(adjList1, 0, -1).first;  // Start DFS for Tree 1
        int diameter2 =
            findDiameter(adjList2, 0, -1).first;  // Start DFS for Tree 2

        // Calculate the diameter of the combined tree
        // This accounts for the longest path spanning both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum diameter among the two trees and the combined tree
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Helper function to find the diameter of a tree
    // Returns the diameter and the depth of the node's subtree
    pair<int, int> findDiameter(vector<vector<int>>& adjList, int node,
                                int parent) {
        int maxDepth1 = 0,
            maxDepth2 =
                0;  // Tracks the two largest depths from the current node
        int diameter = 0;  // Tracks the diameter of the subtree

        for (int neighbor :
             adjList[node]) {  // Iterate through neighbors of the current node
            if (neighbor == parent)
                continue;  // Skip the parent to avoid cycles

            // Recursively calculate the diameter and depth of the neighbor's
            // subtree
            auto [childDiameter, depth] = findDiameter(adjList, neighbor, node);

            // Update the maximum diameter of the subtree
            diameter = max(diameter, childDiameter);

            depth++;  // Increment the depth to include the edge to this
                      // neighbor
            // Update the two largest depths from the current node
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }

        // Update the diameter to include the path through the current node
        diameter = max(diameter, maxDepth1 + maxDepth2);

        return {diameter, maxDepth1};
    }
};


class Solution { // Topological Sort
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameter of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Output the diameters for debugging (can be removed in production
        // code)
        cout << diameter1 << " " << diameter2 << "\n";

        // Calculate the longest path that spans across both trees.
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Function to find the diameter of a tree using topological sorting
    int findDiameter(int n, vector<vector<int>>& adjList) {
        queue<int> leavesQueue;
        vector<int> degrees(n);
        // Initialize the degree of each node and add leaves (nodes with degree
        // 1) to the queue
        for (int node = 0; node < n; node++) {
            degrees[node] =
                adjList[node].size();  // Degree is the number of neighbors
            if (degrees[node] == 1) {
                leavesQueue.push(node);
            }
        }

        int remainingNodes = n;
        int leavesLayersRemoved = 0;

        // Process the leaves until there are 2 or fewer nodes remaining
        while (remainingNodes > 2) {
            int size = leavesQueue.size();  // Get the number of leaves to
                                            // remove in this iteration
            remainingNodes -= size;
            leavesLayersRemoved++;

            // Remove the leaves from the queue and update the degrees of their
            // neighbors
            for (int i = 0; i < size; i++) {
                int currentNode = leavesQueue.front();
                leavesQueue.pop();

                // Process the neighbors of the current leaf
                for (int neighbor : adjList[currentNode]) {
                    degrees[neighbor]--;  // Decrease the degree of the neighbor
                    if (degrees[neighbor] == 1) {
                        leavesQueue.push(
                            neighbor);  // If the neighbor becomes a leaf, add
                                        // it to the queue
                    }
                }
            }
        }

        // If exactly two nodes remain, return the diameter as twice the number
        // of layers of leaves removed + 1 (as the diameter will include the
        // final connecting edge)
        if (remainingNodes == 2) return 2 * leavesLayersRemoved + 1;

        return 2 * leavesLayersRemoved;
    }
};
