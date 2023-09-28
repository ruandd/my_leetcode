//最长连续递增序列
//ruan zheng
//2023-09-26 13:22:28

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;
            else
                dp[i] = 1;

            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    vector<int> vec{1, 3, 5, 4, 7};
    s.findLengthOfLCIS(vec);
    return 0;
}