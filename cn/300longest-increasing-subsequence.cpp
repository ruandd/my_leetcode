//最长递增子序列
//ruan zheng
//2023-09-26 13:15:02

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*值都初始化为1，代表以i为末尾的递增子序列*/
        vector<int> dp(nums.size(), 1);
        int result = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            /*实际每次内部循环都只可能改变dp[i]*/
            for(int j = 0; j < i; j++)
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}