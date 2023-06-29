//翻转二叉树
//ruan zheng
//2023-06-29 13:29:34

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
    void Invert(TreeNode* curr) {
        if(curr == nullptr) return;
        swap(curr->left, curr->right);
        Invert(curr->left);
        Invert(curr->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        Invert(root);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}