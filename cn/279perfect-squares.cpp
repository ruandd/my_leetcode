//完全平方数
//ruan zheng
//2023-09-19 12:33:13

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(int(sqrt(n)), 0);
        for(int i = 0; i < nums.size(); i++)
            nums[i] = (i+1)*(i+1);

        //防止溢出，所以/2;
        //必须是n + 1;
        vector<int> dp(n + 1, INT32_MAX/2);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++)
            for(int j = nums[i]; j <= n; j++)
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);

        return dp[n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.numSquares(12);
    return 0;
}