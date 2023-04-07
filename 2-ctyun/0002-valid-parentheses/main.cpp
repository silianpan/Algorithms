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
