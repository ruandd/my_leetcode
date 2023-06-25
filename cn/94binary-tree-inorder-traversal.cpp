//二叉树的中序遍历
//ruan zheng
//2023-06-25 21:14:11

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
    void inOrder(TreeNode* curr, vector<int>& ivec) {
        if(curr == nullptr) return;
        inOrder(curr->left, ivec);
        ivec.push_back(curr->val);
        inOrder(curr->right, ivec);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inOrder(root, result);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}