//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/9
// @brief: 0025 K个一组翻转链表
//

#include <iostream>
#include <vector>

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int kk = k;
        ListNode *new_head = head;
        ListNode *start = head;
        ListNode *nex = nullptr;
        ListNode *tail = nullptr;
        while (start) {
            if (kk == 1) {
                // 先保存当前组的下一位
                nex = start->next;
                // 将下一位置空，将当前组分为一组
                start->next = nullptr;
                // 翻转当前组
                ListNode *temp = reverseKGroup(head);
                // 第一次循环，保存新的组的开头
                if (new_head == head) new_head = temp;
                // 如果end不为空，将当前组的连接到下一组的开始
                if (tail) tail->next = start;

                // 设置新的当前组的原开头为结尾
                tail = head;
                // 设置下一组的开头
                head = nex;
                // 设置下一组的开始
                start = nex;
                // 初始化下一组循环
                kk = k;
                continue;
            }
            --kk;
            start = start->next;
        }
        if (tail) tail->next = head;
        return new_head;
    }

    /**
     * 翻转链表
     * @param head
     * @return
     */
    ListNode *reverseKGroup(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *nex = nullptr;
        ListNode *cur = head;
        while (cur) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head;
    ListNode *start;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        if (it == nums.begin()) {
            start = head = new ListNode(*it);
        } else {
            start->next = new ListNode(*it);
            start = start->next;
        }
    }
    Solution s;
    ListNode *ret = s.reverseKGroup(head, 2);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}
