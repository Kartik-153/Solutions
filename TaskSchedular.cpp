#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int frp[26] = {0};
        for(char task: tasks) {
            frp[task-'A']++;
        }
        sort(begin(frp), end(frp));
        int chunk = frp[25]-1;
        int idel = chunk*n;
        for(int i = 24; i >= 0; i--) {
            idel -= min(chunk, frp[i]);
        }
        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};
