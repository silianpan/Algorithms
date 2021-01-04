// 0016 最接近的三数之和
// Created by liupan on 2021/1/4.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        // 最好的求和结果
        int sumBest = 10e7;

        for (size_t i = 0; i < len; ++i) {
            // 若当前数和前一个数相同，continue
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            size_t j = i + 1, k = len - 1;
            while (j < k) {
                // 就和
                int sum = nums[i] + nums[j] + nums[k];
                // 如果sum等于target，即绝对值为0，是最接近的，直接返回和
                if (sum == target) return sum;
                // 判断最小的绝对值，更新最好的就和结果sumBest
                if (abs(sum - target) < abs(sumBest - target)) {
                    sumBest = sum;
                }
                // 若和大于target，说明向左移动k，向右的话，sum会更大，abs也会更大
                if (sum > target) {
                    int k0 = k - 1;
                    while (k0 > j && nums[k0] == nums[k]) --k0;
                    k = k0;
                } else {
                    // 若和小于target，说明向右移动j，向左的话，sum会更小，abs也会更大
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j]) ++j0;
                    j = j0;
                }
            }
        }
        return sumBest;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,2,1,-4};
    int ret = s.threeSumClosest(nums, 1);
    cout << ret << endl;
}
