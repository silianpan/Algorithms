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
    int removeDuplicates(vector<int> &nums) {
        int len = nums.size();
        int flag;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if (it == nums.begin() || *it != flag) {
                flag = *it;
                continue;
            }
            if (*it == flag) {
                flag = *it;
                nums.erase(it);
                --len;
                --it;
            }
        }
        return len;
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
