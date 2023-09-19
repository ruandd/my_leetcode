//爬楼梯
//ruan zheng
//2023-09-05 11:10:06

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        vector<int> dp(n+1);          //dp[0]不使用;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

    }

    int climbStairs1(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for(int j = 0; j <= n; j++)
            for(int i = 1; i < 3; i++)
                if(j >= i) dp[j] += dp[j-i];

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}