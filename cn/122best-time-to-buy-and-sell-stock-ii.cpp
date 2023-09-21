//买卖股票的最佳时机 II
//ruan zheng
//2023-08-22 16:00:35

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /*
     * 不需要考虑每天的价格和日期;
     * 只要后一天和前一天有价格差，直接买增加利润;
     * 画图的话相当于只选取上坡的路段;
     */
    int maxProfit(vector<int>& prices) {
//        if(prices.size() == 1) return 0;
//        int profit = 0;
//        for(int idx = 0; idx < prices.size() - 1; idx++) {
//            int diff = prices[idx+1] - prices[idx];
//            if(diff > 0) {
//                profit += diff;
//            }
//        }
//        return profit;

        //动态规划解法;
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[len-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}