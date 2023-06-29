//二叉树的前序遍历
//ruan zheng
//2023-06-25 15:44:35

#include <string>
#include <vector>
#include <iostream>
#include <stack>

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

    //建立树和打印
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

    void printTree(TreeNode* root) {
        if(root == nullptr) return;
        cout << root->val;
        printTree(root->left);
        printTree(root->right);
    }

    //先序递归遍历
    void Traversal(TreeNode* curr, vector<int>& ivec) {
        if(curr == nullptr) return;
        ivec.push_back(curr->val);
        Traversal(curr->left, ivec);
        Traversal(curr->right, ivec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        Traversal(root, result);
        return result;
    }

    vector<int> PreOrder(TreeNode* root) {
        vector<int> result;
        //初始化栈st，p是遍历指针;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p || !st.empty()) {
            if(p) {
                result.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
        return result;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    TreeNode* root;
    s.buildTree(root);
    s.printTree(root);

    return 0;
}