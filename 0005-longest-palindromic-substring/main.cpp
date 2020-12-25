// 0005 最长回文子串
// Created by liupan on 2020/12/25.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        size_t len = s.length();
        if (s.length() < 2) {
            return s;
        }

        size_t maxLen = 1, begin = 0;
        for (size_t i = 0; i < len - 1; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                if (j - i + 1 > maxLen && isPalindromic(s, i, j)) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }

private:
    bool isPalindromic(string subStr, int left, int right) {
        while (left < right) {
            if (subStr[left] != subStr[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution s;
    string ret = s.longestPalindrome("cbbd");
    cout << ret << endl;
}

