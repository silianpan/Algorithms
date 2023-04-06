// 0011 盛最多水的容器
// Created by liupan on 2020/12/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 此算法超出时间限制
     * @param height
     * @return
     */
    int maxArea(vector<int> &height) {
        size_t len = height.size();
        int ret = 0;
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                int tmp = min(height[i], height[j]) * (j - i);
                if (tmp > ret) ret = tmp;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> height = {1,2,1};
    int ret = s.maxArea(height);
    cout << ret << endl;
}

