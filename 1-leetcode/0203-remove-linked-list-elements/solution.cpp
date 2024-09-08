#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
      return head;
    }

    ListNode *prev = head;
    while (prev != nullptr && prev->val == val) {
      prev = head->next;
      head = head->next;
    }

    while (prev != nullptr && prev->next != nullptr) {
      if (prev->next->val == val) {
        prev->next = prev->next->next;
      } else {
        prev = prev->next;
      }
    }
    return head;
  }
};

int main() {
  int num[] = {1, 2, 6, 3, 4, 5, 6};
  ListNode *list = new ListNode(1);
  ListNode *head = list;
  ListNode *headBus = list;
  for (size_t i = 1; i < sizeof(num) / sizeof(num[0]); ++i) {
    list->next = new ListNode(num[i]);
    list = list->next;
  }
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  cout << "removeElements: " << endl;

  Solution s;
  ListNode *newHead = s.removeElements(headBus, 6);

  while (newHead != nullptr) {
    cout << newHead->val << " ";
    newHead = newHead->next;
  }
  cout << endl;
}
