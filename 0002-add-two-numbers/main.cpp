//
// Created by liupan on 2020/12/21.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // 头部指针
        ListNode *head = new ListNode;
        // 遍历
        ListNode *phead = head;

        while (l1 != NULL || l2 != NULL || phead != NULL) {
            // 求和
            int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + (phead == NULL ? 0 : phead->val);
            // 除10
            if (sum >= 10) {
                // 取余数
                int mod = sum % 10;
                phead->val = mod;
                phead->next = new ListNode(1);
//                phead->next->val = 1;
            } else {
                phead->val = sum;
                if ((l1 != NULL && l1->next != NULL) || (l2 != NULL && l2->next != NULL)) {
                    phead->next = new ListNode;
                }
            }

            if (phead != NULL) {
                phead = phead->next;
            }

            if (l1 != NULL) {
                l1 = l1->next;
            }

            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        return head;
    }
};

int main() {
    Solution s;
//    vector<int> v1 = {2, 4, 3};
//    vector<int> v2 = {5, 6, 9, 9};

//    vector<int> v1 = {9, 9, 9, 9, 9, 9, 9};
//    vector<int> v2 = {9, 9, 9, 9};

//    vector<int> v1 = {3, 7};
//    vector<int> v2 = {9, 2};

    vector<int> v1 = {1, 6, 0, 3, 3, 6, 7, 2, 0, 1};
    vector<int> v2 = {6, 3, 0, 8, 9, 6, 6, 9, 6, 1};

    ListNode *head1 = new ListNode;
    ListNode *l1 = head1;
    for (size_t i1 = 0; i1 < v1.size(); ++i1) {
        l1->val = v1[i1];
        if (i1 + 1 != v1.size()) {
            l1->next = new ListNode;
            l1 = l1->next;
        }
    }

    ListNode *head2 = new ListNode;
    ListNode *l2 = head2;
    for (size_t i2 = 0; i2 < v2.size(); ++i2) {
        l2->val = v2[i2];
        if (i2 + 1 != v2.size()) {
            l2->next = new ListNode;
            l2 = l2->next;
        }
    }

    ListNode *ret = s.addTwoNumbers(head1, head2);

    while (ret != NULL) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}

