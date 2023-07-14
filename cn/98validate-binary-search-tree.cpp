//验证二叉搜索树
//ruan zheng
//2023-07-14 20:40:39

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
    long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        auto left = isValidBST(root->left);
        //不可以返回，因为要遍历整棵树;
        //比较思路要正确，不能只是单纯比较根节点和左右节点;
        if(root->val > maxVal) {
            maxVal = root->val;
        }
        else return false;

        auto right = isValidBST(root->right);

        return left && right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}