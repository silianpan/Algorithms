//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/15
// @brief: 实现 strStr()
//

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 特例判断
        if (needle == "") return 0;
        // start标志子串开始位置
        int i = 0, j = 0, start = 0;
        while (i < haystack.size() && j < needle.size()) {
            // 当遇到相等时
            if (haystack[i] == needle[j]) {
                // 记录开始位置
                if (j == 0) start = i;
                // 继续下一次循环
                ++i;
                ++j;
            } else {
                // 当j不为0时，将i置为开始位置+1
                if (j != 0) i = start + 1;
                // 当j为0时，继续循环字符串
                else ++i;
                j = 0;
            }
        }
        // 当j不为结尾，返回-1，反之，返回开始位置
        return j != needle.size() ? -1 : start;
    }
};

int main() {
    Solution s;
    int ret = s.strStr("mississippi", "issip");
    cout << ret << endl;
}
