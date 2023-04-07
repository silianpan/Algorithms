/**
给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。
*/

#include <iostream>

using namespace std;

class Solution {
public:
  int countOdds(int low, int high) {
    // 超出时间范围
    // if (low > high)
    //   return 0;
    // int cout = 0;
    // for (int i = low; i <= high; ++i) {
    //   if (i % 2 == 1)
    //     ++cout;
    // }
    // return cout;

    // 解法一
    // return (high + 1) / 2 - low / 2;
    // 解法二
    return ((high + 1) >> 1) - (low >> 1);
  }
};

int main() {
  Solution s;
  cout << s.countOdds(8, 10) << endl;
  return 0;
}
