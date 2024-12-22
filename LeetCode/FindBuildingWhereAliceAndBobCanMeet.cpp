#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<pair<int, int>> monoStack;
        vector<int> result(queries.size(), -1);
        vector<vector<pair<int, int>>> newQueries(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b)
                swap(a, b);
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            else
                newQueries[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
                monoStack.pop_back();
            monoStack.push_back({heights[i], i});
        }
        return result;
    }

private:
    int search(int height, vector<pair<int, int>>& monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<vector<vector<int>>> storeQueries(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            maxIndex;
        vector<int> result(queries.size(), -1);

        // Store the mappings for all queries in storeQueries.
        for (int currQuery = 0; currQuery < queries.size(); currQuery++) {
            int a = queries[currQuery][0], b = queries[currQuery][1];
            if (a < b && heights[a] < heights[b]) {
                result[currQuery] = b;
            } else if (a > b && heights[a] > heights[b]) {
                result[currQuery] = a;
            } else if (a == b) {
                result[currQuery] = a;
            } else {
                storeQueries[max(a, b)].push_back(
                    {max(heights[a], heights[b]), currQuery});
            }
        }

        for (int index = 0; index < heights.size(); index++) {
            // If the priority queue's minimum pair value is less than the
            // current index of height, it is an answer to the query.
            while (!maxIndex.empty() && maxIndex.top()[0] < heights[index]) {
                result[maxIndex.top()[1]] = index;
                maxIndex.pop();
            }
            // Push the with their maximum index as the current index in the
            // priority queue.
            for (auto& element : storeQueries[index]) {
                maxIndex.push(element);
            }
        }
        return result;
    }
};

constexpr int MAX_SZ = 5e4 + 10;
constexpr int INF = 1e5;
int tree[MAX_SZ * 4];

void build_tree(int v, int tl, int tr, vector<int>& heights) {
    if (tl == tr) {
        tree[v] = heights[tl];
        return;
    }

    int tm = (tl + tr) / 2;

    build_tree(v * 2 + 1, tl, tm, heights);
    build_tree(v * 2 + 2, tm + 1, tr, heights);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int leftmost_greater_idx(int v, int tl, int tr, int l, int r, int min_val) {
    if (tl > r || tr < l) {
        return INF;
    }

    if (tree[v] < min_val) {
        return INF;
    }

    if (tl == tr) {
        return tl;
    }

    int tm = (tl + tr) / 2;

    int ltree_ans = leftmost_greater_idx(v * 2 + 1, tl, tm, l, r, min_val);
    if (ltree_ans != INF)
        return ltree_ans;

    return leftmost_greater_idx(v * 2 + 2, tm + 1, tr, l, r, min_val);
}

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<int> answers;
        answers.reserve(queries.size());

        int n = heights.size();
        build_tree(0, 0, n - 1, heights);

        // auto mapped_heigts = map_heights(heights);
        for (auto& query : queries) {
            int a = query[0], b = query[1];
            if (a > b) {
                swap(a, b);
            }

            if (a == b) {
                answers.push_back(a);
                continue;
            }

            int min_height = max(heights[a], heights[b]);
            if (heights[a] >= heights[b]) {
                ++min_height;
            }

            int answer =
                leftmost_greater_idx(0, 0, n - 1, b, n - 1, min_height);

            if (answer == INF) {
                answer = -1;
            }

            answers.push_back(answer);
        }

        return answers;
    }
};
