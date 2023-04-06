// 0007 整数反转
// Created by liupan on 2020/12/25.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            /**
             * 事先判断是否溢出
             * INT_MAX = 2^31 - 1 = 2147483647
             * INT_MIN= - 2^31 = -2147483648
             */
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main() {
    Solution s;
    int ret = s.reverse(-1534236469);
    printf("%d", ret);
}
