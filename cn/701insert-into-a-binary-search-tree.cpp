//二叉搜索树中的插入操作
//ruan zheng
//2023-07-16 14:20:30

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
 * 本题利用双指针不好做，碰到极端情况不易处理;
 * 应该利用二叉搜索树的性质去递归搜索即可;
 * 不用搜索整棵树;
 */
class Solution {
public:
    TreeNode* pre = nullptr;
    void insert(TreeNode* cur, int val) {
        if(cur == nullptr) return;

        insert(cur->left, val);

        if(pre != nullptr) {
            if(pre->val < val && val < cur->val) {
                TreeNode* node = new TreeNode(val);
                //插入情况只可能有两种;
                //1. 较小节点的右子树;
                //2. 较大节点的左子树;
                if(pre->right == nullptr) pre->right = node;
                else cur->left = node;
            }
        }
        else {
            //处理极端情况，插入值比所有值都要小;
            TreeNode* node = new TreeNode(val);
            cur->left = node;
        }
        pre = cur;

        insert(cur->right, val);
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        if(root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}