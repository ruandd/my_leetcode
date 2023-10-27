//验证二叉搜索树
//ruan zheng
//2023-07-14 20:40:39

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
    bool flag = true;
    /*pre指针必须是引用*/
    void travel(TreeNode* root, TreeNode*& pre) {
        if(root == nullptr) return;

        travel(root->left, pre);
        if(pre == nullptr) {
            pre = root;
        }
        else {
            if(root->val <= pre->val) flag = false
            pre = root;
        }
        travel(root->right, pre);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        travel(root, pre);
        return flag;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    int a = I
    return 0;
}