//二叉搜索树的最小绝对差
//ruan zheng
//2023-07-15 10:50:20

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
    //是最大值，不要弄反;
    int result = INT32_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* curr) {
        if(curr == nullptr) return;
        traversal(curr->left);
        if(pre != nullptr) {
            result = min(result, curr->val - pre->val);
        }
        //很重要;
        pre = curr;
        traversal(curr->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}