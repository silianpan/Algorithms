// 0004 寻找两个正序数组的中位数
// Created by liupan on 2020/12/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 2个为空的情况
        if (nums1.size() == 0 && nums2.size() == 0) {
            return 0.0;
        }
        // 其中一个为空的情况
        if (nums1.size() == 0) {
            if (nums2.size() % 2 == 0) {
                // 偶数位数
                return (nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2]) / 2.0;
            } else {
                return nums2[nums2.size() / 2];
            }
        }
        if (nums2.size() == 0) {
            if (nums1.size() % 2 == 0) {
                // 偶数位数
                return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.0;
            } else {
                return nums1[nums1.size() / 2];
            }
        }
        // 都不为空的情况
        size_t s1 = nums1.size();
        size_t s2 = nums2.size();
        size_t s = s1 + s2;
        size_t s3 = s / 2;

        /**
         * 解题方法：同时遍历两个数组，按从小到大保存至ret中，当ret的大小等于中间索引s3+1，跳出循环
         */
        vector<int> ret;
        size_t flag = 0;
        bool retFlag = false;
        size_t i = 0;
        for (; i < s1; ++i) {
            for (size_t j = flag; j < s2; ++j) {
                if (nums2[j] <= nums1[i]) {
                    ret.push_back(nums2[j]);
                    if (ret.size() >= s3 + 1) {
                        retFlag = true;
                        break;
                    }
                    flag++;
                } else {
                    ret.push_back(nums1[i]);
                    if (ret.size() >= s3 + 1) {
                        retFlag = true;
                    }
                    break;
                }
            }
            if (retFlag) {
                break;
            }
            if (flag >= s2) {
                break;
            }
        }

        /**
         * 当ret的大小还不满足中间索引s3+1时，添加nums1或者nums2中的数目
         */
        if (ret.size() < s3 + 1) {
            size_t curSize = ret.size();
            if (flag <= s2 - 1) {
                // 遍历添加nums2中的数
                for (size_t k = flag; k < s3 + 1 - curSize + flag; ++k) {
                    ret.push_back(nums2[k]);
                }
            } else if (i < s1) {
                // 遍历添加nums1中的数
                for (size_t k = i; k < s3 + 1 - curSize + i; ++k) {
                    ret.push_back(nums1[k]);
                }
            }
        }

        /**
         * 最后判断总大小奇偶，返回中位数
         */
        if (s % 2 == 0) {
            // 总大小为偶数
            return (ret[s3 - 1] + ret[s3]) / 2.0;
        } else {
            // 总大小为奇数
            return ret[s3];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,1};
    vector<int> nums2 = {1,2};

    double ret = s.findMedianSortedArrays(nums1, nums2);
    printf("%.2f", ret);
}
