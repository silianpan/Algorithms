// 0012 整数转罗马数字
// Created by liupan on 2021/1/1.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if (num < 1 || num > 3999) return "";
        int i = 1;
        vector<string> ret;
        unordered_map<int, string> specMap = {
                {4, "IV"},
                {9, "IX"},
                {40, "XL"},
                {90, "XC"},
                {400, "CD"},
                {900, "CM"},
                {1, "I"},
                {5, "V"},
                {10, "X"},
                {50, "L"},
                {100, "C"},
                {500, "D"},
                {1000, "M"}
        };
        while (num > 0) {
            // 余数 * i
            int pop = (num % 10) * i;
            // 特殊情况
            auto tmp = specMap.find(pop);
            if (tmp != specMap.end()) {
                ret.push_back(tmp->second);
            } else {
                // 对应三种情况：个位、十位、百位、千位
                int tmpLop = -1;
                string tmpC1 = "", tmpC5 = "";
                if (i == 1) {
                    // 个位
                    tmpLop = 5;
                    tmpC1 = "I";
                    tmpC5 = "V";
                } else if (i == 10) {
                    // 十位
                    tmpLop = 50;
                    tmpC1 = "X";
                    tmpC5 = "L";
                } else if (i == 100) {
                    // 百位
                    tmpLop = 500;
                    tmpC1 = "C";
                    tmpC5 = "D";
                } else {
                    // 千位
                    for (int j = 0; j < pop / 1000; ++j) {
                        ret.push_back("M");
                    }
                }

                if (tmpLop != -1) {
                    // 大于相应位数高位数字，比如5、50、500
                    if (pop > tmpLop) {
                        // 有多少个相应位数
                        for (int j = 0; j < (pop - tmpLop) / i; ++j) {
                            ret.push_back(tmpC1);
                        }
                        // 添加相应位数罗马数字
                        ret.push_back(tmpC5);
                    } else {
                        // 小于相应为数，直接添加相应位数低位罗马数字
                        for (int j = 0; j < pop / i; ++j) {
                            ret.push_back(tmpC1);
                        }
                    }
                }
            }

            // 除以10
            num /= 10;
            i *= 10;
        }
        // 组装结果
        string retStr = "";
        for (vector<string>::reverse_iterator it = ret.rbegin(); it != ret.rend(); ++it) {
            retStr += *it;
        }
        return retStr;
    }
};

int main() {
    Solution s;
    string ret = s.intToRoman(140);
    cout << ret << endl;
}

