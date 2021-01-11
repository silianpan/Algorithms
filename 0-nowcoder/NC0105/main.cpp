// NC105 二分查找
// Created by liupan on 2021/1/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int> &a) {
        // write code here
        return upper_bound_(0, n - 1, n, v, a);
    }

    int upper_bound_(int start, int end, int n, int v, vector<int> &a) {
        int mid = (end + start + 1) / 2;
        if (start > end) return n + 1;
        if (a[mid] >= v && a[mid - 1] < v) return mid + 1;
        if (a[mid] < v) return upper_bound_(mid + 1, end, n, v, a);
        else return upper_bound_(start, mid - 1, n, v, a);
    }
};

int main() {
    Solution s;
    vector<int> a = {2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 7, 7, 9, 9, 9, 10, 10, 12, 14, 16, 17, 18, 18, 18, 19, 22, 23, 23,
                     26, 26, 26, 26, 28, 28, 29, 29, 29, 32, 33, 35, 36, 38, 39, 39, 40, 41, 46, 47, 47, 47, 49, 50, 54,
                     55, 55, 55, 56, 57, 57, 58, 58, 58, 59, 61, 61, 62, 62, 62, 62, 63, 63, 67, 67, 69, 70, 70, 71, 72,
                     74, 75, 76, 79, 84, 85, 85, 86, 89, 92, 93, 93, 93, 94, 94, 95, 97, 97, 97, 97, 97, 99};
    int ret = s.upper_bound_(100, 100, a);
//    vector<int> a = {1,2,4,4,5,6};
//    int ret = s.upper_bound_(6, 5, a);
    cout << ret << endl;
}

