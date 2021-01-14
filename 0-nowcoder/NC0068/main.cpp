// NC68 跳台阶
// Created by liupan on 2021/1/15.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        int ret = 0;
        jumpFloor(0, number, ret);
        return ret;
    }

    void jumpFloor(int curSum, int number, int &ret) {
        if (curSum == number) {
            ++ret;
            return;
        };
        if (curSum > number) return;
        jumpFloor(curSum + 1, number, ret);
        jumpFloor(curSum + 2, number, ret);
    }
};

int main() {
    Solution s;
    int ret = s.jumpFloor(4);
    cout << ret << endl;
}

