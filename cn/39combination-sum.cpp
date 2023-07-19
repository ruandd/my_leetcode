//组合总和
//ruan zheng
//2023-07-19 17:23:22

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sum = 0;
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int smartIdx) {
        //必须添加这一行，否则会无限递归;
        if(sum > target) return;
        if(sum == target) {
            result.push_back(path);
            return;
        }

        for(int i = smartIdx; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> vec{2, 3, 6, 7};
    s.combinationSum(vec, 7);
    return 0;
}