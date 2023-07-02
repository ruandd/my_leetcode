//对称二叉树
//ruan zheng
//2023-06-29 19:59:07

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
 * 递归问题，关键是确定递归顺序;
 * 这道题是后序遍历，因为对于一棵树确实是否是对称树，先要确定两棵子树是否是对称的;
 * 对于递归函数有无返回值的，递归写起来也有区别。
 */
class Solution {
public:
    bool symmetrec(TreeNode* left, TreeNode* right) {
        if(left && !right) return false;
        else if(!left && right) return false;
        else if(!left && !right) return true;
        else if(left->val != right->val) return false;
        bool outside = symmetrec(left->left, right->right);
        bool inside = symmetrec(left->right, right->left);
        return outside && inside;
    }

    bool isSymmetric(TreeNode* root) {
        return symmetrec(root->left, root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}