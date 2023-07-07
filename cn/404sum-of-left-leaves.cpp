//左叶子之和
//ruan zheng
//2023-07-07 15:53:05

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
 * 为什么if判断中的求值，是赋值而不是return root->left->val;
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;

        auto suml = sumOfLeftLeaves(root->left);
        if (root->left && !root->left->left && !root->left->right) { // 左子树就是一个左叶子的情况
            suml = root->left->val;
        }
        auto sumr = sumOfLeftLeaves(root->right);
        int sum = suml + sumr;
        return sum;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}