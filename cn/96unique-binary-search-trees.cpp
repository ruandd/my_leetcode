//不同的二叉搜索树
//ruan zheng
//2023-09-07 10:15:00

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
        //特殊情况，直接返回;
        if(n < 3) return n;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i < n+1; i++) {
            dp[i] = 2 * dp[i-1];
            for(int j = 1; j < i-1; j++) {
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}