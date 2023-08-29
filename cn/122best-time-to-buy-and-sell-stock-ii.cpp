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
        if(prices.size() == 1) return 0;
        int profit = 0;
        for(int idx = 0; idx < prices.size() - 1; idx++) {
            int diff = prices[idx+1] - prices[idx];
            if(diff > 0) {
                profit += diff;
            }
        }
        return profit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}