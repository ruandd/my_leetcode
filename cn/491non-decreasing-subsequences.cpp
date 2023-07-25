//递增子序列
//ruan zheng
//2023-07-25 11:28:53

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
//    void backtracking1(vector<int>& nums, int startIndex, vector<bool>& used) {
//        if(path.size() >= 2) result.push_back(path);
//        if(startIndex >= nums.size()) return;
//
//        for(int i = startIndex; i < nums.size(); i++) {
//            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
//                continue;
//            if(i > 0 && !path.empty() && nums[i] < path.back())
//                continue;
//            path.push_back(nums[i]);
//            used[i] = true;
//            backtracking(nums, i + 1, used);
//            used[i] = false;
//            path.pop_back();
//        }
//    }

    void backtracking2(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
            // 注意这里不要加return，要取树上的节点
        }
        unordered_set<int> uset; // 使用set对本层元素进行去重
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtracking2(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking2(nums, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}