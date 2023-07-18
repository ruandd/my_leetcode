//组合
//ruan zheng
//2023-07-18 19:22:40

#include <string>
#include <vector>
#include <iostream>


/*
 * pop_back()可以回溯到之前的结果;
 */
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int smartIdx) {
        if(path.size() == k) {
            result.push_back(path);
            return;
        }

        for(int i = smartIdx; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            //对于同一层的横向遍历，弹出上次的选择;
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}