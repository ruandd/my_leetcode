//在每个树行中找最大值
//ruan zheng
//2023-06-29 10:40:30

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> result;
        if(root != nullptr) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                auto p = que.front();
                que.pop();
                vec.push_back(p->val);
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
            }
            result.push_back(*max_element(vec.begin(), vec.end()));
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}