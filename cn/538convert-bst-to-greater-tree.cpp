//把二叉搜索树转换为累加树
//ruan zheng
//2023-07-17 21:57:29

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
    int sum = 0;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* root) {
        if(root == nullptr) return;
        traversal(root->right);
        //第一个节点特殊处理;
        if(pre == nullptr) {
            sum += root->val;
        }
        else {
            root->val += sum;
            sum = root->val;
        }
        pre = root;
        traversal(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}