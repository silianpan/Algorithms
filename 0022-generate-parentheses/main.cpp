// 0022 括号生成
// Created by liupan on 2021/1/13.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> tmp;
        vector<string> ret;
        generateParenthesis(n, '(', tmp, ret);
        generateParenthesis(n, ')', tmp, ret);
    }

    void generateParenthesis(int n, char ch, stack<char> tmp, vector<string> &ret) {
        if (n == 0) return;
        if (tmp.empty()) {
            tmp.push(ch);
        }
    }
};

int main() {

}
