//组合总和 III
//ruan zheng
//2023-07-18 20:01:57

#include <string>
#include <vector>
#include <iostream>
#include<numeric>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int n, int smartIdx) {
        if(path.size() == k && accumulate(path.begin(), path.end(), 0) == n) {
            result.push_back(path);
            return;
        }

        for(int i = smartIdx; i <= 9; i++) {
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}