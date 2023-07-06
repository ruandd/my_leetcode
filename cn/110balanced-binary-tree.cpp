//平衡二叉树
//ruan zheng
//2023-07-06 16:22:15

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
 * 因为迭代返回有两种情况;
 * 所以当一边已经不是平衡二叉树的时候，需要判断并提前返回值;
 */
class Solution {
public:
    int getHeight(TreeNode* curr) {
        if(curr == nullptr) return 0;
        int lh = getHeight(curr->left);
        if(lh == -1) return -1;
        int rh = getHeight(curr->right);
        if(rh == -1) return -1;
        if(abs(lh - rh) > 1) return -1;
        else {
            return max(lh, rh) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}