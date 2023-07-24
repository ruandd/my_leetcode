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
    int sum = 0;
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, vector<bool>& used, int tartget, int smartIdx) {
        if(sum > tartget) return;
        if(sum == tartget) result.push_back(path);

        for(int i = smartIdx; i < candidates.size(); i++) {
            //如果是同一层的相同元素，则剪枝;
            if(i > 0 && used[i-1] == false && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, used, tartget, i + 1);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        //不可以忘了排序;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, used,target, 0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}