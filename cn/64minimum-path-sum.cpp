//最小路径和
//ruan zheng
//2023-11-24 15:24:03

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0, sum = 0; i < m; i++) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        for(int j = 0, sum = 0; j < n; j++) {
            sum += grid[0][j];
            dp[0][j] = sum;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}