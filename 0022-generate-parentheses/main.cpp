// 0022 括号生成
// Created by liupan on 2021/1/13.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        // n==0特判
        if (!n) return ret;
        generateParenthesis("", 0, 0, n, ret);
        return ret;
    }
    /**
     * 深度优先
     * @param curStr 当前递归得到的结果
     * @param left 左括号已经用了几个
     * @param right 右括号已经用了几个
     * @param n 左括号、右括号一共得用几个
     * @param ret 结果集
     */
    void generateParenthesis(string curStr, int left, int right, int n, vector<string> &ret) {
        if (left == n && right == n) ret.push_back(curStr);
        // 剪枝
        if (left < right) return;
        if (left < n) generateParenthesis(curStr + "(", left + 1, right, n, ret);
        if (right < n) generateParenthesis(curStr + ")", left, right + 1, n, ret);
    }
};

int main() {
    Solution s;
    vector<string> ret = s.generateParenthesis(3);
    for_each(ret.begin(), ret.end(), [](string val) {
        cout << val << endl;
    });
}
