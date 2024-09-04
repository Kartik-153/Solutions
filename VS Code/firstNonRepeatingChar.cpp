#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define NO_OF_CHARS 256
int firstNonRepeatingChar_NAIVE(string s) {
    if(s.size() == 0) 
        return -1;
    for(int i = 0; i < s.size(); i++) {
        if(count(s.begin(), s.end(), s[i]) == 1) {
            return s.find(s[i]);
        }
    }
    return -1;
}

int firstNonRepeatingChar_StringMethod(string s) {

    for(int i = 0; i < s.size(); i++) {
        if(s.find(s[i],s.find(s[i]) + 1)) {
            return s.find(s[i]);
        }
    }
    return -1;
}

int* getCharCountArray(char* str) {
    int* count = (int*)calloc(sizeof(int), NO_OF_CHARS);
    int i;
    for(i = 0; *(str+i); i++) {
        count[*(str+i)]++;
    }
    return count;
}

int firstNonRepeating_PAIR(char* str) {
    pair<int, int> arr[NO_OF_CHARS];

    for(int i = 0; str[i]; i++) {
        (arr[str[i]].first)++;
        arr[str[i]].second = i;
    }

    int res = INT_MAX;
    for(int i = 0; i < NO_OF_CHARS; i++) {
        if(arr[i].first == 1) {
            int res = min(res, arr[i].second);
        }
    }
    return res;
    
}

int firstNonRepeatingChar_MAPS(string s) {
    unordered_map<char, int> freq;
    for(char c: s) {
        freq[c]++;
    }

    for(char c: s) {
        if(freq[c] == 1) {
            return s.find(c);
        }
    }
}

void printString(string s) {
    for(auto x: s) {
        cout << x << " ";
    }
}

int main() {
    // printString("ngiern");
    cout << firstNonRepeatingChar_NAIVE("hellh");

    return 0;
}