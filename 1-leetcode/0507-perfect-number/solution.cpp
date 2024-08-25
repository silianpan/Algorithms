/**
* @brief 完美数
* 对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。
* 输入：num = 28
* 输出：true
* 解释：28 = 1 + 2 + 4 + 7 + 14
* 1, 2, 4, 7, 和 14 是 28 的所有正因子。
*/
#include <iostream>
using namespace std;

class Solution {
public:
  bool checkPerfectNumber(int num) {
    // 输入校验
    if (num <= 1 || num > 100000000) {
      return false;
    }
    int sum = 1;
    for (int i = 2; i <= num / i; ++i) {
      if (num % i == 0) {
        sum += i;
        if (i * i < num) {
          sum += num / i;
        }
      }
    }
    return num == sum;
  }
};

int main() {
  Solution s;
  cout << s.checkPerfectNumber(28) << endl;
  cout << s.checkPerfectNumber(26) << endl;
  cout << s.checkPerfectNumber(32) << endl;
}
