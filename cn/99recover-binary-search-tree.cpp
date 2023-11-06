//恢复二叉搜索树
//ruan zheng
//2023-11-05 15:11:44

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
class Solution {
public:
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    TreeNode* pre = nullptr;
    void travel(TreeNode* root) {
        if(root == nullptr) return;

        travel(root->left);
        if(pre != nullptr && root->val < pre->val) {
            if(node1 == nullptr) node1 = pre;
            node2 = root;
        }
        pre = root;
        travel(root->right);
    }
    void recoverTree(TreeNode* root) {
        travel(root);
        swap(node1->val, node2->val);
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}