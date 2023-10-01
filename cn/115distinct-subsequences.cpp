//不同的子序列
//ruan zheng
//2023-10-01 11:21:55

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(s.size() + 1, vector<unsigned long long>(t.size() + 1, 0));
        for(int i = 0; i <= s.size(); i++) dp[i][0] = 1;
        for(int i = 1; i <= s.size(); i++)
            for(int j = 1; j <= t.size(); j++) {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }

        return dp[s.size()][t.size()] % static_cast<unsigned long long>((10e9 + 7));
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main(){
    class Solution s;

    return 0;
}