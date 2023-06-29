//二叉树的层平均值
//ruan zheng
//2023-06-29 10:12:13

#include <string>
#include <vector>
#include <iostream>
#include <queue>

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            long double sum = 0;
            for(int i = 0; i < size; i++) {
                auto p = que.front();
                sum += p->val;
                que.pop();
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}