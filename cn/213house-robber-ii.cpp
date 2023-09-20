//打家劫舍 II
//ruan zheng
//2023-09-20 10:41:29

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int doRob(vector<int>& nums, int start, int end) {
        if(start == end) return nums[start];
        vector<int> dp(nums.size(), 0);
        //这里必须是全部长度，且dp赋值从start开始，而不是0;
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for(int i = start + 2; i <= end; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

        return dp[end];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int result1 = doRob(nums, 0, nums.size() - 2);
        int result2 = doRob(nums, 1, nums.size() - 1);
        return max(result1, result2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}