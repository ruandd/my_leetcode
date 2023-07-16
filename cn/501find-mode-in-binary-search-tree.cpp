//二叉搜索树中的众数
//ruan zheng
//2023-07-15 14:28:12

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
    vector<int> result;
    int cnt = 0;
    int maxCnt = 0;
    TreeNode* pre = nullptr;
    void searchBST(TreeNode* cur) {
        if(cur == nullptr) return;
        //左;
        searchBST(cur->left);

        if(pre == nullptr) {
            cnt = 1; //第一个节点;
        }
        else if(pre->val == cur->val) {
            cnt++;  //相等则递增;
        }
        else {
            cnt = 1;
        }
        //总是忘记更新节点;
        pre = cur;

        if(cnt == maxCnt) {
            result.push_back(cur->val);
        }

        if(cnt > maxCnt) {
            //大于则清空之前的;
            maxCnt = cnt;
            result.clear();
            result.push_back(cur->val);
        }

        //右；
        searchBST(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        searchBST(root);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}