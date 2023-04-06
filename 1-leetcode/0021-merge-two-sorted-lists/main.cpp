// 0021 合并两个有序链表
// Created by liupan on 2021/1/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* start = new ListNode;
        ListNode* head = start;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                start->next = new ListNode(l1->val);
                start = start->next;
                l1 = l1->next;
            } else if (l1->val == l2->val) {
                start->next = new ListNode(l1->val);
                start = start->next;
                start->next = new ListNode(l2->val);
                start = start->next;
                l1 = l1->next;
                l2 = l2->next;
            } else {
                start->next = new ListNode(l2->val);
                start = start->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            start->next = new ListNode(l1->val);
            start = start->next;
            l1 = l1->next;
        }
        while (l2) {
            start->next = new ListNode(l2->val);
            start = start->next;
            l2 = l2->next;
        }
        return head->next;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {};
    vector<int> v2 = {0};
    ListNode *l1 = new ListNode, *l2 = new ListNode;
    ListNode *h1 = l1;
    ListNode *h2 = l2;
    for (size_t i = 0; i < v1.size(); ++i) {
        l1->next = new ListNode(v1[i]);
        l1 = l1->next;
    }
    for (size_t i = 0; i < v2.size(); ++i) {
        l2->next = new ListNode(v2[i]);
        l2 = l2->next;
    }
    ListNode* ret = s.mergeTwoLists(h1->next, h2->next);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}

