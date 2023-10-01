//路径总和
//ruan zheng
//2023-07-09 21:24:49

#include <string>
#include <vector>
#include <iostream>
#include <deque>

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
class Solution {
public:
    //必须按照前序遍历的顺序输入二叉树;
    void buildTree(TreeNode* &curr) {
        int n;
        cin >> n;
        if(n == -1) {
            curr = nullptr;
        }
        else {
            curr = new TreeNode(n);
            curr->val = n;
            buildTree(curr->left);
            buildTree(curr->right);
        }
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root->left == nullptr && root->right == nullptr) {
            return !(targetSum - root->val);
        }
        if(root->left) {
            bool left = hasPathSum(root->left, targetSum - root->val);
            cout << "left:" << left << endl;
        }

        if(root->right) {
            bool right = hasPathSum(root->right, targetSum - root->val);
            cout << "right:" << right << endl;
        }

        return (0 || !right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    deque<int> que{1, 2, -1, -1, 3, -1, -1};
    TreeNode* root;
    s.buildTree(root);
//    s.buildTree2(root, que);
    auto ret = s.hasPathSum(root, 5);
    cout << "ret:" << ret << endl;
    return 0;
}