//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/15
// @brief: NC93 设计LRU缓存结构
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> > &operators, int k) {
        vector<int> cacheKey, cacheValue, result;
        for (int i = 0; i < operators.size(); ++i) {
            if (operators[i][0] == 1) {
                set(operators[i][1], operators[i][2], cacheValue, cacheKey, k);
            } else if (operators[i][0] == 2) {
                get(operators[i][1], cacheValue, cacheKey, result);
            }
        }
        return result;
    }

    void set(int k, int v, vector<int> &cacheValue, vector<int> &cacheKey, int n) {
//        if (cacheValue.size() < n) {
//            cacheKey.push_back(k);
//            cacheValue.push_back(v);
//        } else {
//            cacheKey.erase(cacheKey.begin());
//            cacheValue.erase(cacheValue.begin());
//            cacheKey.insert(cacheKey.begin(), k);
//            cacheValue.insert(cacheValue.begin(), v);
//        }
        if (cacheValue.size() >= n) {
            cacheKey.erase(cacheKey.begin());
            cacheValue.erase(cacheValue.begin());
        }
        cacheKey.push_back(k);
        cacheValue.push_back(v);
    }

    void get(int k, vector<int> &cacheValue, vector<int> &cacheKey, vector<int> &result) {
        int t = -1;
        for (int i = 0; i < cacheKey.size(); ++i) {
            if (k == cacheKey[i]) {
                t = i;
                break;
            }
        }
        if (t == -1) {
            result.push_back(-1);
        } else {
            int key = cacheKey[t];
            int value = cacheValue[t];
            cacheKey.erase(cacheKey.begin() + t);
            cacheValue.erase(cacheValue.begin() + t);
            cacheKey.push_back(key);
            cacheValue.push_back(value);
            result.push_back(value);
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> operators;
    vector<int> a1 = {1, 1, 1};
    vector<int> a2 = {1, 2, 2};
    vector<int> a3 = {1, 3, 2};
    vector<int> a4 = {2, 1};
    vector<int> a5 = {1, 4, 4};
    vector<int> a6 = {2, 2};
    operators.push_back(a1);
    operators.push_back(a2);
    operators.push_back(a3);
    operators.push_back(a4);
    operators.push_back(a5);
    operators.push_back(a6);
    vector<int> ret = s.LRU(operators, 3);
    for_each(ret.begin(), ret.end(), [](int val) {
        cout << val << " ";
    });
}


