//
// Created by liupan on 2020/12/20.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> numMap;
        for (size_t i = 0; i < nums.size(); ++i) {
            auto it = numMap.find(target - nums[i]);
            if (it != numMap.end()) {
                return {it->second, static_cast<int>(i)};
            }
            numMap.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main() {
    Solution s;
//    vector<int> nums = {2, 7, 11, 15};
//    int target = 9;
//    vector<int> nums = {-1, 3, 4, 6, 4, 10, 12, 7, 11, 15, 32};
//    int target = 31;
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> ret = s.twoSum(nums, target);
    for_each(ret.begin(), ret.end(), [](int value) { cout << value << " "; });
}
