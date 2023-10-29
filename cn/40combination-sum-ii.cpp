//组合总和 II
//ruan zheng
//2023-07-19 21:50:09

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if(sum == target) {
            result.push_back(path);
            return;
        }
        /*剪枝*/
        if(sum > target) return;

        /*本题关键是单个数字不可以重复使用但数组中有重复元素
        需要横向剪枝*/
        for(int i = startIndex; i < candidates.size(); i++) {
            if(i != startIndex && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);

            backtracking(candidates, target, i + 1);
            path.pop_back();
            sum -= candidates[i];
        }
    };
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}