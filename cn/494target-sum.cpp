//目标和
//ruan zheng
//2023-09-10 10:32:15

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        if(abs(target) > sum) return 0;  //此时没有方案;
        if((target + sum) % 2 == 1) return 0; //此时没有方案;
        int bagSize = (sum + target)/2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++)
            for(int j = bagSize; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];

        return dp[bagSize];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}