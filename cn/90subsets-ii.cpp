//子集 II
//ruan zheng
//2023-07-25 10:25:02

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        if(startIndex >= nums.size()) return;

        for(int i = startIndex; i < nums.size(); i++) {
            /*在同一树的层上剪枝*/
            if(i != startIndex && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*需要且可以排序*/
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}