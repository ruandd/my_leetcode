//买卖股票的最佳时机
//ruan zheng
//2023-09-21 10:22:56

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        //dp[i][0]持有股票所能获得的最多现金，dp[i][1]不持有股票能获得的最多现金;
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++) {
            //不太理解;
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
        }
        return dp[len-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}