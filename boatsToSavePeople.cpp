#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0, boats = 0;
        int j = n - 1;

        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                boats++;
                i++;
                j--;
            } else {
                boats++;
                j--;
            }
        }
        return boats;
    }
};
