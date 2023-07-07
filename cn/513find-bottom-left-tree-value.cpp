//找树左下角的值
//ruan zheng
//2023-07-07 21:50:37

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
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* root, int depth) {
        if(root->left == nullptr && root->right == nullptr) {
            if(depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
                return;
            }
        }
        if(root->left) traversal(root->left, depth + 1);
        if(root->right) traversal(root->right, depth + 1);
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}