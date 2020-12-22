// 0003 无重复字符的最长子串
// Created by liupan on 2020/12/22.
//
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ret, tmp;
        int retLen = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            auto it = ret.find(s[i]);
            if (it != ret.end()) {
                // 找到重复了
                if (ret.size() > retLen) {
                    retLen = ret.size();
                }
                tmp.clear();
                for (size_t j = it->second + 1; j <= i; ++j) {
                    tmp.insert(pair<char, int>(s[j], j));
                }
                ret = tmp;
            } else {
                // 没有找到重复
                ret.insert(pair<char, int>(s[i], i));
                retLen = ret.size();
            }
        }
        tmp.clear();
        ret.clear();
        return retLen;
    }
};

int main() {
    Solution s;
    int ret = s.lengthOfLongestSubstring("dvdf");
    cout << ret << endl;
}
