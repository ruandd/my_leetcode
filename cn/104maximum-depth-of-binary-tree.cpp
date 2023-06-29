//二叉树的最大深度
//ruan zheng
//2023-06-29 12:19:04

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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++;
            for(int i = 0; i < size; i++) {
                auto p = que.front();
                que.pop();
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
            }
        }
        return depth;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}