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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty())  return nullptr;

        //建立当前节点;
        int rootValue = postorder.back();
        TreeNode* root = new TreeNode(rootValue);

        //返回叶子节点;
        if(postorder.size() == 1) return root;

        //寻找中序遍历切割点;
        int delimiterIdx;
        for(delimiterIdx = 0; delimiterIdx < inorder.size(); delimiterIdx++)
            if(inorder[delimiterIdx] == postorder.back())
                break;

        //分割中序数组,左闭右开;
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIdx);
        vector<int> rightInorder(inorder.begin() + delimiterIdx + 1, inorder.end());

        //分割后序数组,左闭右开;
        int sz = leftInorder.size();
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + sz);
        vector<int> rightPostorder(postorder.begin() + sz , postorder.end() - 1);

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
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