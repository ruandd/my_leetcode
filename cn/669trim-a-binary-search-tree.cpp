//修剪二叉搜索树
//ruan zheng
//2023-07-17 16:47:02

#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return root;
        /*不能保证子树都是符和条件的，需要再次递归*/
        if(root->val < low) {
            return trimBST(root->right, low, high);
        }
        if(root->val > high) {
            return trimBST(root->left, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    deque<int> que{4, 2, 1, -1, -1, 3, -1, -1, 5, -1, -1};
    auto root = s.buildTree(que);
    s.traversal(root);
    auto result = s.trimBST(root, 2, 4);
    cout << "hee";
    return 0;
}