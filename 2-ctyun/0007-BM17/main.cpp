/**
nowcoder BM17 二分查找-I
请实现无重复数字的升序数组的二分查找

给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target
，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0
开始），否则返回 -1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param nums int整型vector
   * @param target int整型
   * @return int整型
   */
  int search(vector<int> &nums, int target) {
    // write code here
    if (nums.empty())
      return -1;

    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
      int k = (end + start) / 2;

      if (target == nums[k])
        return k;
      if (target > nums[k]) {
        start = k + 1;
      } else if (target < nums[k]) {
        end = k - 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> v = {-1, 0, 3, 4, 6, 10, 13, 14};
  cout << s.search(v, 13) << endl;
  return 0;
}
