// 0023 合并K个升序链表
// Created by liupan on 2021/1/15.
//

#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        // 排除特殊情况
        if (len == 0) return nullptr;
        ListNode* start = new ListNode;
        ListNode* head = start;

        // 外部循环标志：当其中一个列表结束，flag-1，当最后一个链表结束，flag减到0，外循环结束
        int flag = len;
        while (flag > 0) {
            // 查找当前指针最小值，并记录节点lnMin和下标iMin
            int vMax = 10000, iMin = -1;
            ListNode *lnMin = new ListNode;
            for (int i = 0; i < len; ++i) {
                ListNode *ln = lists[i];
                if (!ln) continue;
                if (ln->val < vMax) {
                    vMax = ln->val;
                    lnMin = ln;
                    iMin = i;
                }
            }
            // 判断找不到最小值，即内部节点存在空节点
            if (iMin != -1) {
                // 设置start的下一个节点值
                start->next = lnMin;
                // 移动到下一个节点
                start = start->next;
                // 移动最小值指针到下一个值
                lists[iMin] = lists[iMin]->next;
                // 若下一个为空，外循环标志-1
                if (lists[iMin] == nullptr) --flag;
            } else {
                // 如果是空节点，flag-1，防止死循环
                --flag;
            }
        }
        // 返回head的下一个节点，因为初始节点为0
        return head->next;
    }
};

int main() {
    ListNode* ln1 = new ListNode(1);
    ListNode* ln2 = new ListNode(4);
    ListNode* ln3 = new ListNode(5);
    ListNode* ln4 = new ListNode(1);
    ListNode* ln5 = new ListNode(3);
    ListNode* ln6 = new ListNode(4);
    ListNode* ln7 = new ListNode(2);
    ListNode* ln8 = new ListNode(6);

    ListNode* n1 = ln1;
    n1->next = ln2;
    n1->next->next = ln3;
    ListNode* n2 = ln4;
    n2->next = ln5;
    n2->next->next = ln6;
    ListNode* n3 = ln7;
    n3->next = ln8;

    vector<ListNode*> lists = {n1, n2, n3};
//    vector<ListNode*> lists = {nullptr, nullptr};

    Solution s;
    ListNode* ret = s.mergeKLists(lists);
    while (ret != nullptr) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}
