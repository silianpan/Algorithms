// NC61 两数之和
// Created by liupan on 2021/1/4.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        unordered_map<int, int> tmp;
        for (int i = 0; i < numbers.size(); ++i) {
            int left = target - numbers[i];
            auto f = tmp.find(left);
            if (f != tmp.end()) {
                // 存在
                return {f->second + 1, i + 1};
            }
            tmp.insert(pair<int, int>(numbers[i], i));
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 4};
    vector<int> ret = s.twoSum(nums, 6);
    for_each(ret.begin(), ret.end(), [](int val) {
        cout << val << " ";
    });
}
