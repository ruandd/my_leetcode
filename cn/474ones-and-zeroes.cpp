//一和零
//ruan zheng
//2023-09-11 10:21:57

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string& str : strs) {
            int oneNum = 0, zeroNum = 0;
            for(char& c : str) {
                if(c == '0') zeroNum++;
                else oneNum++;
            }

            for(int i = m; i >= zeroNum; i--)
                for(int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
        }
        return dp[m][n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}