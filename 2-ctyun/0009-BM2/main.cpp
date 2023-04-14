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
    int i = 1, j = 1;
    ListNode *move = head, *start, *end, *th, *te;
    while (move != nullptr) {
      if (i == m) {
        start = move;
        break;
      } else if (i == n) {
        end = move;
      }
      move = move->next;
      ++i;
    }
  }
};

int main() { return 0; }
