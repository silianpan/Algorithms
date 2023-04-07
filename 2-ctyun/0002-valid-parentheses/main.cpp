/**
leetcode 20
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.empty())
      return false;
    stack<char> tmp;
    for (char ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        tmp.push(ch);
      } else if (ch == ')') {
        if (tmp.empty() || tmp.top() != '(')
          return false;
        else
          tmp.pop();
      } else if (ch == '}') {
        if (tmp.empty() || tmp.top() != '{')
          return false;
        else
          tmp.pop();
      } else if (ch == ']') {
        if (tmp.empty() || tmp.top() != '[')
          return false;
        else
          tmp.pop();
      } else {
        return false;
      }
    }
    bool ret = tmp.empty();
    while (!tmp.empty())
      tmp.pop();
    return ret;
  }
};

int main() {
  Solution s;
  bool ret = s.isValid("[]{}()");
  cout << boolalpha << ret << endl;
  return 0;
}
