//二叉树的中序遍历
//ruan zheng
//2023-06-25 21:14:11

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
    void inOrder(TreeNode* curr, vector<int>& ivec) {
        if(curr == nullptr) return;
        inOrder(curr->left, ivec);
        ivec.push_back(curr->val);
        inOrder(curr->right, ivec);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inOrder(root, result);
        return result;
    }

    vector<int> InOrder(TreeNode* root) {
        vector<int> result;
        //初始化栈st，p是遍历指针;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p || !st.empty()) {
            if(p) {
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();
                st.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> a, b;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        swap(a[b[i]], a[i])
    }
    return 0;
}