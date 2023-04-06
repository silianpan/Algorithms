//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/13
// @brief: 0027 移除元素
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;
        int i = 0;
        while (i < len && nums[i] != val) i++;
        int n = i;
        for (int j = n + 1; j < len; ++j) {
            if (nums[j] != val) {
                int tmp = nums[i];
                nums[i++] = nums[j];
                nums[j] = tmp;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution s;
    int ret = s.removeElement(nums, val);
    for (int i = 0; i < ret; ++i) {
        cout << nums[i] << " ";
    }
}
