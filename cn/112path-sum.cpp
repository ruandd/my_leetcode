//路径总和
//ruan zheng
//2023-07-09 21:24:49

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
    /*回溯法*/
    void search(TreeNode* root, int targetSum, bool& flag) {
        if(root == nullptr) return;
        targetSum -= root->val;
        if(root->left == nullptr && root->right == nullptr && targetSum == 0) {
            flag = true;
            return;
        }
        if(root->left == nullptr && root->right == nullptr && targetSum != 0) {
            return;
        }

        search(root->left, targetSum, flag);
        search(root->right, targetSum, flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        if(root != nullptr)
            search(root, targetSum, flag);
        return flag;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    deque<int> que{1, 2, -1, -1, 3, -1, -1};
    TreeNode* root;
    s.buildTree(root);
//    s.buildTree2(root, que);
    auto ret = s.hasPathSum(root, 5);
    cout << "ret:" << ret << endl;
    return 0;
}