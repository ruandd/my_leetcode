//二叉树的后序遍历
//ruan zheng
//2023-06-25 21:07:21

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
/*
 * 二叉树的三种递归遍历没有太多难点;
 * 注意递归条件即可;
 */
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
    void postOrder(TreeNode* curr, vector<int>& ivec) {
        if(curr == nullptr) return;
        postOrder(curr->left, ivec);
        postOrder(curr->right, ivec);
        ivec.push_back(curr->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postOrder(root, result);
        return result;
    }

    //非递归版本;
    vector<int> PostOrder(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* p = root;
        TreeNode* r = nullptr;
        while(p || !st.empty()) {
            if(p) {
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();         //读栈顶节点;
                if(p->right && p->right != r)    //若右子树存在，且未被访问过;
                    p = p->right;
                else {
                    st.pop();
                    result.push_back(p->val);
                    r = p;                        //记录最近访问过的节点
                    p = nullptr;                  //节点访问完后，p置为nullptr
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}