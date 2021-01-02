// NC119 最小的k个数
// Created by liupan on 2021/1/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        // 如果长度为0或者k大于等于长度，直接返回input
        if (!len || k > len) return vector<int>();
        for (size_t i = 0; i < k; ++i) {
            // 找出最小的数
            int flag = -1, flagPos = -1;
            for (size_t j = i; j < input.size(); ++j) {
                if (j == i || input[j] < flag) {
                    flag = input[j];
                    flagPos = j;
                }
            }
            // 如果找到位置，且不是本身位置，即i != flagPos，则交换数字
            if (flagPos != -1 && i != flagPos) {
                swap(input[i], input[flagPos]);
            }
        }
        // 返回前k个数
        return vector<int>(input.begin(), input.begin() + k);
    }
};

int main() {
    Solution s;
    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> ret = s.GetLeastNumbers_Solution(input, 4);
    for_each(ret.begin(), ret.end(), [](int val) {
        cout << val << " ";
    });
}
