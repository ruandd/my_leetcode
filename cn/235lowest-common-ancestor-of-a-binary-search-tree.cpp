//二叉搜索树的最近公共祖先
//ruan zheng
//2023-07-16 14:02:01

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
 * 关键是找到二叉搜索树的规律;
 * 当节点的值位于两值之间时，就找到了最近根节点;
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == nullptr) return root;

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }

    /*本题就是在一棵树中找到特定节点，故递归必须有返回值，且需要对子树提前返回*/
    TreeNode* search(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root->val >= p->val && root->val <= q->val) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        if(left) return left;
        auto right = lowestCommonAncestor(root->right, p, q);
        if(right) return right;
        return nullptr;
    };

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* m = (p->val > q->val) ? q : p;
        TreeNode* n = (p->val < q->val) ? q : p;
        auto result = search(root, m, n);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}