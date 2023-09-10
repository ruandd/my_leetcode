//分割等和子集
//ruan zheng
//2023-09-08 09:34:21

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 有待进一步思考;
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        //dp[i]表示在
        vector<int> dp(10001, 0);
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum %2 == 1) return false; //和不可能有小数;
        int target = sum / 2;

        //01背包
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) {
                //倒序，避免元素重复放入;
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[target] == target) return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}