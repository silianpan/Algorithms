// 0019 删除链表的倒数第N个节点
// Created by liupan on 2021/1/9.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head, *second = new ListNode(0, head);
        for (size_t i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return head;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head, *start;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i == 0) {
            start = head = new ListNode(nums[i]);
        } else {
            start->next = new ListNode(nums[i]);
            start = start->next;
        }
    }
    Solution s;
    ListNode* ret = s.removeNthFromEnd(head, 2);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}
