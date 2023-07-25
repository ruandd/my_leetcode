//子集
//ruan zheng
//2023-07-25 09:47:04

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 * 子集问题需要收集除根节点外的所有节点;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        //放在这里减少操作;
        result.push_back(path);
        if(startIndex >= nums.size()) return;

        for(int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);

            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
//        //添加空子集;
//        result.push_back(path);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> nums{1, 2, 3};
    auto result = s.subsets(nums);
    cout << "hello";

    return 0;
}