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
    void searchTrace(TreeNode* curr, vector<int>& path, vector<string>& result) {
        path.push_back(curr->val);
        if(curr->left == nullptr && curr->right == nullptr) {
            string tmp;
            for(int i = 0; i < path.size() - 1; i++) {
                tmp += to_string(path[i]);
                tmp += "->";
            }
            tmp += to_string(path[path.size()-1]);
            result.push_back(tmp);
            return;
        }
        if(curr->left) {
            searchTrace(curr->left, path, result);
            path.pop_back();
        }
        if(curr->right) {
            searchTrace(curr->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        searchTrace(root, path, result);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}