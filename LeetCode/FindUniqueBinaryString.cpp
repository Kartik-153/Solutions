#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    unordered_set<string> numsSet;
    
    string generate(string curr) {
        if (curr.size() == n) {
            if (numsSet.find(curr) == numsSet.end()) {
                return curr;
            }
            
            return "";
        }
        
        string addZero = generate(curr + "0");
        if (addZero.size() > 0) {
            return addZero;
        }
        
        return generate(curr + "1");
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for (string s : nums) {
            numsSet.insert(s);
        }
        
        return generate("");
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> integers;
        for (string num : nums) {
            integers.insert(stoi(num, 0, 2));
        }
        
        int n = nums.size();
        for (int num = 0; num <= n; num++) {
            if (integers.find(num) == integers.end()) {
                string ans = bitset<16>(num).to_string();
                return ans.substr(16 - n);
            }
        }
        
        return "";
    }
};

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        
        return ans;
    }
};
