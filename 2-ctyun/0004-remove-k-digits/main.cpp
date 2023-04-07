/**
leetcode 402 移掉 K 位数字
给你一个以字符串表示的非负整数 num 和一个整数 k ，
移除这个数中的 k 位数字，使得剩下的数字最小。
请你以字符串形式返回这个最小的数字。
*/

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    if (num.empty() || k >= num.size())
      return "0";
    if (k == 0)
      return num;

    queue<char> tmp;
    tmp.push(num[0]);

    size_t i = 1;
    int flag = 0;
    while (i < num.size() && flag < k) {
      if (tmp.empty()) {
        tmp.push(num[i]);
        ++i;
        continue;
      }
      if (num[i] < tmp.back()) {
        tmp.pop();
        if (!(tmp.empty() && num[i] == '0')) {
          tmp.push(num[i]);
        }
        ++flag;
      } else if (num[i] > tmp.back()) {
        ++flag;
      }
      ++i;
    }

    string s;
    while (!tmp.empty()) {
      s.push_back(tmp.front());
      tmp.pop();
    }

    while (i < num.size()) {
      if (s.empty() && num[i] == '0') {
        ++i;
        continue;
      }
      s.push_back(num[i]);
      ++i;
    }
    return s.empty() ? "0" : s;
  }
};

int main() {
  Solution s;
  string ret = s.removeKdigits("112", 1);
  cout << ret << endl;
  return 0;
}
