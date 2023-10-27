//从前序与中序遍历序列构造二叉树
//ruan zheng
//2023-07-10 17:18:10

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //这一行不能删除;
        if(preorder.empty()) return nullptr;

        //建立当前节点;
        int rootValue = preorder.front();
        TreeNode* root = new TreeNode(rootValue);

        //返回叶子节点;
        if(preorder.size() == 1) return root;

        //找到分割点;
        int delimiterIdx = 0;
        for(; delimiterIdx < inorder.size(); delimiterIdx++)
            if(rootValue == inorder[delimiterIdx])
                break;

        //分割两个遍历数组，左闭右开模式;
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIdx);
        vector<int> rightInorder(inorder.begin() + delimiterIdx + 1, inorder.end());

        int sz = leftInorder.size();
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + sz);
        vector<int> rightPreorder(preorder.begin() + 1 + sz, preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int countTree(TreeNode* root, int& result) {
    if(root == nullptr) return 0;
    if(root != nullptr) return 1;

    int left = countTree(root->left, result);
    int right = countTree(root->right, result);
    if(left == right) result++;

    return 1;
}

int main(){
    class Solution s;

    return 0;
}