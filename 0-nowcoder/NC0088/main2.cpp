// NC88 寻找第K大
// Created by liupan on 2021/1/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 快速排序解法
     * @param a
     * @param left
     * @param right
     * @param K
     * @return
     */
    int fun(vector<int> &a, int left, int right, int K) {
        int tmp = a[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (a[j] > tmp) swap(a[i++], a[j]);
        }
        swap(a[i], a[right]);
        return i;
    }
    int findKth(vector<int> a, int n, int K) {
        // write code here
        int start = 0;
        int end = n - 1;
        int p;
        while (start < end) {
            p = fun(a, start, end, K);
            if (p == K - 1) return a[p];
            if (p > K - 1) {
                end = p - 1;
            }
            if (p < K - 1) {
                start = p;
            }
        }
        return a[p];
    }
};

int main() {
    Solution s;
    vector<int> a = {1332802, 1177178, 1514891, 871248, 753214, 123866, 1615405, 328656, 1540395, 968891, 1884022,
                     252932, 1034406, 1455178, 821713, 486232, 860175, 1896237, 852300, 566715, 1285209, 1845742,
                     883142, 259266, 520911, 1844960, 218188, 1528217, 332380, 261485, 1111670, 16920, 1249664, 1199799,
                     1959818, 1546744, 1904944, 51047, 1176397, 190970, 48715, 349690, 673887, 1648782, 1010556,
                     1165786, 937247, 986578, 798663};
    sort(a.begin(), a.end());
    int ret = s.findKth(a, 49, 24);
    cout << ret << endl;
}
