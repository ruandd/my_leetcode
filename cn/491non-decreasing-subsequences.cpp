//递增子序列
//ruan zheng
//2023-07-25 11:28:53

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    vector<vector<int>> result;
//    vector<int> path;
//    /*会出现重复的*/
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
//            backtracking1(nums, i + 1, used);
//            used[i] = false;
//            path.pop_back();
//        }
//    };



//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        vector<bool> used(nums.size(), false);
//        backtracking1(nums, 0, used);
//        return result;
//    }


/*正确的思路*/
    vector<vector<int>> result;
    vector<int> path;
    unordered_set<int> set;
    /*本题去重逻辑与之前的那个不同*/
    void backtracking(vector<int>& nums, int startIndex) {
        if(path.size() >= 2) result.push_back(path);
        if(startIndex >= nums.size()) return;

        /*为什么这个去重逻辑不是push和pop，而是每一层重新定义？？？*/
        for(int i = startIndex; i < nums.size(); i++) {
            /*去重逻辑，只要本层使用过，就不再使用*/
            if(set.find(nums[i]) != set.end()) continue;
            if(path.empty()) {
                path.push_back(nums[i]);
            }
            else if(nums[i] >= path.back()) {
                path.push_back(nums[i]);
            }
            else
                continue;
            set.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
            set.erase(nums[i]);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> nums{4, 6, 7, 7};
    s.findSubsequences(nums);
    return 0;
}