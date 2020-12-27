// 0008 字符串转换整数 (atoi)
// Created by liupan on 2020/12/27.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        s = trim(s);
        // 1. 如果为空，直接返回0
        if (s.length() == 0) return 0;
        // 2. 如果是非数字字符，且非+、-，直接返回0
        if (!isdigit(s[0]) && s[0] != '-' && s[0] != '+') return 0;
        int ret = 0;
        bool neg = s[0] == '-';
        int i = !isdigit(s[0]) ? 1 : 0;
        while (i < s.length() && isdigit(s[i])) {
            int pop = s[i++] - '0';
            // 如果是正整数，如果大于INT_MAX，直接返回INT_MAX
            if (!neg && (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop >= 7))) return INT_MAX;
            // 如果是负整数，如果小于INT_MIN，直接返回INT_MIN
            if (neg && (-ret < INT_MIN / 10 || (-ret == INT_MIN / 10 && -pop <= -8))) return INT_MIN;
            ret = ret * 10 + pop;
        }
        return neg ? -ret : ret;
    }

private:
    string& trim(string &s) {
        if (s.empty()) return s;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }
};

int main() {
    Solution s;
    int ret = s.myAtoi("-2147483648");
    printf("%d", ret);
}