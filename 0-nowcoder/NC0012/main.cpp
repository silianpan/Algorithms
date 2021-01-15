// NC12 重建二叉树
// Created by liupan on 2021/1/15.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty()) return nullptr;
        return reBuild(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }

    TreeNode* reBuild(vector<int> &pre, vector<int> &vin, int p1, int p2, int v1, int v2) {
        if (p1 > p2 || v1 > v2) return nullptr;
        // 求pre[p1]在vin中的位置，即pre[p1]的左子树共有size个节点
        int size = 0;
        for (int i = v1; i <= v2; ++i) {
            if (vin[i] == pre[p1]) {
                size = i - v1;
                break;
            }
        }
        TreeNode* root = new TreeNode(pre[p1]);
        // 画图分辨位置，当前的节点不能算在里面
        root->left = reBuild(pre, vin, p1 + 1, p1 + size, v1, v1 + size - 1);
        root->right = reBuild(pre, vin, p1 + size + 1, p2, v1 + size + 1, v2);
        return root;
    }

    /**
     * 前序遍历
     * @param pRoot
     * @param ret
     */
    void preOrder(TreeNode *pRoot) {
        if (pRoot) {
            cout << pRoot->val << " ";
            preOrder(pRoot->left);
            preOrder(pRoot->right);
        }
    }

    /**
     * 中序遍历
     * @param pRoot
     * @param ret
     */
    void inOrder(TreeNode *pRoot) {
        if (pRoot) {
            inOrder(pRoot->left);
            cout << pRoot->val << " ";
            inOrder(pRoot->right);
        }
    }
};

int main() {
    vector<int> pre = {1, 2, 3, 4, 5, 6, 7};
    vector<int> vin = {3, 2, 4, 1, 6, 5, 7};
    Solution s;
    TreeNode* ret = s.reConstructBinaryTree(pre, vin);
    s.preOrder(ret);
    cout << endl;
    s.inOrder(ret);
}

