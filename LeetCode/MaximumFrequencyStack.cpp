#include<bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    FreqStack() {}
    
    void push(int val) {
        int freq = freqMap[val] + 1;
        freqMap[val] = freq;

        if(freqStack.size() < freq) {
            freqStack.push_back(stack<int>());
        }

        freqStack[freq-1].push(val);
    }
    
    int pop() {
        stack<int>& topStack = freqStack.back();
        int value = topStack.top();
        topStack.pop();

        if(topStack.empty()) {
            freqStack.pop_back();
        }

        freqMap[value] -= 1;

        return value;
    }
private:
    unordered_map<int, int> freqMap;
    vector<stack<int>> freqStack;
};