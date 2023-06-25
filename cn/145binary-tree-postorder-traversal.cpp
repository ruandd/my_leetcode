//二叉树的后序遍历
//ruan zheng
//2023-06-25 21:07:21

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 * 二叉树的三种递归遍历没有太多难点;
 * 注意递归条件即可;
 */

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
    void postOrder(TreeNode* curr, vector<int>& ivec) {
        if(curr == nullptr) return;
        postOrder(curr->left, ivec);
        postOrder(curr->right, ivec);
        ivec.push_back(curr->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrder(root, result);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}