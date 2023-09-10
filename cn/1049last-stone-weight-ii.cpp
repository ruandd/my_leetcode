//最后一块石头的重量 II
//ruan zheng
//2023-09-08 10:53:34

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        //dp[i]表示在
        vector<int> dp(1501, 0);
        for(int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum / 2;

        //01背包
        for(int i = 0; i < stones.size(); i++) {
            for(int j = target; j >= stones[i]; j--) {
                //倒序，避免元素重复放入;
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return (sum - dp[target]) - dp[target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}