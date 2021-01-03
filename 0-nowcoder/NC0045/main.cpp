// NC0045 实现二叉树先序，中序和后序遍历
// Created by liupan on 2021/1/3.
//

#include <iostream>
#include <vector>
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
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<int> pre, in, post;
        preOrder(root, pre);
        inOrder(root, in);
        postOrder(root, post);
        return vector<vector<int>>({pre, in, post});
    }

private:
    void preOrder(TreeNode* root, vector<int> &ret) {
        if (root) {
            ret.push_back(root->val);
            preOrder(root->left, ret);
            preOrder(root->right, ret);
        }
    }
    void inOrder(TreeNode* root, vector<int> &ret) {
        if (root) {
            inOrder(root->left, ret);
            ret.push_back(root->val);
            inOrder(root->right, ret);
        }
    }
    void postOrder(TreeNode* root, vector<int> &ret) {
        if (root) {
            postOrder(root->left, ret);
            postOrder(root->right, ret);
            ret.push_back(root->val);
        }
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode;
    root->val = 1;
    TreeNode* left = new TreeNode;
    left->val = 2;
    TreeNode* right = new TreeNode;
    right->val = 3;
    root->left = left;
    root->right = right;
    auto ret = s.threeOrders(root);
    for_each(ret.begin(), ret.end(), [](vector<int> item) {
        for_each(item.begin(), item.end(), [](int val) {
            cout << val << " ";
        });
        cout << "\n";
    });
}

