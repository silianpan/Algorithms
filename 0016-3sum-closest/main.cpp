// 0016 最接近的三数之和
// Created by liupan on 2021/1/4.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        // 绝对值结果
        int absRet = INT_MAX;
        int ret = 0;
        for (size_t i = 0; i < len; ++i) {
            // 若当前数和前一个数相同，continue
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 减去target剩余
            int left = nums[i] - target;
            for (size_t j = i + 1; j < len; ++j) {
                // 若当前数和前一个数相同，continue
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                for (size_t k = len - 1; k > j; --k) {
                    if (k < len - 1 && nums[k] == nums[k + 1]) continue;
                    int absTmp = abs(left + nums[j] + nums[k]);
                    if (absTmp < absRet) {
                        absRet = absTmp;
                        ret = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,2,1,-3};
    int ret = s.threeSumClosest(nums, 1);
    cout << ret << endl;
}
