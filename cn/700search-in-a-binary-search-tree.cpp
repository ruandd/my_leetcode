//二叉搜索树中的搜索
//ruan zheng
//2023-07-14 19:51:58

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
    TreeNode* searchBST(TreeNode* root, int val) {
//        while(root != nullptr) {
//            if(root->val == val) return root;
//            else if(root->val > val) root = root->left;
//            else root = root->right;
//        }
//        return nullptr;

        //递归方法;
        if(root == nullptr) return nullptr;
        if(root->val == val) return root;
        if(val > root->val) {
            auto leftRet = searchBST(root->right, val);
            if(leftRet != nullptr) return leftRet;
        }
        if(val < root->val) {
            auto rightRet = searchBST(root->left, val);
            if(rightRet != nullptr) return rightRet;
        }
        return nullptr;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}