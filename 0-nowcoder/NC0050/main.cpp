//
// Created by liupan on 2021/2/7.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        // 求链表长度
        int len = 0;
        ListNode *start = head;
        while (start) {
            ++len;
            start = start->next;
        }
        // 特列：长度小于k
        if (len < k) return head;

        start = head;
        // 遍历次数
        int loop = len / k;
        ListNode *pre = nullptr;
        ListNode *nex = nullptr;
        ListNode *cur = start;
        ListNode *end = nullptr;
        for (int i = 0; i < loop; ++i) {
            for (int j = 0; j < k; ++j) {
                // 反转k长度列表
                end = cur;
                nex = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nex;
            }
            cur->next = end;
            pre = cur;
            cur = nex;
            nex = cur->next;
        }
    }
};

int main() {

}
