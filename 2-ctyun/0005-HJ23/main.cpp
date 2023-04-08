/**
nowcoder HJ23
实现删除字符串中出现次数最少的字符，若出现次数最少的字符有多个，则把出现次数最少的字符都删除。
输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。

数据范围：输入的字符串长度满足 1≤n≤20  ，保证输入的字符串中仅出现小写字母
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  string removeWords(string s) {

    unordered_map<char, size_t> tmap;
    for (char ch : s) {
      auto it = tmap.find(ch);
      if (it != tmap.end()) {
        tmap.insert(pair<char, int>(ch, it->second++));
      } else {
        tmap.insert(pair<char, int>(ch, 1));
      }
    }

    unordered_set<char> tmp;
    size_t flag = 0;
    for (unordered_map<char, size_t>::iterator it = tmap.begin();
         it != tmap.end(); ++it) {
      if (it == tmap.begin()) {
        flag = it->second;
        tmp.insert(it->first);
        continue;
      }
      if (flag > it->second) {
        tmp.clear();
        tmp.insert(it->first);
        flag = it->second;
      } else if (flag == it->second) {
        tmp.insert(it->first);
      }
    }
    tmap.clear();
    string ret;
    for (char ch : s) {
      // 没有找到
      if (tmp.find(ch) == tmp.end()) {
        ret.push_back(ch);
      }
    }
    tmp.clear();
    return ret;
  }
};

int main() {
  Solution s;
  cout << s.removeWords("aabcddd") << endl;
  return 0;
}
