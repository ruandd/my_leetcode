//路径总和 II
//ruan zheng
//2023-10-24 12:49:40

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
    /*使用回溯的时候要注意层次，不要上一层操作下一层*/
    vector<vector<int>> result;
    void search(TreeNode* root, int targetSum, vector<int>& path) {
        if(root->left == nullptr && root->right == nullptr && targetSum == 0) {
            result.push_back(path);
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            return;
        }
        if(root->left) {
            path.push_back(root->left->val);
            search(root->left, targetSum - root->left->val, path);
            path.pop_back();
        }
        if(root->right) {
            path.push_back(root->right->val);
            search(root->right, targetSum - root->right->val, path);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        if(root == nullptr) return result;
        path.push_back(root->val);
        search(root, targetSum - root->val, path);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}