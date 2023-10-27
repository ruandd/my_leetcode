//二叉树的最近公共祖先
//ruan zheng
//2023-07-16 13:35:34

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
class Solution {
public:
    /*必须考虑到p是q的父节点这种情况
     当左子树返回p,右子树返回空的时候，则q必在p的子树中*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == nullptr) return root;

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}