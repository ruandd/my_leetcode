//二叉树的最小深度
//ruan zheng
//2023-06-29 12:31:16

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
 * 最小深度关键是不是深度小就可以;
 * 因为如果有一边子树为空，则这个节点不是叶子节点;
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
//        //depth记录当前队列中节点的层数;
//        int depth = 0;
//        queue<TreeNode*> que;
//        if(root != nullptr) que.push(root);
//        while(!que.empty()) {
//            int size = que.size();
//            depth++;
//            for(int i = 0; i < size; i++) {
//                auto p = que.front();
//                que.pop();
//                //如果遍历发现叶子节点，直接返回层数即可;
//                if(!p->left && !p->right) return depth;
//                if(p->left) que.push(p->left);
//                if(p->right) que.push(p->right);
//            }
//        }
//        return depth;
        if(root == nullptr) return 0;
        auto ld = minDepth(root->left);
        auto rd = minDepth(root->right);
        if(root->left == nullptr && root->right != nullptr) {
            return 1 + rd;
        }
        if(root->left != nullptr && root->right == nullptr) {
            return 1 + ld;
        }
        int result = 1 + min(ld, rd);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}