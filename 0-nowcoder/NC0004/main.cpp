//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/9
// @brief: NC4 判断链表中是否有环
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = nullptr;
    ListNode *start = nullptr;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        if (it == nums.begin()) {
            head = start = new ListNode(*it);
        } else {
            start->next = new ListNode(*it);
            start = start->next;
        }
        // 最后一个
        if (it == nums.end() - 1) {
            start->next = head;
        }
    }
    Solution s;
    bool ret = s.hasCycle(head);
    cout << boolalpha << ret << endl;
}
