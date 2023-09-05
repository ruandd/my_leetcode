//斐波那契数
//ruan zheng
//2023-09-05 10:49:59

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 * 注意边界条件;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}