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
        int lower = min(p->val, q->val);
        int higher = max(p->val, q->val);
        while(lower > root->val || higher < root->val) {
            if(root->val > higher) root = root->left;
            else if(root->val < lower) root = root->right;
            else {
                break;
            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}