/**
nowcoder BM83
对于一个长度为 n 字符串，我们需要对它做一些变形。

首先这个字符串中包含着一些空格，就像"Hello
World"一样，然后我们要做的是把这个字符串中由空格隔开的单词反序，同时反转每个字符的大小写。

比如"Hello World"变形后就变成了"wORLD hELLO"。
*/

#include <iostream>
using namespace std;

class Solution {
public:
  string trans(string s, int n) {
    // write code here
    string tmp, ret;
    for (int i = n - 1; i >= 0; --i) {
      char ch;
      if (s[i] >= 'a' && s[i] <= 'z') {
        ch = s[i] - 32;
      } else if (s[i] >= 'A' && s[i] <= 'Z') {
        ch = s[i] + 32;
      } else {
        tmp.push_back(s[i]);
        ret.insert(ret.length(), tmp);
        tmp.clear();
        continue;
      }
      tmp.insert(0, 1, ch);
    }
    if (!tmp.empty()) {
        ret.insert(ret.length(), tmp);
        tmp.clear();
    }
    return ret;
  }
};

int main() {
  Solution s;
  cout << s.trans(" h i", 4) << endl;
  return 0;
}
