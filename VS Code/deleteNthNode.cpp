#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthNodeFromEnd(ListNode *head, int n)
    {
        int pos = count(head) + n - 1;
        return deleteNthNode(head, pos);
    }

    int count(ListNode *head)
    {
        int ans = 0;
        while (head != nullptr)
        {
            ans += 1;
            head = head->next;
        }
        return ans;
    }

    ListNode *deleteNthNode(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr;
        if (n == 1)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        for (int i = 2; i < n && curr != nullptr; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr != nullptr)
        {
            prev->next = curr->next;
            delete curr;
        }
        return head;
    }
};