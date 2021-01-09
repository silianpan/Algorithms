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
        unordered_map<int, ListNode*> tmpMap;
        ListNode *start = head;
        int i = 0;
        while (start != nullptr) {
            tmpMap.insert(pair<int, ListNode*>(i, start));
            start = start->next;
            ++i;
        }

        if (tmpMap.size() - n <= 0) {
            return head->next;
        } else {
            auto tmp1 = tmpMap.find(tmpMap.size() - n - 1);
            if (tmp1 != tmpMap.end()) {
                ListNode *ln = tmp1->second;
                if (n <= 1) {
                    ln->next = nullptr;
                } else {
                    auto tmp2 = tmpMap.find(tmpMap.size() - n + 1);
                    ln->next = tmp2->second;
                }
            }
        }
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
    ListNode* ret = s.removeNthFromEnd(head, 6);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}
