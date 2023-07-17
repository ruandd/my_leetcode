//删除二叉搜索树中的节点
//ruan zheng
//2023-07-17 16:25:17

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        //找到元素，做单层逻辑处理;
        if(root->val == key) {
            //删除节点是叶子节点，直接返回空即可;
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            //删除节点是左节点为空;
            if(root->left == nullptr && root->right != nullptr) {
                auto tmp = root->right;
                delete root;
                return tmp;
            }
            //删除节点的右子树为空;
            if(root->left != nullptr && root->right == nullptr) {
                auto tmp = root->left;
                delete root;
                return tmp;
            }
            //左右子树都存在;
            if(root->left != nullptr && root->right != nullptr) {
                TreeNode* cur = root->right;
                while(cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left;
                auto tmp = root->right;
                delete root;
                return tmp;
            }
        }

        //用上一层节点接住返回值;
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}