//使用最小花费爬楼梯
//ruan zheng
//2023-09-05 11:26:06

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() < 2 ) return 0;
        //dp[i]为爬到i层楼梯的最小花费;
        vector<int> dp(cost.size()+1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[cost.size()];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}