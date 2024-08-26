#include <iostream>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (size_t i = 0; i < nums.size(); ++i) {
      int start = nums[i];
      for (size_t j = i + 1; j < nums.size(); ++j) {
        if (nums[j] == target - start) {
          return {static_cast<int>(i), static_cast<int>(j)};
        }
      }
    }
    return {};
  }
};

int main() {
  Solution s;
  vector<int> nums = {2, 7, 11, 15};
  vector<int> ret = s.twoSum(nums, 9);
  for (size_t i = 0; i < ret.size(); ++i) {
    cout << ret[i] << " ";
  }
  cout << endl;
}
