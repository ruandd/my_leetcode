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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;
        //左;
        auto left = lowestCommonAncestor(root->left, p, q);
        //右;
        auto right = lowestCommonAncestor(root->right, p, q);

        //处理单层递归逻辑;
        if(left && right) return root;
        if(left && !right) return left;
        if(!left && right) return right;
        //必须有返回值;
        return nullptr;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}