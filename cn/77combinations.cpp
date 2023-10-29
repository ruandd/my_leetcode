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
    void backtracking(int n, int k， int startIndex) {
        if(path.size() == k) {
            result.push_back(path);
            return;
        }

        /*这是一个组合问题，不可以重复，故i需要递增
        此处引入一个剪枝，path.size()为已经放进去的元素
        k - path.size()为还需要多少个元素
        n - (k - path.size()) + 1为至少从哪个startIndex开始元素才足够*/
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, startIndex + 1);
            path.pop_back();
        }
    };
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, 1, k);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}