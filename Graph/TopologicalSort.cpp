#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int vertices, vector<vector<int>> &edges)
{ // Time = O(V+E)
    vector<int> sortedOrder;

    if (vertices <= 0)
    {
        return sortedOrder;
    }

    // 1. Initialize the graph
    vector<int> inDegree(vertices, 0);   // count of incoming edges
    vector<vector<int>> graph(vertices); // adjacency list graph

    // 2. Build the graph
    for (auto &edge : edges)
    {
        int parent = edge[0], child = edge[1];
        graph[parent].push_back(child); // put the child into its parent's list
        inDegree[child]++;              // increment child's inDegree
    }

    // 3. Find all sources (vertices with 0 in-degree)
    queue<int> sources;
    for (int i = 0; i < vertices; i++)
    {
        if (inDegree[i] == 0)
        {
            sources.push(i);
        }
    }

    // 4. For each source, add it to sortedOrder and decrement its children's in-degrees
    while (!sources.empty())
    {
        int vertex = sources.front();
        sources.pop();
        sortedOrder.push_back(vertex);
        for (auto &child : graph[vertex])
        {
            inDegree[child]--;
            if (inDegree[child] == 0)
            {
                sources.push(child);
            }
        }
    }

    // Topological sort is not possible if the graph has a cycle
    if (sortedOrder.size() != vertices)
    {
        return {};
    }

    return sortedOrder;
}

void printResult(vector<int> result)
{
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}

class Solution
{
public:
    bool courses(int vertices, vector<vector<int>> &edges)
    {
        vector<int> sortedList;

        if (vertices == 0)
        {
            return false;
        }

        vector<int> inDegree(vertices, 0);
        vector<vector<int>> graph(vertices);

        for (auto &edge : edges)
        {
            int source = edge[0], child = edge[1];
            graph[source].push_back(child);
            inDegree[child] += 1;
        }

        queue<int> sources;
        for (int i = 0; i < vertices; i++)
        {
            if (inDegree[i] == 0)
            {
                sources.push(i);
            }
        }

        while (!sources.empty())
        {
            int vertex = sources.front();
            sources.pop();

            sortedList.push_back(vertex);
            for (auto &child : graph[vertex])
            {
                inDegree[child]--;
                if (inDegree[child] == 0)
                {
                    sources.push(child);
                }
            }
        }

        return sortedList.size() == vertices;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans = courses(numCourses, prerequisites);
        if (ans.size() < numCourses)
        {
            return {};
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> khan(int k, vector<vector<int>> &prerequisites)
    {
        vector<int> graph[k];
        vector<int> degree(k);
        for (auto i : prerequisites)
        {
            graph[i[1]].push_back(i[0]);
            degree[i[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            if (degree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for (auto it : graph[i])
            {
                degree[it]--;
                if (degree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans = khan(numCourses, prerequisites);
        if (ans.size() < numCourses)
        {
            return {};
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> edges1 = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
    cout << "Topological sort: ";
    printResult(topologicalSort(4, edges1));
    // Expected output: 3, 2, 0, 1 or 3, 2, 1, 0

    vector<vector<int>> edges2 = {{4, 2}, {4, 3}, {2, 0}, {2, 1}, {3, 1}};
    cout << "Topological sort: ";
    printResult(topologicalSort(5, edges2));
    // Expected outputs include: 4, 2, 3, 0, 1 or 4, 3, 2, 0, 1

    vector<vector<int>> edges3 = {{6, 4}, {6, 2}, {5, 3}, {5, 4}, {3, 0}, {3, 1}, {3, 2}, {4, 1}};
    cout << "Topological sort: ";
    printResult(topologicalSort(7, edges3));
    // Expected outputs include: 5, 6, 3, 4, 0, 1, 2 or similar

    return 0;
}
