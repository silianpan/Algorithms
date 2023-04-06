// 0015 三数之和
// Created by liupan on 2021/1/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 优化版本
     * @param nums
     * @return
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < len; ++i) {
            // 保证当前数和上一个数不同，如果相同则continue
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 目标值
            int target = -nums[i];
            size_t k = len - 1;
            for (size_t j = i + 1; j < len; ++j) {
                // 保证当前数和上一个数不同
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 如果后面两位数之和大于target，说明num[k]太大，需要向前移动k
                while (j < k && nums[j] + nums[k] > target) --k;

                // 如果k移动到j位置了，说明当前j循环结束了；
                // 如果后两位数之和都小于target（nums[j] + nums[k] < target），说明nums[k]太小了，向前移动k，再也找不到更大的nums[k]了，不能结束，要继续j++
                if (j == k) break;

                if (nums[j] + nums[k] == target) ret.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    auto ret = s.threeSum(nums);
    for_each(ret.begin(), ret.end(), [](vector<int> item) {
        for_each(item.begin(), item.end(), [](int val) {
            cout << val << " ";
        });
        cout << "\n";
    });
}

