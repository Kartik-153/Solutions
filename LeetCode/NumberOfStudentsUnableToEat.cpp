#inlcude<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> s;
        queue<int> q;
        for (int i = sandwiches.size() - 1; i >= 0; --i) {
            s.push(sandwiches[i]);
        }
        for (const auto& e : students) {
            q.push(e);
        }
        int unable_to_eat = 0;

        while (!s.empty() && !q.empty() && unable_to_eat < q.size()) {
            if (s.top() == q.front()) {
                unable_to_eat = 0; 
                s.pop();
                q.pop();
            } else {
                int x = q.front();
                q.pop();
                q.push(x);
                unable_to_eat++;
            }
        }
        return q.size(); 
    }
};
