//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/10
// @brief: 0026 删除排序数组中的重复项
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 双指针优化
     * @param nums
     * @return
     */
    int removeDuplicates(vector<int> &nums) {
        // 特例
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution s;
    int ret = s.removeDuplicates(nums);
    for (int i = 0; i < ret; ++i) {
        cout << nums[i] << " ";
    }
}
