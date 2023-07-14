//最大二叉树
//ruan zheng
//2023-07-14 17:09:54

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
 * 即使采用传递指针，返回值为空的形式来递归;
 * 需要注意的是，这种时候一旦为空，做了终止赋值后，需要return！！！！！！
 * 否则后续会出现访问无效位置的操作;
 * 无论有无返回值，递归都需要return！！！！
 */
class Solution {
public:
    void buildTree(TreeNode* &curr, vector<int>& nums) {
        if(nums.empty()) {
            curr = nullptr;
            //必须return；
            return;
        }

        //寻找最大元素;
        int max_idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > nums[max_idx])
                max_idx = i;
        }

        //建立节点并给元素赋值;
        curr = new TreeNode(nums[max_idx]);

        //只剩一个必须直接返回，否则后续分割会出现无效分割;
//        if(nums.size() == 1) return;

        vector<int> leftValue(nums.begin(),nums.begin() + max_idx);
        vector<int> rightValue(nums.begin() + max_idx + 1, nums.end());
        buildTree(curr->left, leftValue);
        buildTree(curr->right, rightValue);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root;
        buildTree(root, nums);
        return root;
    }

    void traversal(TreeNode* root) {
        if(root == nullptr) return;
        cout << root->val << " ";
        traversal(root->left);
        traversal(root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> nums{3, 2, 1, 6, 0, 5};
    auto root = s.constructMaximumBinaryTree(nums);
//    s.traversal(root);
    return 0;
}