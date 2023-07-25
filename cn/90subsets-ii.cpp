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
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        result.push_back(path);
        if(startIndex >= nums.size()) return;

        for(int i = startIndex; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        //必须先排序;
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}