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
    /*判断叶子节点很简单，关键如何判断该叶子节点是左叶子呢？
    通过引入一个bool值，只在左递归的时候为true即可*/
    void sumLTree(TreeNode* root, int& sum, bool flag) {
        if(root == nullptr) return;
        if(!root->left && !root->right && flag) sum += root->val;
        sumLTree(root->left, sum, true);
        sumLTree(root->right, sum, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumLTree(root, sum, false);
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    return 0;
}