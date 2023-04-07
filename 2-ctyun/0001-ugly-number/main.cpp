//
// Created by liupan on 2023/4/6.
// 题目：把只包含质因子2、3和5的数称作丑数（Ugly
// Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  /**
    思路：要求从小到大的第N个丑数，可以利用动态规划的思想，每个丑数都是由前面某一个丑数乘以2、3或5得到的。设三个指针p2、p3和p5，表示下一个丑数是当前丑数乘以2、3或5得到，初始时三个指针都指向第一个丑数（即1），然后从小到大依次求出每个丑数，直到求出第N个丑数为止。
    具体实现步骤如下：
    
    定义一个数组dp，dp[i]表示第i个丑数，初始化dp[1] = 1。
    定义三个指针p2、p3和p5，初始时都指向第一个丑数，即p2 = p3 = p5 = 1。
    定义一个变量next，表示下一个要求的丑数的位置，初始时为2。
    
    循环求出从第二个丑数到第N个丑数。
    
    1）dp[next] = min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5)，求出下一个丑数。
    
    2）如果dp[next]等于dp[p2] * 2，则p2++；
    如果`dp[next]`等于`dp[p3] * 3`，则`p3++`；
    如果`dp[next]`等于`dp[p5] * 5`，则`p5++`；

    3）next++。
    
    返回dp[N]即可。
    
    需要注意的是，当计算新的丑数时可能会出现重复的情况，例如2×3=6和3×2=6都可以得到6这个丑数，为避免重复需要进行去重。
  */
  int GetUglyNumber_Solution(int index) {
    if (index <= 0) {
      return 0;
    }
    vector<int> dp(index + 1, 0);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= index; i++) {
      dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
      if (dp[i] == dp[p2] * 2) {
        p2++;
      }
      if (dp[i] == dp[p3] * 3) {
        p3++;
      }
      if (dp[i] == dp[p5] * 5) {
        p5++;
      }
    }
    return dp[index];
  }
};

int main() {
  Solution s;
  for (size_t i = 1; i <= 10; ++i) {
    cout << s.GetUglyNumber_Solution(i) << " ";
  }
  cout << endl;
  return 0;
}
