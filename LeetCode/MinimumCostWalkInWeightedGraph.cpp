#include <bits/stdc++.h>
using namespace std;

class Solution { // Union find 
public:
    vector<int> parent;
    vector<int> depth;

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Initialize the parent array with -1 as initially each node belongs to
        // its own component
        parent.resize(n, -1);
        depth.resize(n, 0);

        // All values are initially set to the number with only 1s in its binary
        // representation
        vector<unsigned int> componentCost(n, -1);

        // Construct the connected components of the graph
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        // Calculate the cost of each component by performing bitwise AND of all
        // edge weights in it
        for (auto& edge : edges) {
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        vector<int> answer;
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            // If the two nodes are in different connected components, return -1
            if (find(start) != find(end)) {
                answer.push_back(-1);
            } else {
                // Find the root of the edge's component
                int root = find(start);
                // Return the precomputed cost of the component
                answer.push_back(componentCost[root]);
            }
        }
        return answer;
    }

private:
    // Find function to return the root (representative) of a node's component
    int find(int node) {
        // If the node is its own parent, it is the root of the component
        if (parent[node] == -1)
            return node;
        // Otherwise, recursively find the root and apply path compression
        return parent[node] = find(parent[node]);
    }

    // Union function to merge the components of two nodes
    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        // If the two nodes are already in the same component, do nothing
        if (root1 == root2)
            return;

        // Union by depth: ensure the root of the deeper tree becomes the parent
        if (depth[root1] < depth[root2])
            swap(root1, root2);

        // Merge the two components by making root1 the parent of root2
        parent[root2] = root1;

        // If both components had the same depth, increase the depth of the new
        // root
        if (depth[root1] == depth[root2])
            depth[root1]++;
    }
};

class Solution { // BFS
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform BFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            } else {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using BFS
    int getComponentCost(int source, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        queue<int> nodesQueue;

        // Initialize the component cost to the number that has only 1s in its
        // binary representation
        int componentCost = INT_MAX;

        nodesQueue.push(source);
        visited[source] = true;

        // Perform BFS to explore the component and calculate the cost
        while (!nodesQueue.empty()) {
            int node = nodesQueue.front();
            nodesQueue.pop();

            // Mark the node as part of the current component
            components[node] = componentId;

            // Explore all neighbors of the current node
            for (auto& [neighbor, weight] : adjList[node]) {
                // Update the component cost by performing a bitwise AND of the
                // edge weights
                componentCost &= weight;

                // If the neighbor hasn't been visited, mark it as visited and
                // add it to the queue
                if (visited[neighbor])
                    continue;
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
            }
        }

        return componentCost;
    }
};

class Solution { // DFS
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform DFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            } else {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using DFS
    int getComponentCost(int node, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        // Initialize the cost to the number that has only 1s in its
        // binary representation
        int currentCost = INT_MAX;

        // Mark the node as part of the current component
        components[node] = componentId;
        visited[node] = true;

        // Explore all neighbors of the current node
        for (auto& [neighbor, weight] : adjList[node]) {
            // Update the cost by performing a bitwise AND of the edge
            // weights
            currentCost &= weight;

            if (!visited[neighbor]) {
                // Recursively calculate the cost of the rest of the component
                // and accumulate it into currentCost
                currentCost &= getComponentCost(neighbor, adjList, visited,
                                                components, componentId);
            }
        }

        return currentCost;
    }
};