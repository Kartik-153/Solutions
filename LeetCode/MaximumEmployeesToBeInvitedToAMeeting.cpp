#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        // Find Longest Cycle

        int N = favorite.size();
        int longesCycle = 0;
        vector<bool> visit(N, false);

        for(int i = 0; i < N; i++) {
            if(visit[i]) continue;
            int start = i;
            int cur = i;
            
        }
    }
};