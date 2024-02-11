class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) {
            return 0;
        }
        int maxLength = 0;
        int start = 0;
        
        unordered_map<char, int> charIndexMap;

        for (int end = 0; end < n; ++end) {
            if (charIndexMap.find(s[end]) != charIndexMap.end() && charIndexMap[s[end]] >= start) {
                start = charIndexMap[s[end]] + 1;
            }
            charIndexMap[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
    return maxLength;
    }
};
