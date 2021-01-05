// 0017 电话号码的字母组合
// Created by liupan on 2021/1/5.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    const unordered_map<char, string> numMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
public:
    vector<string> letterCombinations(string digits) {
        // 大小等于0
        if (!digits.length()) return {};
        vector<string> ret;
        // 大小等于1
        if (digits.length() == 1) {
            auto tmp = numMap.find(digits[0]);
            if (tmp == numMap.end()) return {};
            for (char ch: tmp->second) {
                ret.push_back(string(1, ch));
            }
            return ret;
        }
        // 第一次两个数字之间组合
        ret = letterCombinations(digits[0], digits[1]);
        // 第二次不断和新的数字进行组合
        for (size_t i = 2; i < digits.length(); ++i) {
            ret = letterCombinations(ret, digits[i]);
        }
        return ret;
    }

    /**
     * 两个数字字符之间组合
     * @param num1
     * @param num2
     * @return
     */
    vector<string> letterCombinations(char num1, char num2) {
        auto tmp1 = numMap.find(num1);
        auto tmp2 = numMap.find(num2);
        if (tmp1 == numMap.end() || tmp2 == numMap.end()) return {};
        vector<string> ret;
        for (char ch1: tmp1->second) {
            for (char ch2: tmp2->second) {
                ret.push_back({ch1, ch2});
            }
        }
        return ret;
    }

    /**
     * 组合的中间结果和新的字符数字组合
     * @param mid
     * @param numNew
     * @return
     */
    vector<string> letterCombinations(vector<string> &mid, char numNew) {
        auto tmpNew = numMap.find(numNew);
        if (tmpNew == numMap.end()) return mid;
        vector<string> ret;
        for (size_t i = 0; i < mid.size(); ++i) {
            for (char chNew: tmpNew->second) {
                ret.push_back(mid[i] + chNew);
            }
        }
        mid.clear();
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> ret = s.letterCombinations("234");
    for_each(ret.begin(), ret.end(), [](string val) {
        cout << val << " ";
    });
}
