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
            TreeNode *tmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }

    /**
     * 先序输出
     * @param root
     */
    void preOrder(TreeNode *root) {
        if (root) {
            cout << root->val << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    /**
     * 构建二叉树
     * @param a
     * @param i
     * @return
     */
    TreeNode *createTree(vector<int> &a, int &i) {
        TreeNode *root = nullptr;
        if (i < a.size()) {
            root = new TreeNode(a[i]);
            root->left = createTree(a, ++i);
            root->right = createTree(a, ++i);
        }
        return root;
    }
};

int main() {
    Solution s;
//    TreeNode* pRoot = new TreeNode(8);
//    pRoot->left = new TreeNode(6);
//    pRoot->right = new TreeNode(10);
//    pRoot->left->left = new TreeNode(5);
//    pRoot->left->right = new TreeNode(7);
//    pRoot->right->left = new TreeNode(9);
//    pRoot->right->right = new TreeNode(11);
    vector<int> a = {8, 6, 10, 5, 7, 9, 11};
    int i = 0;
    TreeNode *pRoot = s.createTree(a, i);
    s.preOrder(pRoot);
    cout << endl;
    s.Mirror(pRoot);
    s.preOrder(pRoot);
}
