// NC22 合并两个有序的数组
// Created by liupan on 2021/1/12.
//

#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (B[j] < A[i]) {
                for (int k = m - 1; k >= i; --k) {
                    A[k + 1] = A[k];
                }
                A[i++] = B[j++];
                ++m;
            } else if (B[j] == A[i]) {
                for (int k = m - 1; k >= i + 1; --k) {
                    A[k + 1] = A[k];
                }
                A[i + 1] = B[j];
                ++i;
                ++j;
                ++m;
            } else {
                ++i;
            }
        }
        while (j < n) {
            A[i++] = B[j++];
        }
    }
};

int main() {
    int A[11] = {4, 7, 9, 12, 15, 16};
    int B[5] = {1, 3, 5, 6, 10};
    Solution s;
    s.merge(A, 6, B, 5);
    for (int num: A) {
        cout << num << " ";
    }
}
