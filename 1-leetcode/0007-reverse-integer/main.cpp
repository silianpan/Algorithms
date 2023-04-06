// 0007 整数反转
// Created by liupan on 2020/12/25.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x < INT_MIN || x > INT_MAX || x == 0) {
            return 0;
        }

        string tmpStr;
        if (x < 0) {
            int tmp = -x;
            tmpStr = to_string(tmp);
            std::reverse(tmpStr.begin(), tmpStr.end());
            tmpStr = "-" + tmpStr;
        } else {
            tmpStr = to_string(x);
            std::reverse(tmpStr.begin(), tmpStr.end());
        }

        /**
         * 该方案不可行
         * atoi有可能越界，需要判断atoi是否越界
         */
        int ret = atoi(tmpStr.c_str());
        if (ret < INT_MIN || ret > INT_MAX) {
            return 0;
        }
        return ret;
    }
};

int main() {
    Solution s;
    int ret = s.reverse(1534236469);
    printf("%d", ret);
}
