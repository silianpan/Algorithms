//
// Copyright (c) 2021 Seals Studio, All rights reserved.
// @license: GPL
// @author: silianpan
// @email: liu.pan@silianpan.cn
// @date 2021/2/10
// @brief: NC16 判断二叉树是否对称
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isSymmetric(TreeNode *root) {
        // write code here
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left ^ !right) return false;
        if (left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    void preOrder(TreeNode *root) {
        if (root) {
            cout << root->val << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main() {
    TreeNode *root = new TreeNode;
    root->val = 1;
    TreeNode *left = new TreeNode;
    left->val = 2;
    TreeNode *right = new TreeNode;
    right->val = 2;
    root->left = left;
    root->right = right;

    Solution s;
    s.preOrder(root);
    bool ret = s.isSymmetric(root);
    cout << boolalpha << ret << endl;
}