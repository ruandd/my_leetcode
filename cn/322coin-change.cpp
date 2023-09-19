//零钱兑换
//ruan zheng
//2023-09-19 10:51:20

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT32_MAX/2);
        dp[0] = 0;

        for(int i = 0; i < coins.size(); i++)
            for(int j = coins[i]; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);

        return dp[amount] == INT32_MAX/2 ? -1 : dp[amount];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}