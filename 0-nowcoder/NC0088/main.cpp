// NC88 寻找第K大
// Created by liupan on 2021/1/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        // 只求前K个最小值
        for (size_t i = 0; i < K; ++i) {
            // 查找最小值，并记录索引
            int max, maxIndex;
            for (size_t j = i; j < a.size(); ++j) {
                if (j == i || a[j] > max) {
                    max = a[j];
                    maxIndex = j;
                }
            }
            // 交换
            swap(a[i], a[maxIndex]);
        }
        return a[K - 1];
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
