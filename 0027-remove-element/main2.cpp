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
    /**
     * 当我们遇到 nums[i] = valnums[i]=val 时，我们可以将当前元素与最后一个元素进行交换，并释放最后一个元素。这实际上使数组的大小减少了 1。
     * 请注意，被交换的最后一个元素可能是您想要移除的值。但是不要担心，在下一次迭代中，我们仍然会检查这个元素。
     * @param nums
     * @param val
     * @return
     */
    int removeElement(vector<int> &nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;
        int i = 0;
        while (i < len) {
            if (nums[i] == val) {
                nums[i] = nums[len - 1];
                --len;
            } else {
                ++i;
            }
        }
        return len;
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
