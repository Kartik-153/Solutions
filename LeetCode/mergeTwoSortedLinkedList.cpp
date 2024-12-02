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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		vector<int> v;
		while(list1!=NULL) {
			v.push_back(list1->val);
			list1 = list1->next;
		}
		while(list2!=NULL) {
			v.push_back(list2->val);
			list2 = list2->next;
		}
		sort(v.begin(), v.end());
		ListNode *result = new ListNode(-1);
		ListNode *temp = result;
		for(int i = 0; i < v.size(); i++) {
			result->next = new ListNode(v[i]);
			result = result->next;
		}
		temp = temp->next;
		return temp;
    }
};

class Solution { 
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* a = ans;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                a->next = list1;
                list1 = list1->next;
            } else {
                a->next = list2;
                list2 = list2->next;
            }
            a = a->next;
        }
        if (list1 != NULL) {
            a->next = list1;
        }
        if (list2 != NULL) {
            a->next = list2;
        }
        ans = ans->next;
        return ans;
    }
};
