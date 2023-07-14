//合并二叉树
//ruan zheng
//2023-07-14 19:01:20

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
    TreeNode* buildTree(deque<int>& que) {
        if(que.front() == -1) {
            que.pop_front();
            return nullptr;
        }
        int elem = que.front();
        que.pop_front();
        TreeNode* root = new TreeNode(elem);
        root->left = buildTree(que);
        root->right = buildTree(que);
        return root;
    }

    void traversal(TreeNode* root) {
        if(root == nullptr) return;
        cout << root->val << " ";
        traversal(root->left);
        traversal(root->right);
    }


    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return nullptr;
        if(root1 != nullptr && root2 == nullptr) return root1;
        if(root1 == nullptr && root2 != nullptr) return root2;

        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    deque<int> que1{1, 3, 5, -1, -1, -1, 2, -1, -1};
    deque<int> que2{2, 1, -1, 4, -1, -1, 3, -1, 7, -1, -1};
    auto root1 = s.buildTree(que1);
    auto root2 = s.buildTree(que2);
    s.traversal(root1);
    cout << endl;
    s.traversal(root2);
    auto root = s.mergeTrees(root1, root2);
    cout << endl;
    s.traversal(root);
    return 0;
}