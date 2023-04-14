/**
nowcoder BM4 合并两个排序的链表
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
数据范围： 0≤n≤1000，−1000≤节点值≤1000
要求：空间复杂度 O(1)，时间复杂度 O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == nullptr)
      return pHead2;
    if (pHead2 == nullptr)
      return pHead1;

    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    while (pHead1 != nullptr && pHead2 != nullptr) {
      if (pHead1->val <= pHead2->val) {
        cur->next = pHead1;
        pHead1 = pHead1->next;
      } else if (pHead1->val > pHead2->val) {
        cur->next = pHead2;
        pHead2 = pHead2->next;
      }
      cur = cur->next;
    }

    if (pHead1 != nullptr)
      cur->next = pHead1;
    if (pHead2 != nullptr)
      cur->next = pHead2;
    return head->next;
  }
};

int main() {
  Solution s;
  vector<int> l1 = {1, 3, 5};
  vector<int> l2 = {2, 4, 6};

  ListNode *h1, *p1;
  for (size_t i = 0; i < l1.size(); ++i) {
    if (i == 0) {
      h1 = p1 = new ListNode(l1[i]);
    } else {
      p1->next = new ListNode(l1[i]);
      p1 = p1->next;
    }
  }

  ListNode *h2, *p2;
  for (size_t i = 0; i < l2.size(); ++i) {
    if (i == 0) {
      h2 = p2 = new ListNode(l2[i]);
    } else {
      p2->next = new ListNode(l2[i]);
      p2 = p2->next;
    }
  }

  ListNode *ret = s.Merge(h1, h2);
  while (ret != nullptr) {
    cout << ret->val << " ";
    ret = ret->next;
  }
  cout << endl;
  return 0;
}
