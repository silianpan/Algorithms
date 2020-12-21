//
// Created by liupan on 2020/12/20.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        multimap<int, int> numMap;
        size_t maxSize = nums.size();
        for (size_t i = 0; i < maxSize; ++i) {
            numMap.insert(pair<int, int>(nums[i], i));
        }
        vector<int> ret;
        for (map<int, int>::reverse_iterator it = numMap.rbegin(); it != numMap.rend(); ++it) {
            map<int, int>::iterator findIt = numMap.find(target - it->first);

            if (findIt != numMap.end() and it->second != findIt->second) {
                ret.push_back(findIt->second);
                ret.push_back(it->second);
                break;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
//    vector<int> nums = {2, 7, 11, 15};
//    int target = 9;
    vector<int> nums = {-1, 3, 4, 6, 4, 10, 12, 7, 11, 15, 32};
    int target = 31;
//    vector<int> nums = {3, 3};
//    int target = 6;
    vector<int> ret = s.twoSum(nums, target);
    for_each(ret.begin(), ret.end(), [](int value) { cout << value << " "; });
}
