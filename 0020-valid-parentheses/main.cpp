// 0020 有效的括号
// Created by liupan on 2021/1/11.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (char ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                tmp.push(ch);
            } else if (ch == ')') {
                if (tmp.empty()) return false;
                char top = tmp.top();
                if (top != '(') return false;
                tmp.pop();
            } else if (ch == '}') {
                if (tmp.empty()) return false;
                char top = tmp.top();
                if (top != '{') return false;
                tmp.pop();
            } else if (ch == ']') {
                if (tmp.empty()) return false;
                char top = tmp.top();
                if (top != '[') return false;
                tmp.pop();
            }
        }
        return tmp.empty();
    }
};

int main() {
    Solution s;
    bool ret = s.isValid("]");
    cout << boolalpha << ret << endl;
}
