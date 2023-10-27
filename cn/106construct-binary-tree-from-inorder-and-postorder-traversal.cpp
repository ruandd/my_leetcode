//从中序与后序遍历序列构造二叉树
//ruan zheng
//2023-07-10 15:39:05

#include <string>
#include <vector>
#include <iostream>

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

/*
 * 分割数组的时候注意细节，区间开闭需要统一;
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return nullptr;

        /*第一步，取后序数组最后一个元素*/
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // if(postorder.size() == 1) return root;

        /*找到切割点*/
        int deliteIndx;
        for(int i = 0; i < inorder.size(); i++)
            if(inorder[i] == rootValue) {
                deliteIndx = i;
                break;
            }

        /*切割中序数组和后序数组,因为它的默认构造函数就是左闭右开的！！！！！*/
        vector<int> leftInorder(inorder.begin(), inorder.begin() + deliteIndx);
        vector<int> rightInorder(inorder.begin() + deliteIndx + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + deliteIndx);
        vector<int> rightPostorder(postorder.begin() + deliteIndx, postorder.end() - 1);

        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> inorder = vector<int>{9, 3, 15, 20, 7};
    vector<int> postorder = vector<int>{9, 15, 7, 20, 3};
    auto ret = s.buildTree(inorder, postorder);
    return 0;
}