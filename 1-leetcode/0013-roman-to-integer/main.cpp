// 0013 罗马数字转整数
// Created by liupan on 2021/1/1.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> specMap = {
                {"IV", 4},
                {"IX", 9},
                {"XL", 40},
                {"XC", 90},
                {"CD", 400},
                {"CM", 900},
                {"I", 1},
                {"V", 5},
                {"X", 10},
                {"L", 50},
                {"C", 100},
                {"D", 500},
                {"M", 1000}
        };
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            // 判断当前位和下一位是否符合特殊情况
            if (i + 1 < s.length() &&
                ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))) {
                ret += specMap.find(s.substr(i, 2))->second;
                i++;
            } else {
                ret += specMap.find(s.substr(i, 1))->second;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    int ret = s.romanToInt("MCMXCIV");
    cout << ret << endl;
}
