// NC72 二叉树镜像
// Created by liupan on 2021/1/13.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot) {
            TreeNode* tmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
    void preOrder(TreeNode* root, vector<int> &ret) {
        if (root) {
            ret.push_back(root->val);
            preOrder(root->left, ret);
            preOrder(root->right, ret);
        }
    }
};

int main() {
    Solution s;
    vector<int> ret;
    

}
