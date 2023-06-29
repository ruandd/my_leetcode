//二叉树的右视图
//ruan zheng
//2023-06-29 10:09:11

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> result;
        //注意判断非空，节点空和队列非空是两码事;
        if(root != nullptr) que.push(root);
        while(!que.empty()) {
            //size必须使用固定值;
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                auto tmp = que.front();
                vec.push_back(tmp->val);
                que.pop();
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }
            result.push_back(vec.back());
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}