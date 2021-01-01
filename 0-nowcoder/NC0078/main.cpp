// NC78 反转链表
// Created by liupan on 2021/1/1.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    /**
     * a->b->c
     * a<-b<-c
     * @param pHead
     * @return
     */
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        ListNode* nex = nullptr;
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
    vector<int> num = {1, 2, 3};
    ListNode* pHead;
    ListNode* tmp;
    for (vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
        if (it == num.begin()) {
            tmp = pHead = new ListNode(*it);
        } else {
            tmp->next = new ListNode(*it);
            tmp = tmp->next;
        }
    }
    delete tmp;
    Solution s;
    ListNode* ret = s.ReverseList(pHead);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}
