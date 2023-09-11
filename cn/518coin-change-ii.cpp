//零钱兑换 II
//ruan zheng
//2023-09-11 11:20:00

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
 * 1.本题是一道完全背包问题，因为硬币数目是无限的，所以要注意遍历顺序，
 * 此时先遍历物品再遍历容量，并且容量顺序遍历;
 * 2. 求解的是有多少种组合数，故需要注意递推公式;
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        //遍历;
        for(int i = 0; i < coins.size(); i++)
            for(int j = coins[i]; j <= amount; j++)
                dp[j] += dp[j - coins[i]];

        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}