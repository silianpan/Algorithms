//
// Created by liupan on 2021/2/8.
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
    ListNode *swapPairs(ListNode *head) {
        int k = 2;
        ListNode *new_head = head;
        ListNode *nex = nullptr;
        ListNode *end = nullptr;
        ListNode *start = head;
        while (start) {
            if (k == 1) {
                // 保存当前的下一位
                nex = start->next;
                // 截断链表，分为一组
                start->next = nullptr;
                // 反转链表，并返回新的首位
                ListNode *temp = swap(head);
                // 如果是首次循环，设置新的首位
                if (new_head == head) new_head = temp;

                // 将第一组的新的结尾连接第二组的新的开始
                if (end) end->next = start;

                // 因为反转了，所以设置结尾为开头
                end = head;
                // 设置开头为下一组开头
                head = nex;
                // 设置开始为下一组开头
                start = nex;
                k = 2;
                continue;
            }
            --k;
            start = start->next;
        }
        // 如果链表个数不是k即2的倍数，将剩下的连接起来
        if (end) end->next = head;
        return new_head;
    }

    /**
     * 反转链表
     * @param head
     * @return 返回反转后的链表首位
     */
    ListNode *swap(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *nex = nullptr;
        ListNode *cur = head;
        while (cur) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        // 返回反转后的链表首位
        return pre;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    ListNode *head = nullptr;
    ListNode *start = nullptr;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        if (it == nums.begin()) {
            start = head = new ListNode(*it);
        } else {
            start->next = new ListNode(*it);
            start = start->next;
        }
    }

    Solution s;
    ListNode *ret = s.swapPairs(head);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}

