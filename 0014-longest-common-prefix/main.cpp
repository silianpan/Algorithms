// 0014 最长公共前缀
// Created by liupan on 2021/1/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        char flagCh;
        size_t j = 0;
        string ret = "";
        while (strs.size() > 0) {
            for (size_t i = 0; i < strs.size(); ++i) {
                string str = strs[i];
                // 将第一个字符串的每个字符作为标志位flagCh
                if (i == 0) {
                    // j索引第一个字符串每个字符
                    if (j < str.length()) {
                        flagCh = str[j];
                    } else {
                        return ret;
                    }
                }

                // j索引其他字符串字符和标志位比较，如果不相同，直接返回
                if (str[j] != flagCh) {
                    return ret;
                }
            }
            // j索引字符都相同，进行下一个字符比较
            j++;
            // 将标志字符添加到结果中
            ret += flagCh;
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"dog", "racecar", "car"};
    string ret = s.longestCommonPrefix(strs);
    cout << ret << endl;
}

