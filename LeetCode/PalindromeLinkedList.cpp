#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool check(vector<int> &nums) {
        bool flag = false;
        int n = nums.size();
        for (int i = 0; i <= n / 2 && n != 0; i++) {
            if (nums[i] != nums[n - i - 1]) {
                flag = true;
                break;
            }
        }
        return !flag;
    }

    bool isPalindrome(ListNode *head) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        return check(v);
    }
};

class Solution2 {
public:
    bool isPalindromicLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        // Find the middle of the LinkedList
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half
        ListNode* headSecondHalf = reverse(slow);
        
        // Store the head of reversed part to revert back later
        ListNode* copyHeadSecondHalf = headSecondHalf;
        
        // Compare first and second half
        while (head != nullptr && headSecondHalf != nullptr) {
            if (head->val != headSecondHalf->val) {
                break;
            }
            head = head->next;
            headSecondHalf = headSecondHalf->next;
        }
        
        // Revert the reverse of the second half
        reverse(copyHeadSecondHalf);
        
        // If both halves match
        if (head == nullptr || headSecondHalf == nullptr) {
            return true;
        }
        
        return false;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
