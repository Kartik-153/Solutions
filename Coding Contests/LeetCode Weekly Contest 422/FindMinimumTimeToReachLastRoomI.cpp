#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
       int n = moveTime.size();
       int m = moveTime[0].size();

       vector<pair<int, int>> directions = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};

       vector<vector<int>> visited(n, vector<int>(m, INT_MAX));

       visited[0][0] = 0;

       queue<tuple<int, int, int>> q;
       q.push({0,0,0});

       while(!q.empty()) {
        int row = get<0>(q.front());
        int col = get<1>(q.front());
        int currTime = get<2>(q.front());
        q.pop();
        if(row==n-1 && col == m-1) {
            return currTime;
        }

        for(auto & dir: directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                int nextTime = currTime + 1;

                if(nextTime < moveTime[newRow][newCol]) {
                    nextTime = moveTime[newRow][newCol];
                }

                if(nextTime < visited[newRow][newCol]) {
                    visited[newRow][newCol] = nextTime;
                    q.push(make_tuple(newRow, newCol, nextTime));
                }
            }
        }

       } 
    return -1;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int result = dfs(moveTime, dp, 0, 0, 0, n, m);
        return result == INT_MAX ? -1 : result; 
    }

private:
    int dfs(vector<vector<int>>& moveTime, vector<vector<int>>& dp, int row, int col, int curTime, int n, int m) {
        if (row == n - 1 && col == m - 1) {
            return curTime;
        }
        if (curTime >= dp[row][col]) {
            return INT_MAX; 
        }

        dp[row][col] = curTime; 
        int minTime = INT_MAX;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                int waitTime = max(moveTime[newRow][newCol] - curTime, 0);
                int newTime = curTime + waitTime + 1;
                minTime = min(minTime, dfs(moveTime, dp, newRow, newCol, newTime, n, m));
            }
        }
        return minTime; 
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            _pq_;
        _pq_.push({0, 0, 0});
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!_pq_.empty()) {
            vector<int> curr = _pq_.top();
            _pq_.pop();
            int time = curr[0];
            int row = curr[1];
            int col = curr[2];
            if (time > dist[row][col])
                continue;
            for (const auto& dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int newTime = max(time, moveTime[newRow][newCol]) + 1;
                    if (newTime < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newTime;
                        _pq_.push({newTime, newRow, newCol});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};