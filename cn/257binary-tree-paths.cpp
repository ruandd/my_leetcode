//二叉树的所有路径
//ruan zheng
//2023-07-06 22:17:05

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
 * 第一遍，看了代码，然后自己写的;
 */
class Solution {
public:
    /*使用回溯*/
    vector<string> result;
    void search(TreeNode* root, string str) {
        if(root->left != nullptr) {
            search(root->left, str + string("->") + to_string(root->left->val));
        }
        if(root->right != nullptr) {
            search(root->right, str + string("->") + to_string(root->right->val));
        }
        if(root->left == nullptr && root->right == nullptr)
            result.push_back(str);
        return;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        if(root) str = to_string(root->val);
        search(root, str);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}