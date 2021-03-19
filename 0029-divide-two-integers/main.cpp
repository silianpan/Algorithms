//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/25
// @brief: 0029 两数相除
//

#include <iostream>

using namespace std;

class Solution {
public:
//    int sameSign(int a, int b) {
//        return a ^ b >= 0;
//    }
//    // 0和负认为符号相同
//    int sameSign(int a, int b) {
//        if ((a > 0 && b > 0)
//            || (a <= 0 && b <= 0))
//            return 1;
//        else
//            return 0;
//    }

    int divide(int dividend, int divisor) {
        // 特例
        if (dividend == 0 || divisor == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            else if (dividend == INT_MAX) return INT_MIN;
            else return -dividend;
        }
        // 判断符号是否相同
        bool flag = (dividend > 0 && divisor > 0) || (dividend <= 0 && divisor <= 0);
        // 全部取正，不能取反，会溢出，比如INT_MIN
//        if (dividend < 0) dividend = -dividend;
//        if (divisor < 0) divisor = -divisor;
        // 循环
        int pool = flag ? dividend - divisor : dividend + divisor;
        int ret = 0;
        while ((dividend > 0 && pool >= 0) || (dividend < 0 && pool <= 0)) {
            ++ret;
            pool = flag ? pool - divisor : pool + divisor;
        }
        return flag ? ret : -ret;
    }
};

int main() {
    Solution s;
    int ret = s.divide(3, 3);
    cout << ret << endl;
}
