/**
将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转
*/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
  /**
   *
   * @param head ListNode类
   * @param m int整型
   * @param n int整型
   * @return ListNode类
   */
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    // write code here
    int i = 1;
    ListNode *move = head, *pm_1, *pm, *pn;
    while (move != nullptr) {
      if (i == m - 1) {
        pm_1 = move;
      } else if (i == m) {
        pm = move;
      } else if (i == n) {
        pn = move;
      }
      move = move->next;
      ++i;
    }

    pm_1->next = pn;
    ListNode *tmp = pm->next;
    pm->next = pn->next;
  }
};

int main() { return 0; }
