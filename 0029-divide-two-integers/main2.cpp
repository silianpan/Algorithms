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
        // 被除数=0
        if (dividend == 0) return 0;
        // 除数=1
        if (divisor == 1) return dividend;
        // 除数=-1
        if (divisor == -1) {
            // 被除数>最小值，即不等于最小值，最小值取反会溢出
            if (dividend > INT_MIN) return -dividend;
                // 等于最小值
            else return INT_MAX;
        }
        long a = dividend, b = divisor;
        int sign = 1;
        // sign表示判断a、b符号是否相同
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) sign = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long ret = div(a, b);
        // 判断ret值是否大于INT_MAX，在符号相同的情况下，即sign>0
        if (sign > 0) return ret > INT_MAX ? INT_MAX : ret;
        return -ret;
    }

    // a和b是正整数
    long div(long a, long b) {
        // 特例
        if (a < b) return 0;
        long tb = b; // 记录b
        long count = 1; // 至少等于1
        // 翻倍检查
        while ((tb + tb) <= a) {
            count = count + count;
            tb = tb + tb;
        }
        // 递归检查剩余
        return count + div(a - tb, b);
    }
};

int main() {
    Solution s;
    int ret = s.divide(3, 3);
    cout << ret << endl;
}
