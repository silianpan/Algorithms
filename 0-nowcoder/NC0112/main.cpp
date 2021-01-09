// NC112 进制转换
// Created by liupan on 2021/1/9.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 进制转换
     * @param M int整型 给定整数
     * @param N int整型 转换到的进制
     * @return string字符串
     */
    string solve(int M, int N) {
        // write code here
        unordered_map<int, char> tmpMap = {
                {10, 'A'},
                {11, 'B'},
                {12, 'C'},
                {13, 'D'},
                {14, 'E'},
                {15, 'F'}
        };
        if (N == 10 || N < 2 || N > 16) return to_string(M);
        string ret = "";
        int tmpM = M < 0 ? -M : M;
        while (tmpM) {
            int pop = tmpM % N;
            string popStr = "";
            if (pop <= N && pop >= 10) {
                popStr = tmpMap.find(pop)->second;
            } else {
                popStr = to_string(pop);
            }
            ret += popStr;
            tmpM /= N;
        }
        if (M < 0) ret += "-";
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution s;
    string ret = s.solve(-4, 3);
    cout << ret << endl;
}
