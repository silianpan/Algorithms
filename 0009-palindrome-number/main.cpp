// 0009 回文数
// Created by liupan on 2020/12/29.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况排除
        // 情况1：x < 0
        // 情况2：x末尾为0，且不等于0
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        return x == revert(x);
    }

private:
    /**
     * 反转x
     * @param x
     * @return
     */
    int revert(int x) {
        int ret = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop >= 7)) return 0;
            if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop <= -8)) return 0;
            ret = ret * 10 + pop;
        }
        return ret;
    }
};

int main() {
    Solution s;
    bool ret = s.isPalindrome(2147483647);
    cout << boolalpha << ret << endl;
}
