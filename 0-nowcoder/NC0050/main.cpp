//
// Created by liupan on 2021/2/7.
//

#include <iostream>
#include <vector>
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
        int kk = k;
        ListNode *new_head = head;
        ListNode *cur = head;
        ListNode *nex = nullptr;
        ListNode *end = nullptr;

        // 遍历链表
        while (cur) {
            // 找到第k次尾
            if (kk == 1) {
                // 保存每组末尾下一位
                nex = cur->next;
                // 截断每组
                cur->next = nullptr;
                // 反转当前组链表，并返回新的列表第一位
                ListNode *temp = reverseKGroup(head);
                // 如果是第一次循环，返回新的首地址
                if (new_head == head) new_head = temp;
                // 如果结尾不为空，下一位即为当前

                // 拼接每组新开始和新结尾
                if (end) end->next = cur;

                // 因为反转了，所以设置结尾为开头
                end = head;

                // 设置开头为下一组开头
                head = nex;
                // 设置当前为下一组开头
                cur = nex;
                kk = k;
                continue;
            }
            --kk;
            cur = cur->next;
        }
        // 如果节点数不是k的倍数，将剩余的串联起来
        if (end) end->next = head;
        return new_head;
    }

    /**
     * 反转链表
     * @param head
     * @return 返回反转后的链表首位
     */
    ListNode* reverseKGroup(ListNode* head) {
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
    vector<int> num = {1, 2, 3, 4, 5};
    ListNode *head;
    ListNode *start;
    for (vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
        if (it == num.begin()) {
            start = head = new ListNode;
            start->val = *it;
            head->val = *it;
        } else {
            start->next = new ListNode;
            start->next->val = *it;
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
