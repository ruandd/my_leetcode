//打家劫舍
//ruan zheng
//2023-09-20 10:16:30

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);

        return dp[n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}