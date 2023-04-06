// 0015 三数之和
// Created by liupan on 2021/1/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 超出时间限制
     * @param nums
     * @return
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                for (size_t k = j + 1; k < len; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> tmp = {nums[i], nums[j], nums[k]};
                        if (!count(ret.begin(), ret.end(), tmp)) ret.push_back(tmp);
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    auto ret = s.threeSum(nums);
    for_each(ret.begin(), ret.end(), [](vector<int> item) {
        for_each(item.begin(), item.end(), [](int val) {
            cout << val << " ";
        });
        cout << "\n";
    });
}

