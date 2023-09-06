//不同路径 II
//ruan zheng
//2023-09-06 10:09:16

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //处理极端情况;
        if(obstacleGrid[0][0] == 1) return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        //初始化dp数组;
        //在最左侧和最上方的边角情况中，一旦出现障碍物，之后的dp都为0;
        dp[0][0] = 1;
        for(int i = 1; i < m; i++) {
            //有障碍，则dp的值为0，意味不可到达;
            if(obstacleGrid[i][0] == 1)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i-1][0];
        }
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] == 1)
                dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j-1];
        }
        //开始遍历更新dp数组;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }

        return dp[m-1][n-1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}