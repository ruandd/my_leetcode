//不同路径
//ruan zheng
//2023-09-06 09:45:14

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        //dp[i][j]代表到[i, j]位置有多少种不同的路径;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                //初始化值需要注意，应该为1才对;
                if(i == 0 && j == 0) dp[0][0] = 1;
                else if(0 < i && i <= m-1 && j == 0) dp[i][j] = dp[i-1][0];
                else if(i == 0 && 0 < j && j <= n-1) dp[i][j] = dp[i][j-1];
                else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;
    auto ret = s.uniquePaths(3, 7);
    return 0;
}