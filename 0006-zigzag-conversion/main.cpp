// 0006 Z 字形变换
// Created by liupan on 2020/12/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        // 如果为1，直接返回原字符串
        if (numRows <= 1 || numRows >= len) return s;

        // 1. 计算分配二维数组空间
        // 以z字竖线字符数+中间字符数作为一次循环，计算列数
        int columns = (len / (2 * numRows - 2)) * (numRows - 1);
        // 如果 除以 （z字竖线字符数+中间字符数）有余数，则最终列数+1
        if (len % (2 * numRows - 2) != 0) {
            columns++;
        }
        // 2. vector二维数组，并初始化
        vector<vector<string>> ret(numRows, vector<string>(columns));
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < columns; ++j) {
                ret[i][j] = "";
            }
        }

        // 3. 遍历字符串，并赋值给二维数组相应位置
        // 步长为numRows - 1
        int step = 0;
        for (int i = 0; i < len; i += (2 * numRows - 2)) {
            // z字竖线的字符
            int j = 0;
            for (; j < numRows; ++j) {
                ret[j][step] = s[i + j];
            }
            // z字中间的字符
            for (int k = 0; k < numRows - 2; ++k) {
                ret[numRows - 2 - k][step + 1 + k] = s[i + j + k];
            }
            step += numRows - 1;
        }
        // 4. 最后将vector二维数组赋值给字符串
        string retStr = "";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if ("" != ret[i][j]) {
                    retStr += ret[i][j];
                }
            }
        }
        return retStr;
    }
};

int main() {
    Solution s;
    string ret = s.convert("LEETCODEISHIRING", 3);
    cout << ret << endl;
}
