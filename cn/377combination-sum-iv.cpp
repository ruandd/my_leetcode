//组合总和 Ⅳ
//ruan zheng
//2023-09-12 10:29:08

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int j = 0; j <= target; j++)
            for(int i = 0; i < nums.size(); i++) {
                if(j >= nums[i] && dp[j] < INT32_MAX - dp[j - nums[i]])
                    dp[j] += dp[j - nums[i]];
            }

        return dp[target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}