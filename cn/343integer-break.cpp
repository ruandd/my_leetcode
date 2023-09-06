//整数拆分
//ruan zheng
//2023-09-06 11:00:37

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        //初始化dp数组;
        dp[1] = 1, dp[2] = 1;
        //特殊情况处理;
        if(n < 3) return dp[n];
        for(int i = 3; i < n+1; i++) {
            //拆分成两个数字;
            int product1 = (i/2) * (i - i/2);
            //拆分成多个数字;
            int product2 = INT32_MIN;
            for(int j = 1; j < i - 1; j++) {
                int tmp = j * dp[i-j];
                if(tmp > product2)
                    product2 = tmp;
            }
            dp[i] = max(product1, product2);
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.integerBreak(10);
    return 0;
}