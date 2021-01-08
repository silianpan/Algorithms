// 0018 四数之和
// Created by liupan on 2021/1/6.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (size_t i = 0; i < len; ++i) {
            // 若当前数和前一个数相同，跳过
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (size_t j = i + 1; j < len; ++j) {
                // 若当前数和前一个数相同，跳过
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (size_t k = j + 1; k < len; ++k) {
                    // 若当前数和前一个数相同，跳过
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    int left = target - nums[i] - nums[j] - nums[k];
                    size_t m = len - 1;

                    // 若当前m的值大于剩下的值，说明太大了，要往前移动m
                    while (m > k && nums[m] > left) --m;

                    // 若m和k碰头，说明已经找不到合适的k了（因为k和m越往后越大），直接跳出
                    if (k == m) break;
                    if (left == nums[m]) ret.push_back({nums[i], nums[j], nums[k], nums[m]});
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ret = s.fourSum(nums, 0);
    for_each(ret.begin(), ret.end(), [](vector<int> item) {
        for_each(item.begin(), item.end(), [](int val) {
            cout << val << " ";
        });
        cout << "\n";
    });
}
