// 0011 盛最多水的容器
// Created by liupan on 2020/12/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 优化：双指针模式，从两边同时往里循环
     * @param height
     * @return
     */
    int maxArea(vector<int> &height) {
        int ret = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int tmp = min(height[i], height[j]) * (j - i);
            if (tmp > ret) ret = tmp;
            if (height[i] < height[j]) i++;
            else j--;
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

