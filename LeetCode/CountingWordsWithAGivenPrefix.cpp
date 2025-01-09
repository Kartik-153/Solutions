#include<bits/stdc++.h>
using namespace std;

class Solution { // brute force
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (string& word : words) {
            res += hasPrefix(word, pref);
        }
        return res;
    }

private:
    int hasPrefix(string& str, string& pref) {
        int itr;
        for (itr = 0; itr < str.size() && itr < pref.size(); itr++) {
            if (str[itr] != pref[itr]) return 0;
        }
        if (itr != pref.size()) return 0;
        return 1;
    }
};

class Solution { // Inbuilt methods
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;  // Found a string with pref as prefix
            }
        }
        return count;
    }
};

class Solution { // Trie Method
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        // Add all words to trie
        for (string& word : words) {
            trie.addWord(word);
        }
        return trie.countPrefix(pref);
    }

private:
    class Trie {
        // Node class represents each character in Trie
        struct Node {
            // Links to child nodes
            vector<Node*> links;
            // Number of strings having prefix till this node
            int count;

            Node() : links(26, nullptr), count(0) {}
        };

        Node* root;

    public:
        Trie() { root = new Node(); }

        // Add word to trie and update prefix counts
        void addWord(string& word) {
            Node* curr = root;
            for (char c : word) {
                if (curr->links[c - 'a'] == nullptr) {
                    curr->links[c - 'a'] = new Node();
                }
                curr = curr->links[c - 'a'];
                curr->count++;  // Increment count for this prefix
            }
        }

        // Return count of strings having pref as prefix
        int countPrefix(string& pref) {
            Node* curr = root;
            for (char c : pref) {
                if (curr->links[c - 'a'] == nullptr) {
                    return 0;  // Prefix not found
                }
                curr = curr->links[c - 'a'];
            }
            return curr->count;  // Return count at last node
        }
    };
};