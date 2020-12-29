// 0010 正则表达式匹配
// Created by liupan on 2020/12/29.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.find(".*") != string::npos) return true;
        int i = 0, j = 0;
        while (i < s.length() && j < p.length()) {
            if (i >= p.length()) return false;
            if (p[j] == '*' || p[j] == '.') {
                j++;
                i++;
                continue;
            }
            if (s[i] != p[j]) {
                i = 0;
                j++;
                continue;
            }
            i++;
            j++;
        }
        return i == s.length();
    }
};

int main() {
    Solution s;
    bool ret = s.isMatch("mississippi", "mis*is*p*.");
    cout << boolalpha << ret << endl;
}
