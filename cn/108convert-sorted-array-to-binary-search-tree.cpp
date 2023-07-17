//将有序数组转换为二叉搜索树
//ruan zheng
//2023-07-17 21:09:26

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
  * 这里不要用begin和end迭代器来分割，不好处理！！！！！！;
  * 不如用数组下标;
  */
class Solution {
public:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid-1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto ret = traversal(nums, 0, nums.size() - 1);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> vec{1, 2, 3, 4, 5};
    vector<int> v1{vec.begin(), vec.begin()+1};
    vector<int> v2{vec.begin()+ 2, vec.end()};
    cout << "he";
    return 0;
}